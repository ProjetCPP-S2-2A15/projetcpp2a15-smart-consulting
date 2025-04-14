#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QDialog>
#include <QSqlDatabase>
#include <QTimer>

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChatWindow(const QString& pseudo, QSqlDatabase db, QWidget *parent = nullptr);
    ~ChatWindow();

private slots:
    void on_pushButton_envoyer_clicked();
    void chargerMessages();

private:
    Ui::ChatWindow *ui;
    QSqlDatabase database;
    QString utilisateur;
    QTimer *rafraichisseur;
};

#endif // CHATWINDOW_H
