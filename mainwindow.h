#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "consultantmanager.h"
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setUtilisateurConnecte(const QString &pseudo); // 👈 doit être dans public ou protected

private slots:
    void on_pushButton_9_clicked();  // Ajouter un consultant
    void on_pushButton_10_clicked(); // Modifier un consultant
    void on_pushButton_11_clicked(); // Supprimer un consultant
    void on_pushButton_chat_clicked(); // Chat
    void on_pushButton_3_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_pointage_clicked();
    void on_lineEdit_textChanged(const QString &text);
    void loadConsultants();          // Charger les consultants dans le QTableWidget
    void lireDonneesArduino();

private:
    Ui::MainWindow *ui;
    ConsultantManager *consultantManager;
    QString utilisateurConnecte; // 👈 doit être ici dans private
    QSerialPort *arduino;
    QString serialBuffer;

};

#endif // MAINWINDOW_H
