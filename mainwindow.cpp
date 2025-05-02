#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ressource.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>
#include <QStringListModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTextDocument>
#include <QtCore/QCoreApplication>
#include <QtGui/QPainter>
#include <QtGui/QFont>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QToolTip>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlError>
#include <QDialog>
#include <QVBoxLayout>
#include <QCursor>
#include <QtCore/QCoreApplication>
#include <QtGui/QPainter>
#include <QtGui/QFont>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QToolTip>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlError>
#include <QDialog>
#include <QVBoxLayout>
#include <QCursor>
#include <QQuickWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QSqlQuery>
#include <QQmlContext>



#include <QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);

    serial->setPortName("COM14"); //
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadWrite)) {
        connect(serial, &QSerialPort::readyRead, this, &MainWindow::readSerial);
    } else {
        QMessageBox::warning(this, "Serial Error", serial->errorString());
    }

    connect(ui->pushButton_ajouter, &QPushButton::clicked, this, &MainWindow::on_pushButton_ajouter_clicked);
    connect(ui->pushButton_rechercheid, &QPushButton::clicked, this, &MainWindow::on_pushButton_rechercheid_clicked);
    connect(ui->pushButton_modifier, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_clicked);
    connect(ui->pushButton_supprimer, &QPushButton::clicked, this, &MainWindow::on_pushButton_supprimer_clicked);
    connect(ui->pushButton_afficher, &QPushButton::clicked, this, &MainWindow::on_pushButton_afficher_clicked);
    connect(ui->pushButton_pdf, &QPushButton::clicked, this, &MainWindow::on_pushButton_pdf_clicked);
    connect(ui->buttonRechercher, &QPushButton::clicked, this, &MainWindow::on_buttonRechercher_clicked);
    connect(ui->buttonTrier, &QPushButton::clicked, this, &MainWindow::on_buttonTrier_clicked);
    connect(ui->pushButton_statistiques, &QPushButton::clicked, this, &MainWindow::on_pushButton_statistiques_clicked);


    refreshMap();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{

    qDebug() << "ajouter 1 :";

    int id_ressource = ui->lineEdit_id->text().toInt();
    QString type = ui->lineEdit_type->text();
    QString nom = ui->lineEdit_nom->text();
    QString description = ui->lineEdit_description->text();
    QString disponibilite = ui->lineEdit_disponibilite->text();
    QString fournisseur = ui->lineEdit_fournisseur->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString phone = ui->lineEdit_phone->text();

    qDebug() << "ajouter 2 :";


    Ressource r(id_ressource, type, nom, description, disponibilite, fournisseur, adresse, phone);
        // Set values and attempt to add the Fournisseur to the database

    qDebug() << "ajouter 3 :";

    res.setId(id_ressource);
    res.setType(type);
    res.setNom(nom);
    res.setDescription(description);
    res.setDisponibilite(disponibilite);
    res.setFournisseur(fournisseur);
    res.setAdresse(adresse);
    res.setPhone(phone);


    if (r.ajouter()) {
        qDebug() << "ajouter 4 :";


        QMessageBox::information(this, "Success", "Ressource added successfully.");
        //  trayIcon->showMessage("Notification", "Ressource added successfully.", QSystemTrayIcon::Information, 3000);


}


void MainWindow::on_pushButton_rechercheid_clicked()
{
    int id_ressource = ui->lineEdit_id_2->text().toInt();
    QSqlQuery query;
    query.prepare("SELECT * FROM ressource WHERE id_ressource = :id_ressource");
    query.bindValue(":id_ressource", id_ressource);

    if (query.exec() && query.next()) {
        ui->lineEdit_id->setText(query.value("id_ressource").toString());
        ui->lineEdit_type->setText(query.value("type").toString());
        ui->lineEdit_nom->setText(query.value("nom").toString());
        ui->lineEdit_description->setText(query.value("description").toString());
        ui->lineEdit_disponibilite->setText(query.value("disponibilite").toString());
        ui->lineEdit_fournisseur->setText(query.value("fournisseur").toString());
        ui->lineEdit_adresse->setText(query.value("adresse").toString());
        ui->lineEdit_phone->setText(query.value("phone").toString());
    } else {
    }
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id_ressource = ui->lineEdit_id->text().toInt();
    QString type = ui->lineEdit_type->text();
    QString nom = ui->lineEdit_nom->text();
    QString description = ui->lineEdit_description->text();
    QString disponibilite = ui->lineEdit_disponibilite->text();
    QString fournisseur = ui->lineEdit_fournisseur->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString phone = ui->lineEdit_phone->text();

    Ressource r(id_ressource, type, nom, description, disponibilite, fournisseur, adresse, phone);
    if (r.modifier(id_ressource)) {
        QMessageBox::information(this, "Succès", "Ressource modifiée avec succès");
    } else {
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int id_ressource = ui->lineEdit_id->text().toInt();
    Ressource r;
    if (r.supprimer(id_ressource)) {
        QMessageBox::information(this, "Succès", "Ressource supprimée avec succès");
    } else {
    }
}

void MainWindow::on_pushButton_afficher_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM ressource");

    QSqlQueryModel *model = new QSqlQueryModel(this);

    if (query.exec()) {
        model->setQuery(query);
        // Si vous souhaitez personnaliser les en-têtes de colonne
        model->setHeaderData(0, Qt::Horizontal, tr("ID Ressource"));
        model->setHeaderData(1, Qt::Horizontal, tr("Type"));
        model->setHeaderData(2, Qt::Horizontal, tr("Nom"));
        model->setHeaderData(3, Qt::Horizontal, tr("Description"));
        model->setHeaderData(4, Qt::Horizontal, tr("Disponibilité"));
        model->setHeaderData(5, Qt::Horizontal, tr("Fournisseur"));
        model->setHeaderData(6, Qt::Horizontal, tr("Adresse"));
        model->setHeaderData(7, Qt::Horizontal, tr("Téléphone"));
    } else {
        // Gestion de l'erreur
    }

    ui->tableView->setModel(model);
}
void MainWindow::on_pushButton_pdf_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT id_ressource, type, nom, description, disponibilite, fournisseur, adresse, phone FROM ressource");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Problème avec la base de données.");
        return;
    }

    QString html = R"(
        <html>
        <head>
            <style>
                body {
                    font-family: Arial, sans-serif;
                }
                table {
                    border-collapse: collapse;
                    width: 100%;
                    font-size: 36px;
                }
                th, td {
                    border: 1px solid black;
                    padding: 8px;
                    text-align: center;
                }
                th {
                    background-color: #f2f2f2;
                }
            </style>
        </head>
        <body>            <table>
                <tr>
                    <th>ID</th>
                    <th>Type</th>
                    <th>Nom</th>
                    <th>Description</th>
                    <th>Disponibilité</th>
                    <th>Fournisseur</th>
                    <th>Adresse</th>
                    <th>Téléphone</th>
                </tr>
    )";

    while (query.next()) {
        html += "<tr>";
        for (int i = 0; i < 8; ++i) {
            html += "<td>" + query.value(i).toString() + "</td>";
        }
        html += "</tr>";
    }

    html += R"(
            </table>
        </body>
        </html>
    )";

    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer PDF", "", "*.pdf");
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf")) fileName += ".pdf";

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setResolution(300);
    pdfWriter.setPageMargins(QMargins(60, 60, 60, 60));

    QTextDocument doc;
    doc.setHtml(html);
    doc.setPageSize(QSizeF(pdfWriter.width(), pdfWriter.height()));

    QPainter painter(&pdfWriter);
    doc.drawContents(&painter);
    painter.end();

    QMessageBox::information(this, "Succès", "PDF généré avec succès !");
}
void MainWindow::on_buttonRechercher_clicked()
{
    QString input = ui->lineEdit_recherche_3->text().trimmed();
    QString modeRecherche = ui->comboBox_18->currentText().trimmed();
    qDebug() << "Mode de recherche sélectionné :" << modeRecherche;

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Recherche par ID
    if (modeRecherche == "Rechercher_par_ID") {
        QRegularExpression regex("^\\d+$");
        if (!regex.match(input).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Veuillez entrer un ID valide (nombre entier).");
            return;
        }

        query.prepare("SELECT * FROM ressource WHERE id_ressource = :id");
        query.bindValue(":id", input.toInt());
    }

    // Recherche par nom
    else if (modeRecherche == "Rechercher_par_Nom") {
        if (input.isEmpty()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le champ nom ne peut pas être vide.");
            return;
        }

        query.prepare("SELECT * FROM ressource WHERE nom LIKE :nom");
        query.bindValue(":nom", "%" + input + "%");
    }

    // Recherche par type
    else if (modeRecherche == "Rechercher_par_Type") {
        if (input.isEmpty()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le champ type ne peut pas être vide.");
            return;
        }

        query.prepare("SELECT * FROM ressource WHERE type LIKE :type");
        query.bindValue(":type", "%" + input + "%");
    }

    // Recherche par disponibilité
    else if (modeRecherche == "Rechercher_par_Disponibilite") {
        if (input.isEmpty()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le champ disponibilité ne peut pas être vide.");
            return;
        }

        query.prepare("SELECT * FROM ressource WHERE disponibilite LIKE :dispo");
        query.bindValue(":dispo", "%" + input + "%");
    }

    // Recherche par fournisseur
    else if (modeRecherche == "Rechercher_par_Fournisseur") {
        if (input.isEmpty()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le champ fournisseur ne peut pas être vide.");
            return;
        }

        query.prepare("SELECT * FROM ressource WHERE fournisseur LIKE :fournisseur");
        query.bindValue(":fournisseur", "%" + input + "%");
    }

    else {
        QMessageBox::warning(this, "Mode inconnu", "Mode de recherche inconnu");
        return;
    }

    // Exécution de la requête
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        return;
    }

    model->setQuery(std::move(query));
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}
void MainWindow::on_buttonTrier_clicked()
{
    QString modeTri = ui->comboBox_188->currentText().trimmed();
    qDebug() << "Mode de tri sélectionné : " << modeTri;

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    if (modeTri == "Trier_par_ID") {
        // Tri par ID de ressource
        query.prepare("SELECT * FROM ressource ORDER BY id_ressource ASC");
    }
    else if (modeTri == "Trier_par_Nom") {
        // Tri par nom
        query.prepare("SELECT * FROM ressource ORDER BY nom ASC");
    }
    else if (modeTri == "Trier_par_Type") {
        // Tri par type
        query.prepare("SELECT * FROM ressource ORDER BY type ASC");
    }
    else if (modeTri == "Trier_par_Disponibilite") {
        // Tri par disponibilité
        query.prepare("SELECT * FROM ressource ORDER BY disponibilite ASC");
    }
    else if (modeTri == "Trier_par_Fournisseur") {
        // Tri par fournisseur
        query.prepare("SELECT * FROM ressource ORDER BY fournisseur ASC");
    }
    else if (modeTri == "Trier_par_Adresse") {
        // Tri par adresse
        query.prepare("SELECT * FROM ressource ORDER BY adresse ASC");
    }
    else if (modeTri == "Trier_par_Phone") {
        // Tri par téléphone (numérique ou alphabétique)
        query.prepare("SELECT * FROM ressource ORDER BY phone ASC");
    }
    else {
        QMessageBox::warning(this, "Mode de tri inconnu", "Mode de tri inconnu.");
        return;
    }

    // Exécution de la requête
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        return;
    }

    qDebug() << "Requête exécutée avec succès !";

    // Si aucune donnée n'est retournée
    if (query.size() == 0) {
        QMessageBox::information(this, "Aucun résultat", "Aucune ressource trouvée.");
    } else {
        model->setQuery(query);

        // Définir les en-têtes des colonnes pour la table des ressources
        model->setHeaderData(0, Qt::Horizontal, "ID Ressource");
        model->setHeaderData(1, Qt::Horizontal, "Type");
        model->setHeaderData(2, Qt::Horizontal, "Nom");
        model->setHeaderData(3, Qt::Horizontal, "Description");
        model->setHeaderData(4, Qt::Horizontal, "Disponibilité");
        model->setHeaderData(5, Qt::Horizontal, "Fournisseur");
        model->setHeaderData(6, Qt::Horizontal, "Adresse");
        model->setHeaderData(7, Qt::Horizontal, "Téléphone");

        // Mettre à jour le modèle dans le tableau
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();

        qDebug() << "Données triées et affichées dans le tableau.";
    }
}

void MainWindow::on_pushButton_statistiques_clicked()
{
    // Préparer la requête pour récupérer les types et le nombre de ressources pour chaque type
    QSqlQuery query;
    query.prepare("SELECT type, COUNT(*) FROM ressource GROUP BY type");
    query.exec();

    // Créer un objet QPieSeries pour les tranches du graphique
    QPieSeries *series = new QPieSeries();

    // Créer un graphique QChart pour ajouter les tranches
    QChart *chart = new QChart();
    chart->setTitle("Répartition des ressources par type");

    // Traiter chaque ligne de résultat et ajouter une tranche au graphique
    while (query.next()) {
        QString type = query.value(0).toString();  // Récupère le type
        int count = query.value(1).toInt();       // Nombre de ressources pour ce type

        // Créer une tranche pour chaque type
        QPieSlice *slice = new QPieSlice(type, count);  // Le label est le type et la taille est le nombre
        slice->setLabelVisible(true);  // Afficher l'étiquette sur la tranche

        // Définir l'étiquette pour chaque tranche avec le nom du type et le nombre de ressources
        QString label = type + " (" + QString::number(count) + " ressources)";
        slice->setLabel(label);

        // Ajouter la tranche à la série
        series->append(slice);
    }

    // Ajouter la série de tranches au graphique

    chart->addSeries(series);

    // Configurer l'angle du demi-cercle (le graphique sera un demi-cercle)
    series->setPieStartAngle(0);
    series->setPieEndAngle(180);

    // Créer un QChartView pour afficher le graphique avec le rendu antialiasing
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Créer un dialogue pour afficher le graphique dans une fenêtre séparée
    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->setWindowTitle("Statistiques des Ressources par Type");
    dialog->resize(700, 500);  // Redimensionner la fenêtre du graphique
    dialog->exec();  // Afficher la fenêtre de statistiques
}









#include <QRegularExpression>
#include <QtSerialPort/QSerialPort>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>


void MainWindow::readSerial() {
    // Tant qu’il y a des lignes complètes à lire...
    while (serial->canReadLine()) {
        QByteArray line = serial->readLine();
        QString text = QString::fromUtf8(line).trimmed();
        qDebug() << "[SERIAL] Ligne reçue:" << text;

        // On ne garde que les chaînes hex majuscules (4 à 20 caractères)
        static const QRegularExpression rx("^[0-9A-F]{4,20}$");
        if (!rx.match(text).hasMatch()) {
            qDebug() << "[SERIAL] Ignorée (pas un UID valide)";
            continue;
        }

        // Normalisation en majuscules
        QString code = text.toUpper();
        qDebug() << "[SERIAL] UID valide détecté:" << code;

        checkRFID(code);
    }
}

void MainWindow::checkRFID(const QString &rfid) {
    QString code = rfid.trimmed().toUpper();

    QSqlQuery query;
    const QString sql = R"(
        SELECT STATUT
          FROM PROJET
         WHERE TRIM(UPPER(RFID)) = :rfid
    )";
    query.prepare(sql);
    query.bindValue(":rfid", code);

    qDebug() << "[SQL] Testing RFID value:" << code;

    if (!query.exec()) {
        qDebug() << "[SQL] Exec error:" << query.lastError().text();
        QMessageBox::critical(this,
                              "Database Error",
                              query.lastError().text());
        serial->write("CLOSE\n");
        return;
    }

    int count = 0;
    QString statut;
    while (query.next()) {
        statut = query.value(0).toString();
        ++count;
        qDebug() << "[SQL] Statut trouvé:" << statut;
    }
    qDebug() << "[SQL] Lignes matchées:" << count;

    if (count == 0) {
        QMessageBox::warning(this,
                             "RFID introuvable",
                             QString("Aucun projet associé à ce RFID '%1'.").arg(code));
        serial->write("CLOSE\n");
        return;
    }

    statut = statut.trimmed().toLower();
    if (statut == "terminé" || statut == "termine") {
        QMessageBox::information(this,
                                 "Accès autorisé",
                                 QString("Statut 'terminé' pour RFID '%1'").arg(code));
        serial->write("OPEN\n");
    } else {
        QMessageBox::warning(this,
                             "Accès refusé",
                             QString("Statut '%1' ≠ 'terminé' pour RFID '%2'")
                                 .arg(statut).arg(code));
        serial->write("CLOSE\n");
    }
}

