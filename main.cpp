#include "mainwindow.h"
#include "database.h"
#include "login.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    connect c;
    bool test = c.set_connection();

    if (!test) {
        QMessageBox::critical(nullptr, "Erreur", "Connexion à la base de données impossible.");
        return -1;
    }

    QSqlDatabase db = QSqlDatabase::database(); // récupère la base connectée

    Login login(db);
    if (login.exec() == QDialog::Accepted) {
        MainWindow w;
        w.show();
        return a.exec();
    }

    return 0;
}
