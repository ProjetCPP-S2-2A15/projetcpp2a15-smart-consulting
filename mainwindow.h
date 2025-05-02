#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ressource.h"
#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QSystemTrayIcon>
#include "ressource.h"

#include <QQmlContext>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showPage1();  // Slot pour afficher la page 1 lorsque le bouton est cliqué
    void showPage2();    // Slot pour afficher la page 2 lorsque le bouton est cliqué
    void showHomePage(); // retourner a la page d'acceuil d'apres page projet
    void showHomePage2(); // retourner à la page d'acceuil d'apres page ressource
     void on_pushButton_ajouter_2_clicked();
    void on_pushButton_ajouter_clicked();
     void on_pushButton_afficher_clicked();
    void on_pushButton_supprimer_clicked();
     void on_pushButton_modifier_clicked();
    void on_pushButton_afficher_clicked2();
      void on_pushButton_modifier_clicked2();
    void on_pushButton_supprimer_clicked2();
      void on_buttonRechercher_clicked();
    void on_buttonTrier_clicked();
       void on_pushButton_statistiques_clicked();
    void on_pushButton_pdf_clicked();
       void on_pushButton_pdf_clicked2();
       void on_buttonRechercher_clicked2();
       void on_buttonTrier_clicked2();
       void on_pushButton_statistiques_clicked2();
        void on_pushButton_QR_clicked();
          void readSerial();

private:
    Ui::MainWindow *ui;
    Ressource res;


    void checkRFID(const QString &rfid);
    QSerialPort *serial;
    QSystemTrayIcon *trayIcon;

};

#endif // MAINWINDOW_H
