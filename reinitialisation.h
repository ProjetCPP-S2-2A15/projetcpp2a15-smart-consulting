#ifndef REINITIALISATION_H
#define REINITIALISATION_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Reinitialisation;
}

class Reinitialisation : public QDialog
{
    Q_OBJECT

public:
    explicit Reinitialisation(const QString &username, const QString &question, QSqlDatabase db, QWidget *parent = nullptr);
    ~Reinitialisation();

private slots:
    void on_pushButton_valider_clicked();

private:
    Ui::Reinitialisation *ui;
    QSqlDatabase database;
    QString utilisateur;
};

#endif // REINITIALISATION_H
