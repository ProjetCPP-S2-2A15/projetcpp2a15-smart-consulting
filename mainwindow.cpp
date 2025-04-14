#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "database.h"
#include "consultantmanager.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QTextDocument>
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>
#include <QStandardPaths>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include "login.h"
#include "chatwindow.h"

QT_USE_NAMESPACE



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Ouvrir la fenêtre de login
    Login loginDialog(QSqlDatabase::database(), this);

    if (loginDialog.exec() == QDialog::Accepted) {
        // L'utilisateur est connecté, on continue avec l'application
    } else {
        // Si l'utilisateur annule, on ferme l'application
        QApplication::quit();
    }
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_3_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::on_pushButton_8_clicked);

}
void MainWindow::setUtilisateurConnecte(const QString &pseudo)
{
    utilisateurConnecte = pseudo;
}

void MainWindow::on_pushButton_chat_clicked()
{
    ChatWindow *chat = new ChatWindow(utilisateurConnecte, QSqlDatabase::database(), this);
    chat->exec();
}



void MainWindow::on_pushButton_8_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT id_consultant, nom, email, specialite, disponibilite FROM CONSULTANT");

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
void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT disponibilite, COUNT(*) FROM consultant GROUP BY disponibilite");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        return;
    }

    // Create a pie chart series
    QPieSeries *series = new QPieSeries();

    // Create a chart object to add the slices
    QChart *chart = new QChart();
    chart->setTitle("statistiques des consultants");

    while (query.next()) {
        QString statut = query.value(0).toString();  // Get the status of the project
        int count = query.value(1).toInt();          // Count of projects with that status

        // Create a slice for each distinct statut
        QPieSlice *slice = new QPieSlice(statut, count);
        slice->setLabelVisible(true);

        // Set the label to display the statut and the count
        QString label = statut + ": " + QString::number(count) + " consultants";
        slice->setLabel(label);
        slice->setLabelPosition(QPieSlice::LabelInsideHorizontal);
        slice->setLabelFont(QFont("Arial", 6, QFont::Bold));

        // Connect hover signal to show tooltip
        connect(slice, &QPieSlice::hovered, this, [=](bool state){
            if (state) {
                QToolTip::showText(QCursor::pos(),
                                   "Statut: " + statut +
                                       "\nNombre  des consultants: " + QString::number(count));
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



// Ajouter un consultant
void MainWindow::on_pushButton_9_clicked() {
    QString email = ui->lineEdit_4->text();
    QString nom = ui->lineEdit_5->text();
    QString specialite = ui->lineEdit_7->text();
    QString disponibilite = ui->lineEdit_8->text();


    if (email.isEmpty() || nom.isEmpty() || specialite.isEmpty() || disponibilite.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs !");
        return;
    }

    // Création du consultant sans ID
    Consultant consultant(0, nom, email, specialite, disponibilite);

    if (consultantManager->ajouterConsultant(consultant)) {
        QMessageBox::information(this, "Succès", "Consultant ajouté !");
        loadConsultants();  // Mise à jour de la liste


        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible d'ajouter le consultant !");
    }
}



// Modifier un consultant
void MainWindow::on_pushButton_10_clicked() {
    int row = ui->tableWidget->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner un consultant !");
        return;
    }

    int id = ui->tableWidget->item(row, 0)->text().toInt();
    QString nom = ui->lineEdit_4->text();
    QString email = ui->lineEdit_2->text();
    QString specialite = ui->lineEdit_5->text();
    QString disponibilite = ui->lineEdit_7->text();

    Consultant consultant(id, nom, email, specialite, disponibilite);
    if (consultantManager->modifierConsultant(consultant)) {
        QMessageBox::information(this, "Succès", "Consultant modifié !");
        loadConsultants();  // Mettre à jour l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification !");
    }
}



// Supprimer un consultant
void MainWindow::on_pushButton_11_clicked() {
    int row = ui->tableWidget->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner un consultant !");
        return;
    }

    int id = ui->tableWidget->item(row, 0)->text().toInt();

    if (consultantManager->supprimerConsultant(id)) {
        QMessageBox::information(this, "Succès", "Consultant supprimé !");
        loadConsultants();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression !");
    }
}




// Charger les consultants dans le QTableWidget
void MainWindow::loadConsultants() {
    QSqlQuery query;
    query.prepare("SELECT id_consultant, nom, email, specialite, disponibilite FROM CONSULTANT");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec du chargement des consultants !");
        return;
    }

    ui->tableWidget->clear();  // Nettoyer la table avant d'ajouter de nouvelles données
    ui->tableWidget->setRowCount(0);  // Réinitialiser le nombre de lignes
    ui->tableWidget->setColumnCount(5);  // Assurer le bon nombre de colonnes

    QStringList headers = {"ID", "Nom", "Email", "Spécialité", "Disponibilité"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);  // Définir les en-têtes

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("id_consultant").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("nom").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("email").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("specialite").toString()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("disponibilite").toString()));
        row++;
    }
    ui->tableWidget->sortItems(1, Qt::AscendingOrder); // colonne 1 = nom

}



void MainWindow::on_lineEdit_textChanged(const QString &text)
{
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *item = ui->tableWidget->item(row, 3); // colonne 3 = spécialité
        if (item && !item->text().contains(text, Qt::CaseInsensitive)) {
            ui->tableWidget->setRowHidden(row, true);
        } else {
            ui->tableWidget->setRowHidden(row, false);
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


