#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ressource.h"
#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QSystemTrayIcon>
#include "ressource.h"
#include "consultant.h"
#include <QQmlContext>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>



namespace Ui {
class MainWindow;

}

// classe login



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
public:
    // moujib

    void on_lineEdit_textChanged(const QString &text);
    void on_pushButton_3_clicked(); // stat consultant
    void on_pushButton_8_clicked();//pdf consultant
    void on_pushButton_11_clicked();//supprimer un consultant
    void on_pushButton_32_clicked(); // Modifier un consultant
    void modifierConsultant();
    void loadConsultants(); // afficher consultant
    void on_pushButton_9_clicked();  // Ajouter un consultant
    void preparerReinitialisation(const QString &username, const QString &question);
    void on_pushButton_mdp_oublie_clicked();
    bool verifierIdentifiants(const QString &username, const QString &password);
    void on_pushButton_connexion_clicked() ;
    void showPage1();  // Slot pour afficher la page 1 lorsque le bouton est cliqué
    void showPage2();
 void showPage3();    // Slot pour afficher la page 2 lorsque le bouton est cliqué
    void showHomePage(); // retourner a la page d'acceuil d'apres page projet
    void showHomePage2(); // retourner à la page d'acceuil d'apres page ressource
    void showPage5();
    void showHomePage3();
    void showHomePage3_2();
    void showPage33();
    void showPage6();
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
       void on_pushButton_inscrire_clicked();
          void on_pushButton_valider_clicked();
     void lireDonneesArduino();
     void on_pushButton_pointage_clicked();
private:
    Ui::MainWindow *ui;
    Ressource res;
     Consultant *consultant;

 QString utilisateurActuel;
    void checkRFID(const QString &rfid);
    QSerialPort *serial;
    QSystemTrayIcon *trayIcon;

    //arduino moujib anis
    QSerialPort *arduino;
    QString serialBuffer;

};

#endif // MAINWINDOW_H
