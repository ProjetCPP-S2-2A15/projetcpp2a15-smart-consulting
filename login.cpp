
#include "login.h"
#include "ui_login.h"
#include "reinitialisation.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QInputDialog>

Login::Login(QSqlDatabase db, QWidget *parent)
    : QDialog(parent), ui(new Ui::Login), database(db)
{
    ui->setupUi(this);
       connect(ui->pushButton_motdepasseoublie, &QPushButton::clicked, this, &Login::on_pushButton_motdepasseoublie_clicked);
}

Login::~Login()
{
    delete ui;
}

void Login::verifierUtilisateur(const QString &username, const QString &password)
{
    QSqlQuery query(database);
    query.prepare("SELECT * FROM UTILISATEUR WHERE username = :username AND mot_de_passe = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        accept();
    } else {
        QMessageBox::warning(this, "Erreur", "Nom d'utilisateur ou mot de passe incorrect.");
    }
}

void Login::on_pushButton_connexion_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    verifierUtilisateur(username, password);
}

void Login::on_pushButton_motdepasseoublie_clicked()
{
    QString username = ui->lineEdit_username->text();

    QSqlQuery query(database);
    query.prepare("SELECT question_secrete FROM UTILISATEUR WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        QString question = query.value(0).toString();
        Reinitialisation *dialog = new Reinitialisation(username, question, database, this);
        dialog->exec();
    } else {
        QMessageBox::warning(this, "Erreur", "Utilisateur non trouvé.");
    }
}

void Login::reinitialiserMotDePasse(const QString &username, const QString &reponse)
{
    // Ne sert plus ici, déplacé dans Reinitialisation
}
