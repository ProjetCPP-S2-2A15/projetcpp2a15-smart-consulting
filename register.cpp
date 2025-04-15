#include "register.h"
#include "ui_register.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

Register::Register(QSqlDatabase db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
    , database(db)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_inscrire_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString question = ui->lineEdit_question->text();
    QString reponse  = ui->lineEdit_reponse->text();

    if (username.isEmpty() || password.isEmpty() || question.isEmpty() || reponse.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs !");
        return;
    }

    QSqlQuery query(database);
    query.prepare("INSERT INTO UTILISATEUR (username, mot_de_passe, question_secrete, reponse_secrete) "
                  "VALUES (:u, :p, :q, :r)");
    query.bindValue(":u", username);
    query.bindValue(":p", password);
    query.bindValue(":q", question);
    query.bindValue(":r", reponse);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Utilisateur inscrit avec succès !");
        this->accept();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'inscription : " + query.lastError().text());
    }
}
