#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QSqlError>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QVBoxLayout>
#include "Mailing.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

// Constructeur de MainWindow
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialisation du port série
    setupSerialConnection();
}

// Destructeur de MainWindow
MainWindow::~MainWindow()
{
    delete ui;

    // Fermeture du port série lors de la destruction
    if (serialPort && serialPort->isOpen()) {
        serialPort->close();
    }
}

// 📌 Configuration du port série pour communiquer avec Arduino
void MainWindow::setupSerialConnection()
{
    serialPort = new QSerialPort(this);

    // Définir explicitement le port COM6
    serialPort->setPortName("COM6");

    // Configurer les paramètres de communication
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    // Ouvrir la connexion
    if (serialPort->open(QIODevice::ReadOnly)) {
        qDebug() << "Connexion série établie avec succès sur COM6.";
        connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readArduinoData);
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter au port série !");
    }
}

// 📌 Lecture des données envoyées par Arduino
void MainWindow::readArduinoData()
{
    if (serialPort->canReadLine()) {
        QByteArray data = serialPort->readLine().trimmed();
        QString message = QString::fromUtf8(data);

        qDebug() << "Message reçu depuis Arduino :" << message;

        // Vérifier si le message contient le temps
        if (message.contains(":")) { // Format attendu : "MM:SS"
            int row = ui->tableWidgetClient->currentRow();
            if (row < 0) {
                QMessageBox::warning(this, "Attention", "Aucun client sélectionné dans le tableau !");
                return;
            }

            int idClient = ui->tableWidgetClient->item(row, 0)->text().toInt();
            qDebug() << "ID sélectionné :" << idClient;

            // Mise à jour SQL
            QSqlQuery query;
            query.prepare("UPDATE CLIENT SET etat_consultation = 'effectuée', duree_consultation = :duree WHERE ID = :id");
            query.bindValue(":duree", message); // Durée reçue
            query.bindValue(":id", idClient);

            if (!query.exec()) {
                qDebug() << "Erreur SQL :" << query.lastError().text();
            } else {
                qDebug() << "Mise à jour réussie pour le client avec ID :" << idClient;

                // Mise à jour dans le tableau Qt
                ui->tableWidgetClient->setItem(row, 6, new QTableWidgetItem("Effectuée"));
                ui->tableWidgetClient->setItem(row, 7, new QTableWidgetItem(message));
                qDebug() << "Tableau mis à jour : Etat = 'Effectuée', Durée =" << message;
            }
        }
    }
}

// 📌 Ajout d'un client
void MainWindow::on_pushButton_9_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_4->text();
    QString email = ui->lineEdit_email->text();
    QString telephone = ui->lineEdit_telephone->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString secteur = ui->lineEdit_secteur->text();

    QRegularExpression emailRegex("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    QRegularExpression phoneRegex("^[0-9]{8,15}$");

    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Adresse email invalide !");
        return;
    }

    if (!phoneRegex.match(telephone).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Numéro de téléphone invalide !");
        return;
    }

    client newClient(id, nom, email, telephone, adresse, secteur);
    if (newClient.ajouter()) {
        QMessageBox::information(this, "Succès", "Ajout effectué !");
        qDebug() << "Ajout réussi dans la base de données.";
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client.");
        qDebug() << "Erreur SQL : " << QSqlDatabase::database().lastError().text();
        return;
    }

    int rowCount = ui->tableWidgetClient->rowCount();
    ui->tableWidgetClient->insertRow(rowCount);
    ui->tableWidgetClient->setItem(rowCount, 0, new QTableWidgetItem(QString::number(id)));
    ui->tableWidgetClient->setItem(rowCount, 1, new QTableWidgetItem(nom));
    ui->tableWidgetClient->setItem(rowCount, 2, new QTableWidgetItem(email));
    ui->tableWidgetClient->setItem(rowCount, 3, new QTableWidgetItem(telephone));
    ui->tableWidgetClient->setItem(rowCount, 4, new QTableWidgetItem(adresse));
    ui->tableWidgetClient->setItem(rowCount, 5, new QTableWidgetItem(secteur));
}

// 📌 Suppression d'un client
void MainWindow::on_pushButton_11_clicked()
{
    QModelIndex index = ui->tableWidgetClient->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un client à supprimer !");
        return;
    }

    int row = index.row();
    int id = ui->tableWidgetClient->item(row, 0)->text().toInt();

    if (QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir supprimer ce client ?") == QMessageBox::Yes) {
        client clientToDelete;
        if (clientToDelete.supprimer(id)) {
            QMessageBox::information(this, "Succès", "Client supprimé !");
            ui->tableWidgetClient->removeRow(row);
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
        }
    }
}

void MainWindow::on_pushButton_trier_clicked()
{
    QString filtre = ui->lineEdit_2->text();
    if (filtre.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir une lettre ou un mot pour filtrer !");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT ID, NOM, EMAIL, TELEPHONE, ADRESSE, SECTEUR "
                  "FROM CLIENT WHERE NOM LIKE :filtre ORDER BY NOM ASC");
    query.bindValue(":filtre", filtre + "%");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'afficher les données triées : " + query.lastError().text());
        return;
    }

    ui->tableWidgetClient->setRowCount(0);  // Efface les anciennes lignes
    int row = 0;
    while (query.next()) {
        ui->tableWidgetClient->insertRow(row);
        for (int col = 0; col < 6; ++col) {
            ui->tableWidgetClient->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }
}


// 📌 Export PDF
void MainWindow::on_pushButton_pdf_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer le fichier PDF", "", "PDF Files (*.pdf)");

    if (!fileName.isEmpty()) {
        client c;
        if (!c.exporterPDF(fileName, ui->tableWidgetClient)) {  // ✅ On passe le tableau ici
            QMessageBox::critical(this, "Erreur", "Impossible de générer le fichier PDF.");
        } else {
            QMessageBox::information(this, "Succès", "Le fichier PDF a été généré avec succès.");
        }
    } else {
        QMessageBox::warning(this, "Attention", "Aucun fichier sélectionné !");
    }
}


void MainWindow::on_lineEdit_recherche_2_clicked()
{
    QString adresse = ui->lineEdit->text(); // Récupérer l'adresse saisie dans le champ texte

    if (adresse.isEmpty()) { // Vérifie si l'utilisateur n'a rien entré
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une adresse pour effectuer une recherche !");
        return;
    }

    client c;
    QSqlQueryModel* model = c.rechercherParAdresse(adresse);

    if (model->rowCount() > 0) {
        ui->tableWidgetClient->setRowCount(0); // Réinitialise le tableau
        ui->tableWidgetClient->setColumnCount(5); // Définit le nombre de colonnes
        ui->tableWidgetClient->setHorizontalHeaderLabels(
            QStringList() << "ID" << "Nom" << "Email" << "Téléphone" << "Adresse"
            );

        // Remplir le tableau avec les résultats
        for (int i = 0; i < model->rowCount(); i++) {
            ui->tableWidgetClient->insertRow(i); // Insère une nouvelle ligne

            for (int j = 0; j < 5; j++) { // Remplit les colonnes de la ligne
                QString value = model->data(model->index(i, j)).toString();
                ui->tableWidgetClient->setItem(i, j, new QTableWidgetItem(value));
            }
        }
    } else {
        QMessageBox::information(this, "Aucun résultat", "Aucun client trouvé pour cette adresse.");
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    int row = ui->tableWidgetClient->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner une ligne pour modifier !");
        return;
    }

    int idClient = ui->tableWidgetClient->item(row, 0)->text().toInt();
    QString nom = ui->lineEdit_4->text();
    QString email = ui->lineEdit_email->text();
    QString telephone = ui->lineEdit_telephone->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString secteur = ui->lineEdit_secteur->text();

    if (idClient <= 0) {
        QMessageBox::critical(this, "Erreur", "ID client invalide !");
        return;
    }

    client c;
    if (c.modifier(idClient, nom, email, telephone, adresse, secteur)) {
        QMessageBox::information(this, "Succès", "Modification réussie !");
        ui->tableWidgetClient->setItem(row, 1, new QTableWidgetItem(nom));
        ui->tableWidgetClient->setItem(row, 2, new QTableWidgetItem(email));
        ui->tableWidgetClient->setItem(row, 3, new QTableWidgetItem(telephone));
        ui->tableWidgetClient->setItem(row, 4, new QTableWidgetItem(adresse));
        ui->tableWidgetClient->setItem(row, 5, new QTableWidgetItem(secteur));
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de modifier les données.");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    client c;
    QMap<QString, int> stats = c.getStatistiquesParSecteur();

    // Vérification si les statistiques sont vides
    if (stats.isEmpty()) {
        QMessageBox::warning(this, "Aucune donnée", "Aucune donnée de secteur trouvée.");
        return; // Si aucune donnée, on arrête l'exécution de la fonction
    }

    // Créer une série pour le graphique
    QPieSeries* series = new QPieSeries();

    // Ajouter les secteurs et les valeurs à la série
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        series->append(it.key(), it.value());
    }

    // Ajouter des couleurs pour chaque segment du graphique
    QList<QColor> colors = {Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::cyan, Qt::magenta};
    int colorIndex = 0;
    for (QPieSlice* slice : series->slices()) {
        slice->setBrush(colors[colorIndex % colors.size()]);
        colorIndex++;
    }

    // Créer le graphique
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques par secteur d'activité");
    chart->legend()->show();

    // Afficher le graphique dans une boîte de dialogue
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Créer la boîte de dialogue pour afficher le graphique
    QDialog dialog(this);
    QVBoxLayout* layout = new QVBoxLayout(&dialog);
    layout->addWidget(chartView);
    dialog.setLayout(layout);
    dialog.setWindowTitle("Statistiques");
    dialog.exec();
}

void MainWindow::on_pushButton_mailling_clicked()
{
    QString destinataire = ui->lineEdit_9->text(); // Récupérer l'adresse e-mail
    QString sujet = ui->lineEdit_10->text();       // Récupérer le sujet
    QString contenu = ui->textEdit_11->toPlainText(); // Récupérer le contenu du message

    // Vérification de l'adresse e-mail avec une expression régulière
    QRegularExpression emailRegex("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(destinataire).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Adresse e-mail invalide !");
        return;
    }

    // Envoi de l'e-mail
    Mailing mail;
    if (!mail.envoyerEmail(destinataire, sujet, contenu)) {
        QMessageBox::critical(this, "Erreur", "Échec de l'envoi de l'e-mail.");
    } else {
        QMessageBox::information(this, "Succès", "E-mail envoyé avec succès.");
    }
}
