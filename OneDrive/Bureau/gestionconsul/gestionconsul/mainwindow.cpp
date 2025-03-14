#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "database.h"
#include "consultantmanager.h"
#include <QMessageBox>
#include <QSqlQueryModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

// Ajouter un consultant
void MainWindow::on_pushButton_9_clicked() {
    QString email = ui->lineEdit_4->text();
    QString nom = ui->lineEdit_5->text();
    QString specialite = ui->lineEdit_7->text();
    QString disponibilite = ui->lineEdit_8->text();

    // Vérification des champs obligatoires (sauf l'ID car il est auto-généré)
    if (email.isEmpty() || nom.isEmpty() || specialite.isEmpty() || disponibilite.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs !");
        return;
    }

    // Création du consultant sans ID (Oracle s'occupe de le générer)
    Consultant consultant(0, nom, email, specialite, disponibilite);

    if (consultantManager->ajouterConsultant(consultant)) {
        QMessageBox::information(this, "Succès", "Consultant ajouté !");
        loadConsultants();  // Mise à jour de la liste

        // Vider les champs après l'ajout
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
}

MainWindow::~MainWindow()
{
    delete ui;
}


