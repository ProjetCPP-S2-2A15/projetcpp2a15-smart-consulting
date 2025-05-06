#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mailing.h"
#include "ressource.h"
#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QSystemTrayIcon>
<<<<<<< HEAD
#include "ressource.h"
=======
#include "client.h"
>>>>>>> c2b1c55 (gestion ressource projet consultant)
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
<<<<<<< HEAD
    void showPage1();  // Slot pour afficher la page 1 lorsque le bouton est cliqué
    void showPage2();
 void showPage3();    // Slot pour afficher la page 2 lorsque le bouton est cliqué
=======
    //client
    void showPage7();
    void showHomePage3_3();
    void ajouter_client();
    void supprimer_client();
    void modifier_client();
    void rechercher_client();
    void pdf_client();
    void trier_client();
    void mailing_client();
    void stat_client();
    //
    void showPage1();  // Slot pour afficher la page 1 lorsque le bouton est cliqué
    void showPage2();
    void showPage3();    // Slot pour afficher la page 2 lorsque le bouton est cliqué
>>>>>>> c2b1c55 (gestion ressource projet consultant)
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
<<<<<<< HEAD
=======
     void readArduinoData();
>>>>>>> c2b1c55 (gestion ressource projet consultant)
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

<<<<<<< HEAD
=======
    //arduino scott
    QSerialPort *serialPort; // Déclaration du port série


    void setupSerialConnection(); // Fonction pour configurer le port série

>>>>>>> c2b1c55 (gestion ressource projet consultant)
};


#endif // MAINWINDOW_H
