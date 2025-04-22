#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projet.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTextDocument>
#include <QPainter>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QPageSize>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QToolTip>
#include <QCursor>
#include <QFont>
#include <QVBoxLayout>
#include <QDialog>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>


#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

#include "import.h"

#include <QPrinter>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>


#include "backup.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_ajouter_2, &QPushButton::clicked, this, &::MainWindow::on_pushButton_ajouter_2_clicked);
    connect(ui->pushButton_rechercheid, &QPushButton::clicked, this, &MainWindow::on_pushButton_rechercheid_clicked);
    connect(ui->pushButton_modifier, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_clicked);
    connect(ui->pushButton_supprimer, &QPushButton::clicked, this, &MainWindow::on_pushButton_supprimer_clicked);
    connect(ui->pushButton_afficher, &QPushButton::clicked, this, &MainWindow::on_pushButton_afficher_clicked);
    connect(ui->pushButton_pdf, &QPushButton::clicked, this, &MainWindow::on_pushButton_pdf_clicked);
    connect(ui->buttonRechercher, &QPushButton::clicked, this, &MainWindow::on_buttonRechercher_clicked);
    connect(ui->buttonTrier, &QPushButton::clicked, this, &MainWindow::on_buttonTrier_clicked);
    connect(ui->pushButton_statistiques, &QPushButton::clicked, this, &MainWindow::on_pushButton_statistiques_clicked);
    connect(ui->pushButton_QR, &QPushButton::clicked, this, &MainWindow::on_pushButton_QR_clicked);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_2_clicked()
{
    int id_projet = ui->lineEdit_id_2->text().toInt();
    QString nom = ui->lineEdit_nom_3->text();
    QString description = ui->lineEdit_description_3->text();
    QString statut = ui->lineEdit_statut_->text();

    Projet p(id_projet, nom, description, statut);
    if (p.ajouter()) {
        QMessageBox::information(this, "Succès", "Projet ajouté avec succès");
    } else {
       // QMessageBox::critical(this, "Erreur", "Échec de l'ajout du projet");
    }
}

void MainWindow::on_pushButton_rechercheid_clicked()
{
    int id_projet = ui->lineEdit_id_3->text().toInt();
    QSqlQuery query;
    query.prepare("SELECT * FROM projet WHERE id_projet = :id_projet");
    query.bindValue(":id_projet", id_projet);

    if (query.exec() && query.next()) {
        ui->lineEdit_id_2->setText(query.value("id_projet").toString());
        ui->lineEdit_nom_3->setText(query.value("nom").toString());
        ui->lineEdit_description_3->setText(query.value("description").toString());
        ui->lineEdit_statut_->setText(query.value("statut").toString());
    } else {
        QMessageBox::warning(this, "Erreur", "Projet non trouvé");
    }
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id_projet = ui->lineEdit_id_2->text().toInt();
    QString nom = ui->lineEdit_nom_3->text();
    QString description = ui->lineEdit_description_3->text();
    QString statut = ui->lineEdit_statut_->text();

    Projet p(id_projet, nom, description, statut);
    if (p.modifier(id_projet)) {
        QMessageBox::information(this, "Succès", "Projet modifié avec succès");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la modification du projet");
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int id_projet = ui->lineEdit_id_2->text().toInt();
    Projet p;
    if (p.supprimer(id_projet)) {
        QMessageBox::information(this, "Succès", "Projet supprimé avec succès");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression du projet");
    }
}

void MainWindow::on_pushButton_afficher_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM projet");

    QSqlQueryModel *model = new QSqlQueryModel(this);
    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, tr("ID Projet"));
        model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, tr("Description"));
        model->setHeaderData(3, Qt::Horizontal, tr("Statut"));
    }

    ui->tableView->setModel(model);
}
void MainWindow::on_pushButton_pdf_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT id_projet, nom, description, statut FROM projet");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Problème avec la base de données.");
        return;
    }

    // HTML avec grande taille de police et titre bien visible
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
                    font-size: 48px; /* taille de police réduite pour plus d'espace */
                }
                th, td {
                    border: 1px solid black;
                    padding: 17px;
                    text-align: center;
                }
                th {
                    background-color: #f2f2f2;
                }
            </style>
        </head>
        <body>
            <table>
                <tr>
                    <th>ID Projet</th>
                    <th>Nom</th>
                    <th>Description</th>
                    <th>Statut</th>
                </tr>
    )";

    // Remplissage du tableau avec les données de la table 'projet'
    while (query.next()) {
        html += "<tr>";
        html += "<td>" + query.value(0).toString() + "</td>";
        html += "<td>" + query.value(1).toString() + "</td>";
        html += "<td>" + query.value(2).toString() + "</td>";
        html += "<td>" + query.value(3).toString() + "</td>";
        html += "</tr>";
    }

    html += R"(
            </table>
        </body>
        </html>
    )";

    // Choix du fichier
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer PDF", "", "*.pdf");
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf")) fileName += ".pdf";

    // Configuration du PDF
    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setResolution(300); // haute qualité
    pdfWriter.setPageMargins(QMargins(60, 60, 60, 60)); // marges

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

    // Recherche par ID de projet
    if (modeRecherche == "Rechercher_par_ID") {
        QRegularExpression regex("^\\d+$");
        if (!regex.match(input).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Veuillez entrer un identifiant valide (nombre entier).");
            return;
        }

        int idProjet = input.toInt();

        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("SELECT id_projet, nom, description, statut FROM projet WHERE id_projet = :idProjet");
        query.bindValue(":idProjet", idProjet);

        if (!query.exec()) {
            QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
            return;
        }

        if (query.size() == 0) {
            QMessageBox::information(this, "Aucune correspondance", "Aucun projet trouvé avec cet identifiant.");
            return;
        }

        model->setQuery(std::move(query));
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    }

    // Recherche par nom de projet
    else if (modeRecherche == "Rechercher_par_Nom") {
        if (input.isEmpty()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le nom du projet ne peut pas être vide.");
            return;
        }

        // Exécution de la requête pour rechercher par nom
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("SELECT id_projet, nom, description, statut FROM projet WHERE nom LIKE :nom");
        query.bindValue(":nom", "%" + input + "%");

        if (!query.exec()) {
            QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
            return;
        }

        if (query.size() == 0) {
            QMessageBox::information(this, "Aucune correspondance", "Aucun projet trouvé avec ce nom.");
            return;
        }

        model->setQuery(std::move(query));
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    }

    // Recherche par statut (texte)
    else if (modeRecherche == "Rechercher_par_Statut") {
        if (input.isEmpty()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le statut ne peut pas être vide.");
            return;
        }

        // Exécution de la requête pour rechercher par statut
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("SELECT id_projet, nom, description, statut FROM projet WHERE statut LIKE :statut");
        query.bindValue(":statut", "%" + input + "%");

        if (!query.exec()) {
            QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
            return;
        }

        if (query.size() == 0) {
            QMessageBox::information(this, "Aucune correspondance", "Aucun projet trouvé avec ce statut.");
            return;
        }

        model->setQuery(std::move(query));
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    }

    else {
        QMessageBox::warning(this, "Mode inconnu", "Mode de recherche inconnu");
    }
}
void MainWindow::on_buttonTrier_clicked()
{
    QString modeTri = ui->comboBox_10->currentText().trimmed();
    qDebug() << "Mode de tri sélectionné : " << modeTri;

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Determine the column to sort based on user selection
    if (modeTri == "Trier_par_ID") {
        // Tri par ID du projet
        query.prepare("SELECT id_projet, nom, description, statut "
                      "FROM projet ORDER BY id_projet ASC");
    }
    else if (modeTri == "Trier_par_Nom") {
        // Tri par nom du projet
        query.prepare("SELECT id_projet, nom, description, statut "
                      "FROM projet ORDER BY nom ASC");
    }
    else if (modeTri == "Trier_par_Description") {
        // Tri par description du projet
        query.prepare("SELECT id_projet, nom, description, statut "
                      "FROM projet ORDER BY description ASC");
    }
    else if (modeTri == "Trier_par_Statut") {
        // Tri par statut du projet
        query.prepare("SELECT id_projet, nom, description, statut "
                      "FROM projet ORDER BY statut ASC");
    }
    else {
        QMessageBox::warning(this, "Mode de tri inconnu", "Mode de tri inconnu.");
        return;
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        return;
    }

    qDebug() << "Requête exécutée avec succès !";

    if (query.size() == 0) {
        QMessageBox::information(this, "Aucun résultat", "Aucun projet trouvé.");
    } else {
        model->setQuery(query);

        // Définir les en-têtes des colonnes pour les projets
        model->setHeaderData(0, Qt::Horizontal, "ID Projet");
        model->setHeaderData(1, Qt::Horizontal, "Nom");
        model->setHeaderData(2, Qt::Horizontal, "Description");
        model->setHeaderData(3, Qt::Horizontal, "Statut");

        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();

        qDebug() << "Données affichées dans le tableau.";
    }
}
void MainWindow::on_pushButton_statistiques_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT statut, COUNT(*) FROM projet GROUP BY statut");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        return;
    }

    // Create a pie chart series
    QPieSeries *series = new QPieSeries();

    // Create a chart object to add the slices
    QChart *chart = new QChart();
    chart->setTitle("Répartition des projets (par statut)");

    while (query.next()) {
        QString statut = query.value(0).toString();  // Get the status of the project
        int count = query.value(1).toInt();          // Count of projects with that status

        // Create a slice for each distinct statut
        QPieSlice *slice = new QPieSlice(statut, count);
        slice->setLabelVisible(true);

        // Set the label to display the statut and the count
        QString label = statut + ": " + QString::number(count) + " projets";
        slice->setLabel(label);
        slice->setLabelPosition(QPieSlice::LabelInsideHorizontal);
        slice->setLabelFont(QFont("Arial", 6, QFont::Bold));

        // Connect hover signal to show tooltip
        connect(slice, &QPieSlice::hovered, this, [=](bool state){
            if (state) {
                QToolTip::showText(QCursor::pos(),
                                   "Statut: " + statut +
                                       "\nNombre de projets: " + QString::number(count));
            } else {
                QToolTip::hideText();
            }
        });

        // Append the slice to the series
        series->append(slice);
    }

    // Add the series to the chart
    chart->addSeries(series);

    // Set up the chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create a dialog to display the chart
    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->setWindowTitle("Statistiques");
    dialog->resize(700, 500);
    dialog->exec();
}


//jdid
void MainWindow::on_importer_clicked() {
    Import importer;
    importer.importDatabase(this);

    ui->tableView->setModel( projet.afficher());
}

void MainWindow::on_exportButton_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this, "Export to PDF", "", "PDF Files (*.pdf)");

    if (fileName.isEmpty()) {
        return;
    }


    QTextDocument doc;


    QString htmlContent;


    htmlContent += "<h1 style='text-align: center;'>Fournisseurs List</h1>";
    htmlContent += "<hr/>";


    htmlContent += "<table border='1' cellpadding='5' cellspacing='0' width='100%'>";


    htmlContent += "<tr>"
                   "<th>ID_projet</th>"
                   "<th>NOM</th>"
                   "<th>Description</th>"
                   "<th>Statut</th>"
                   "</tr>";


    QAbstractItemModel *model = ui->tableView->model();


    for (int row = 0; row < model->rowCount(); ++row) {
        htmlContent += "<tr>";
        for (int col = 0; col < model->columnCount(); ++col) {
            QString cellData = model->data(model->index(row, col)).toString();
            htmlContent += "<td>" + cellData + "</td>";
        }
        htmlContent += "</tr>";
    }

    htmlContent += "</table>";


    doc.setHtml(htmlContent);


    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));


    doc.print(&printer);


    QMessageBox::information(this, "Export Successful", "The data has been exported to PDF.");
}

void MainWindow::on_backup_clicked() {
    Backup backup;
    backup.exportDatabase(this);
}

void MainWindow::on_pushButton_QR_clicked()
{
    // Répertoire pour enregistrer les QR codes
    QString outputDir = QString("%1/QR_Codes").arg(QDir::currentPath());
    if (!QDir(outputDir).exists()) {
        if (QDir().mkdir(outputDir)) {
            qDebug() << "Répertoire créé pour les QR codes : " << outputDir;
        } else {
            QMessageBox::critical(this, "Erreur", "Impossible de créer le répertoire pour les QR codes.");
            return;
        }
    }

    // Vérifier si qrencode.exe existe
    QString qrencodePath = "C:/Users/ASUS/Desktop/anisprojet/tools/qrencode.exe";
    if (!QFile::exists(qrencodePath)) {
        QMessageBox::critical(this, "Erreur", QString("Le fichier qrencode.exe est introuvable au chemin : %1").arg(qrencodePath));
        qDebug() << "Le fichier qrencode.exe est introuvable.";
        return;
    } else {
        qDebug() << "qrencode.exe trouvé à : " << qrencodePath;
    }

    // Requête SQL pour récupérer les projets
    QSqlQuery query;
    if (!query.exec("SELECT id_projet, nom, description, statut FROM projet")) {
        QString errorMsg = QString("Erreur SQL : %1").arg(query.lastError().text());
        QMessageBox::critical(this, "Erreur SQL", errorMsg);
        qDebug() << errorMsg;
        return;
    }

    // Parcourir les projets et générer un QR code pour chacun
    while (query.next()) {
        QString idProjet = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString description = query.value(2).toString();
        QString statut = query.value(3).toString();

        // Contenu à encoder dans le QR code
        QString qrCodeData = QString("Projet ID: %1\nNom: %2\nDescription: %3\nStatut: %4")
                                 .arg(idProjet).arg(nom).arg(description).arg(statut);

        QString filePath = QString("%1/Projet_%2.png").arg(outputDir).arg(idProjet);

        // Commande pour générer le QR code
        QString command = QString("\"%1\" -o \"%2\" \"%3\"")
                              .arg(qrencodePath)
                              .arg(filePath)
                              .arg(qrCodeData);

        qDebug() << "Commande générée : " << command;

        // Exécuter le processus
        QProcess process;
        process.start(command);

        if (!process.waitForStarted()) {
            QMessageBox::critical(this, "Erreur", QString("Impossible de démarrer le processus pour générer le QR code : %1").arg(command));
            qDebug() << "Impossible de démarrer le processus : " << command;
            return;
        }

        if (!process.waitForFinished()) {
            QMessageBox::critical(this, "Erreur", QString("Échec de l'exécution de la commande : %1").arg(command));
            qDebug() << "Commande échouée : " << command;
            return;
        }

        // Vérifier si le fichier QR code a été généré
        if (!QFile::exists(filePath)) {
            qDebug() << "Échec de génération pour ID projet : " << idProjet << ", fichier attendu : " << filePath;
        } else {
            QImage qrImage(filePath);
            if (qrImage.isNull()) {
                qDebug() << "Échec de chargement de l'image : " << filePath;
                continue;
            }

            int textHeight = 30;
            QImage newImage(qrImage.width(), qrImage.height() + textHeight, QImage::Format_RGB32);
            newImage.fill(Qt::white);

            QPainter painter(&newImage);
            painter.drawImage(0, 0, qrImage);

            painter.setPen(QPen(Qt::black));
            painter.setFont(QFont("Arial", 12));
            QString text = nom;
            int textWidth = painter.fontMetrics().horizontalAdvance(text);
            int x = (newImage.width() - textWidth) / 2;
            int y = qrImage.height() + 20;
            painter.drawText(x, y, text);
            painter.end();

            // Sauvegarder l'image modifiée avec texte
            if (!newImage.save(filePath)) {
                qDebug() << "Échec de la sauvegarde de l'image avec texte : " << filePath;
            } else {
                qDebug() << "QR code généré avec texte pour le projet : " << nom << ", fichier : " << filePath;
            }
        }
    }

    QMessageBox::information(this, "Succès", QString("Les QR codes ont été générés dans : %1").arg(outputDir));
    qDebug() << "Génération des QR codes terminée avec succès.";
}
