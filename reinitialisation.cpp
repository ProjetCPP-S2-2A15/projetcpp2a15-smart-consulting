#include "reinitialisation.h"
#include "ui_reinitialisation.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

Reinitialisation::Reinitialisation(const QString &username, const QString &question, QSqlDatabase db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Reinitialisation)
    , database(db)
    , utilisateur(username)
{
    ui->setupUi(this);
    ui->label_question->setText(question);
}

Reinitialisation::~Reinitialisation()
{
    delete ui;
}

void Reinitialisation::on_pushButton_valider_clicked()
{
    QString reponse = ui->lineEdit_reponse->text();
    QString nouveauMDP = ui->lineEdit_nouveau_mdp->text();

    if (reponse.isEmpty() || nouveauMDP.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs.");
        return;
    }

    QSqlQuery query(database);
    query.prepare("SELECT reponse_secrete FROM UTILISATEUR WHERE username = :username");
    query.bindValue(":username", utilisateur);

    if (query.exec() && query.next()) {
        QString bonneReponse = query.value(0).toString();
        if (bonneReponse == reponse) {
            QSqlQuery updateQuery(database);
            updateQuery.prepare("UPDATE UTILISATEUR SET mot_de_passe = :mdp WHERE username = :username");
            updateQuery.bindValue(":mdp", nouveauMDP);
            updateQuery.bindValue(":username", utilisateur);

            if (updateQuery.exec()) {
                QMessageBox::information(this, "Succès", "Mot de passe mis à jour !");
                accept(); // Ferme la fenêtre
            } else {
                QMessageBox::critical(this, "Erreur", "Erreur lors de la mise à jour.");
            }
        } else {
            QMessageBox::warning(this, "Erreur", "Réponse incorrecte.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Utilisateur introuvable.");
    }
}
