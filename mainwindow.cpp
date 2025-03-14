#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cnx.createconnect();

    connect(ui->pushButton_16,&QPushButton::clicked,this,&MainWindow::on_btnAjouter_clicked);
    connect(ui->pushButton_19,&QPushButton::clicked,this,&MainWindow::on_btnSupprimer_clicked);
    connect(ui->pushButton_20,&QPushButton::clicked,this,&MainWindow::on_btnModifier_clicked);

    afficherTaches();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAjouter_clicked() {
    int Id = ui->lineEditID->text().toInt();
    QString nom = ui->lineEditNom->text();
    QString description = ui->lineEditDescription->text();
    int consultant = ui->lineEditConsultant->text().toInt();
    QString echeance = ui->dateEditEcheance->date().toString("yyyy-MM-dd");
    QString statut = ui->comboBoxStatut->currentText();

    if (nom.isEmpty() || description.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    if (tache.ajouterTache(Id,nom, description, consultant, echeance, statut)) {
        QMessageBox::information(this, "Succès", "Tâche ajoutée avec succès !");
        afficherTaches();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout de la tâche.");
    }
}
void MainWindow::afficherTaches() {
    QSqlQuery query("SELECT ID_TACHE,NOM, DESCRIPTION, CONSULTANT_ASSIGNE, ECHEANCE, STATUT FROM TACHE");
    int row = 0;
    ui->tableWidget->setRowCount(0); // Réinitialiser la table

    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));

        row++;
    }

}
void MainWindow::on_btnModifier_clicked() {
    int id = ui->lineEditID->text().toInt();
    QString nom = ui->lineEditNom->text();
    QString description = ui->lineEditDescription->text();
    int consultant = ui->lineEditConsultant->text().toInt();
    QString echeance = ui->dateEditEcheance->date().toString("yyyy-MM-dd");
    QString statut = ui->comboBoxStatut->currentText();

    if (tache.modifierTache(id, nom, description, consultant, echeance, statut)) {
        QMessageBox::information(this, "Succès", "Tâche modifiée !");
        afficherTaches();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la modification.");
    }
}
void MainWindow::on_btnSupprimer_clicked() {
    int id = ui->lineEditID->text().toInt();

    if (tache.supprimerTache(id)) {
        QMessageBox::information(this, "Succès", "Tâche supprimée !");
        afficherTaches();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression.");
    }
}


