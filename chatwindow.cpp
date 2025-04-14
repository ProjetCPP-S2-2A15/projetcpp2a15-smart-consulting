#include "chatwindow.h"
#include "ui_chatwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

ChatWindow::ChatWindow(const QString& pseudo, QSqlDatabase db, QWidget *parent)
    : QDialog(parent), ui(new Ui::ChatWindow), database(db), utilisateur(pseudo)
{
    ui->setupUi(this);
    chargerMessages();

    rafraichisseur = new QTimer(this);
    connect(rafraichisseur, &QTimer::timeout, this, &ChatWindow::chargerMessages);
    rafraichisseur->start(3000);
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::chargerMessages()
{
    QSqlQuery query(database);
    query.exec("SELECT expediteur, contenu, TO_CHAR(date_envoi, 'HH24:MI:SS') FROM MESSAGE ORDER BY date_envoi ASC");

    ui->textEdit_chat->clear();
    while (query.next()) {
        QString heure = query.value(2).toString();
        QString exp = query.value(0).toString();
        QString msg = query.value(1).toString();
        ui->textEdit_chat->append("[" + heure + "] " + exp + ": " + msg);
    }
}

void ChatWindow::on_pushButton_envoyer_clicked()
{
    QString msg = ui->lineEdit_message->text().trimmed();
    if (msg.isEmpty()) return;

    QSqlQuery query(database);
    query.prepare("INSERT INTO MESSAGE (expediteur, contenu) VALUES (:exp, :msg)");
    query.bindValue(":exp", utilisateur);
    query.bindValue(":msg", msg);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Envoi échoué : " + query.lastError().text());
    }

    ui->lineEdit_message->clear();
    chargerMessages();
}
