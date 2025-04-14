#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QSqlDatabase db, QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_connexion_clicked();
    void on_pushButton_motdepasseoublie_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase database;
    void verifierUtilisateur(const QString &username, const QString &password);
    void reinitialiserMotDePasse(const QString &username, const QString &reponse);
};

#endif // LOGIN_H
