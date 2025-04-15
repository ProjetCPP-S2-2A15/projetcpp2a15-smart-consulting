#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QSqlDatabase db, QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_pushButton_inscrire_clicked();

private:
    Ui::Register *ui;
    QSqlDatabase database;
};

#endif // REGISTER_H
