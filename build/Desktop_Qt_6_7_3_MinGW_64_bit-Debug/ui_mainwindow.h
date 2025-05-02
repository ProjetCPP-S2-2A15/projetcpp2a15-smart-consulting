/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Page1;
    QGroupBox *groupBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QLabel *label_24;
    QLabel *label;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QLabel *label_27;
    QPushButton *pushButton_25;
    QLabel *label_6;
    QPushButton *pushButton_26;
    QPushButton *pushButton_5;
    QPushButton *importer;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_ajouter_4;
    QPushButton *buttonRechercher;
    QComboBox *comboBox_18;
    QLineEdit *lineEdit_recherche_3;
    QGroupBox *groupBox_3;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *lineEdit_id_2;
    QLineEdit *lineEdit_nom_3;
    QPushButton *pushButton_13;
    QPushButton *pushButton_ajouter_2;
    QLineEdit *lineEdit_description_3;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *lineEdit_statut_;
    QPushButton *pushButton_modifier;
    QPushButton *pushButton_rechercheid;
    QLineEdit *lineEdit_id_3;
    QPushButton *backup;
    QPushButton *pushButton_QR;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_ajouter_3;
    QPushButton *buttonTrier;
    QComboBox *comboBox_10;
    QPushButton *pushButton_afficher;
    QPushButton *pushButton_supprimer;
    QGroupBox *groupBox_6;
    QPushButton *pushButton_ajouter_5;
    QPushButton *pushButton_pdf;
    QPushButton *pushButton_statistiques;
    QTableView *tableView;
    QPushButton *pushButton_9;
    QWidget *Page0;
    QPushButton *pushButton_21;
    QPushButton *pushButton_19;
    QLabel *label_26;
    QPushButton *pushButton_4;
    QPushButton *pushButton_20;
    QLabel *label_5;
    QPushButton *pushButton_22;
    QWidget *Page2;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_7;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_type;
    QPushButton *pushButton_12;
    QPushButton *pushButton_ajouter;
    QLineEdit *lineEdit_nom;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_description;
    QLineEdit *lineEdit_disponibilite;
    QLineEdit *lineEdit_fournisseur;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit_adresse;
    QLabel *label_14;
    QLineEdit *lineEdit_phone;
    QLabel *label_4;
    QTableView *tableView_2;
    QLineEdit *lineEdit_id_4;
    QPushButton *pushButton_supprimer_2;
    QGroupBox *groupBox_15;
    QPushButton *pushButton_rechercheid_2;
    QGroupBox *groupBox_8;
    QPushButton *buttonTrier_2;
    QComboBox *comboBox_188;
    QGroupBox *groupBox_9;
    QPushButton *buttonRechercher_2;
    QComboBox *comboBox_19;
    QLineEdit *lineEdit_recherche_4;
    QPushButton *pushButton_modifier_2;
    QLabel *label_19;
    QPushButton *pushButton_afficher_2;
    QPushButton *pushButton_rechercheid_3;
    QGroupBox *groupBox_10;
    QPushButton *pushButton_statistiques_2;
    QPushButton *pushButton_pdf_2;
    QPushButton *pushButton_modifier_3;
    QComboBox *comboBox;
    QLineEdit *lineEdit_id_5;
    QPushButton *pushButton_10;
    QMenuBar *menubar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1380, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 10, 1581, 811));
        Page1 = new QWidget();
        Page1->setObjectName("Page1");
        groupBox = new QGroupBox(Page1);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 40, 131, 471));
        groupBox->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral du QGroupBox */\n"
"QGroupBox {\n"
"    border: none; /* Supprime le cadre du groupe */\n"
"    background-color: transparent; /* Fond transparent */\n"
"}\n"
"\n"
"/* Style des boutons */\n"
"QPushButton {\n"
"    background-color: transparent; /* Fond transparent par d\303\251faut */\n"
"    color: white; /* Texte blanc */\n"
"    border: none;\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    min-width: 120px; /* Largeur minimale du bouton */\n"
"    min-height: 40px; /* Hauteur minimale du bouton */\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); /* L\303\251ger fond blanc transparent au survol */\n"
"}\n"
"\n"
"/* Effet quand le bouton est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: white; /* Fond blanc */\n"
"    color: black; /* Texte noir */\n"
"}\n"
"\n"
"/* Quand le bouton est coch\303\251, il reste en blanc */\n"
"QPushButton:checked {\n"
"    background-color: white; /* Fon"
                        "d blanc apr\303\250s clic */\n"
"    color: black; /* Texte noir apr\303\250s clic */\n"
"}\n"
"\n"
"/* Style du QLabel */\n"
"QLabel {\n"
"    color: white; /* Texte en blanc */\n"
"    font-family: Arial, sans-serif; /* Police Arial */\n"
"    font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    padding: 5px; /* Espace autour du texte */\n"
"}\n"
""));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 80, 142, 62));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"\n"
"    color: black;  /* D\303\251finir la couleur du texte en noir */\n"
"    border: 1px solid black;  /* Optionnel : pour ajouter une bordure noire */\n"
"}\n"
""));
        pushButton_15 = new QPushButton(groupBox);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(0, 170, 140, 60));
        pushButton_16 = new QPushButton(groupBox);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(0, 240, 140, 60));
        pushButton_17 = new QPushButton(groupBox);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(0, 300, 140, 60));
        pushButton_18 = new QPushButton(groupBox);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(0, 360, 140, 60));
        label_24 = new QLabel(groupBox);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(10, 0, 141, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setBold(true);
        label_24->setFont(font);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -20, 151, 571));
        label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(34, 32, 82, 255), stop:1 rgba(0, 0, 0, 255));\n"
"border-radius: 10px;"));
        pushButton_23 = new QPushButton(groupBox);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(-10, 310, 140, 60));
        pushButton_24 = new QPushButton(groupBox);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(-10, 160, 140, 60));
        label_27 = new QLabel(groupBox);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(10, 50, 141, 31));
        label_27->setFont(font);
        pushButton_25 = new QPushButton(groupBox);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setGeometry(QRect(-10, 230, 140, 60));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(200, 90, 881, 61));
        label_6->setStyleSheet(QString::fromUtf8("/* Style avec fond blanc, bords arrondis et ombre tr\303\250s sombre */\n"
"QWidget {\n"
"    background-color: rgba(255, 255, 255, 255); /* Fond blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    box-shadow: 0px 8px 16px rgba(0, 0, 0, 0.8); /* Ombre tr\303\250s sombre et plus marqu\303\251e */\n"
"}\n"
""));
        pushButton_26 = new QPushButton(groupBox);
        pushButton_26->setObjectName("pushButton_26");
        pushButton_26->setGeometry(QRect(0, 390, 140, 60));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(0, 90, 142, 62));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"\n"
"    color: black;  /* D\303\251finir la couleur du texte en noir */\n"
"    border: 1px solid black;  /* Optionnel : pour ajouter une bordure noire */\n"
"}\n"
""));
        importer = new QPushButton(Page1);
        importer->setObjectName("importer");
        importer->setGeometry(QRect(980, 450, 93, 29));
        groupBox_5 = new QGroupBox(Page1);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(700, 60, 181, 131));
        groupBox_5->setStyleSheet(QString::fromUtf8("/* Style pour le QGroupBox avec la couleur #e8ded7 */\n"
"QGroupBox {\n"
"    background-color: #e8ded7; /* Couleur beige clair */\n"
"    border: 1px solid #d1c6b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px; /* Espacement interne */\n"
"}\n"
""));
        groupBox_5->setFlat(true);
        groupBox_5->setCheckable(false);
        pushButton_ajouter_4 = new QPushButton(groupBox_5);
        pushButton_ajouter_4->setObjectName("pushButton_ajouter_4");
        pushButton_ajouter_4->setGeometry(QRect(70, 140, 75, 24));
        pushButton_ajouter_4->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        buttonRechercher = new QPushButton(groupBox_5);
        buttonRechercher->setObjectName("buttonRechercher");
        buttonRechercher->setGeometry(QRect(50, 90, 91, 31));
        buttonRechercher->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        comboBox_18 = new QComboBox(groupBox_5);
        comboBox_18->addItem(QString());
        comboBox_18->addItem(QString());
        comboBox_18->addItem(QString());
        comboBox_18->setObjectName("comboBox_18");
        comboBox_18->setGeometry(QRect(20, 50, 141, 31));
        lineEdit_recherche_3 = new QLineEdit(groupBox_5);
        lineEdit_recherche_3->setObjectName("lineEdit_recherche_3");
        lineEdit_recherche_3->setGeometry(QRect(30, 20, 113, 22));
        groupBox_3 = new QGroupBox(Page1);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(190, 90, 241, 351));
        groupBox_3->setStyleSheet(QString::fromUtf8("/* Style pour le QGroupBox avec la couleur #e8ded7 */\n"
"QGroupBox {\n"
"    background-color: #e8ded7; /* Couleur beige clair */\n"
"    border: 1px solid #d1c6b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px; /* Espacement interne */\n"
"}\n"
""));
        groupBox_3->setFlat(true);
        groupBox_3->setCheckable(false);
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 30, 121, 20));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 160, 49, 16));
        lineEdit_id_2 = new QLineEdit(groupBox_3);
        lineEdit_id_2->setObjectName("lineEdit_id_2");
        lineEdit_id_2->setGeometry(QRect(100, 30, 113, 22));
        lineEdit_nom_3 = new QLineEdit(groupBox_3);
        lineEdit_nom_3->setObjectName("lineEdit_nom_3");
        lineEdit_nom_3->setGeometry(QRect(100, 70, 113, 22));
        pushButton_13 = new QPushButton(groupBox_3);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(110, 230, 81, 41));
        pushButton_13->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        pushButton_ajouter_2 = new QPushButton(groupBox_3);
        pushButton_ajouter_2->setObjectName("pushButton_ajouter_2");
        pushButton_ajouter_2->setGeometry(QRect(10, 230, 81, 41));
        pushButton_ajouter_2->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        lineEdit_description_3 = new QLineEdit(groupBox_3);
        lineEdit_description_3->setObjectName("lineEdit_description_3");
        lineEdit_description_3->setGeometry(QRect(100, 120, 113, 22));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 70, 91, 16));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(10, 120, 91, 16));
        lineEdit_statut_ = new QLineEdit(groupBox_3);
        lineEdit_statut_->setObjectName("lineEdit_statut_");
        lineEdit_statut_->setGeometry(QRect(100, 160, 113, 22));
        pushButton_modifier = new QPushButton(Page1);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(830, 493, 81, 31));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        pushButton_rechercheid = new QPushButton(Page1);
        pushButton_rechercheid->setObjectName("pushButton_rechercheid");
        pushButton_rechercheid->setGeometry(QRect(680, 493, 91, 31));
        pushButton_rechercheid->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        lineEdit_id_3 = new QLineEdit(Page1);
        lineEdit_id_3->setObjectName("lineEdit_id_3");
        lineEdit_id_3->setGeometry(QRect(530, 500, 113, 22));
        backup = new QPushButton(Page1);
        backup->setObjectName("backup");
        backup->setGeometry(QRect(980, 500, 93, 29));
        pushButton_QR = new QPushButton(Page1);
        pushButton_QR->setObjectName("pushButton_QR");
        pushButton_QR->setGeometry(QRect(980, 410, 93, 29));
        groupBox_4 = new QGroupBox(Page1);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(480, 60, 181, 131));
        groupBox_4->setStyleSheet(QString::fromUtf8("/* Style pour le QGroupBox avec la couleur #e8ded7 */\n"
"QGroupBox {\n"
"    background-color: #e8ded7; /* Couleur beige clair */\n"
"    border: 1px solid #d1c6b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px; /* Espacement interne */\n"
"}\n"
""));
        groupBox_4->setFlat(true);
        groupBox_4->setCheckable(false);
        pushButton_ajouter_3 = new QPushButton(groupBox_4);
        pushButton_ajouter_3->setObjectName("pushButton_ajouter_3");
        pushButton_ajouter_3->setGeometry(QRect(70, 140, 75, 24));
        pushButton_ajouter_3->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        buttonTrier = new QPushButton(groupBox_4);
        buttonTrier->setObjectName("buttonTrier");
        buttonTrier->setGeometry(QRect(50, 90, 81, 31));
        buttonTrier->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        comboBox_10 = new QComboBox(groupBox_4);
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->setObjectName("comboBox_10");
        comboBox_10->setGeometry(QRect(20, 40, 141, 41));
        pushButton_afficher = new QPushButton(Page1);
        pushButton_afficher->setObjectName("pushButton_afficher");
        pushButton_afficher->setGeometry(QRect(770, 443, 81, 31));
        pushButton_afficher->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        pushButton_supprimer = new QPushButton(Page1);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(500, 443, 91, 31));
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        groupBox_6 = new QGroupBox(Page1);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(900, 60, 181, 131));
        groupBox_6->setStyleSheet(QString::fromUtf8("/* Style pour le QGroupBox avec la couleur #e8ded7 */\n"
"QGroupBox {\n"
"    background-color: #e8ded7; /* Couleur beige clair */\n"
"    border: 1px solid #d1c6b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px; /* Espacement interne */\n"
"}\n"
""));
        groupBox_6->setFlat(true);
        groupBox_6->setCheckable(false);
        pushButton_ajouter_5 = new QPushButton(groupBox_6);
        pushButton_ajouter_5->setObjectName("pushButton_ajouter_5");
        pushButton_ajouter_5->setGeometry(QRect(70, 140, 75, 24));
        pushButton_ajouter_5->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        pushButton_pdf = new QPushButton(groupBox_6);
        pushButton_pdf->setObjectName("pushButton_pdf");
        pushButton_pdf->setGeometry(QRect(40, 30, 101, 31));
        pushButton_pdf->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        pushButton_statistiques = new QPushButton(groupBox_6);
        pushButton_statistiques->setObjectName("pushButton_statistiques");
        pushButton_statistiques->setGeometry(QRect(40, 90, 101, 31));
        pushButton_statistiques->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        tableView = new QTableView(Page1);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(470, 200, 641, 192));
        pushButton_9 = new QPushButton(Page1);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(20, 0, 131, 31));
        stackedWidget->addWidget(Page1);
        Page0 = new QWidget();
        Page0->setObjectName("Page0");
        pushButton_21 = new QPushButton(Page0);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(30, 340, 140, 60));
        pushButton_19 = new QPushButton(Page0);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(30, 180, 140, 60));
        label_26 = new QLabel(Page0);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(30, 50, 141, 31));
        label_26->setFont(font);
        pushButton_4 = new QPushButton(Page0);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(30, 100, 142, 62));
        pushButton_4->setStyleSheet(QString::fromUtf8(""));
        pushButton_20 = new QPushButton(Page0);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(30, 260, 140, 60));
        label_5 = new QLabel(Page0);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(190, 60, 881, 61));
        label_5->setStyleSheet(QString::fromUtf8("/* Style avec fond blanc, bords arrondis et ombre tr\303\250s sombre */\n"
"QWidget {\n"
"    background-color: rgba(255, 255, 255, 255); /* Fond blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    box-shadow: 0px 8px 16px rgba(0, 0, 0, 0.8); /* Ombre tr\303\250s sombre et plus marqu\303\251e */\n"
"}\n"
""));
        pushButton_22 = new QPushButton(Page0);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(30, 410, 140, 60));
        stackedWidget->addWidget(Page0);
        Page2 = new QWidget();
        Page2->setObjectName("Page2");
        groupBox_2 = new QGroupBox(Page2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(30, 80, 131, 471));
        groupBox_2->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral du QGroupBox */\n"
"QGroupBox {\n"
"    border: none; /* Supprime le cadre du groupe */\n"
"    background-color: transparent; /* Fond transparent */\n"
"}\n"
"\n"
"/* Style des boutons */\n"
"QPushButton {\n"
"    background-color: transparent; /* Fond transparent par d\303\251faut */\n"
"    color: white; /* Texte blanc */\n"
"    border: none;\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    min-width: 120px; /* Largeur minimale du bouton */\n"
"    min-height: 40px; /* Hauteur minimale du bouton */\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); /* L\303\251ger fond blanc transparent au survol */\n"
"}\n"
"\n"
"/* Effet quand le bouton est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: white; /* Fond blanc */\n"
"    color: black; /* Texte noir */\n"
"}\n"
"\n"
"/* Quand le bouton est coch\303\251, il reste en blanc */\n"
"QPushButton:checked {\n"
"    background-color: white; /* Fon"
                        "d blanc apr\303\250s clic */\n"
"    color: black; /* Texte noir apr\303\250s clic */\n"
"}\n"
"\n"
"/* Style du QLabel */\n"
"QLabel {\n"
"    color: white; /* Texte en blanc */\n"
"    font-family: Arial, sans-serif; /* Police Arial */\n"
"    font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    padding: 5px; /* Espace autour du texte */\n"
"}\n"
""));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(-10, 0, 151, 571));
        label_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(34, 32, 82, 255), stop:1 rgba(0, 0, 0, 255));\n"
"border-radius: 10px;"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 10, 211, 51));
        label_3->setFont(font);
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(-10, 130, 142, 62));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"\n"
"    color: black;  /* D\303\251finir la couleur du texte en noir */\n"
"    border: 1px solid black;  /* Optionnel : pour ajouter une bordure noire */\n"
"}\n"
""));
        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(-20, 220, 140, 60));
        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(-20, 300, 140, 60));
        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(-20, 60, 140, 61));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(-10, 380, 140, 60));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        pushButton_2->setPalette(palette);
        groupBox_7 = new QGroupBox(Page2);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(190, 200, 241, 361));
        groupBox_7->setStyleSheet(QString::fromUtf8("/* Style pour le QGroupBox avec la couleur #e8ded7 */\n"
"QGroupBox {\n"
"    background-color: #e8ded7; /* Couleur beige clair */\n"
"    border: 1px solid #d1c6b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px; /* Espacement interne */\n"
"}\n"
""));
        groupBox_7->setFlat(true);
        groupBox_7->setCheckable(false);
        label_7 = new QLabel(groupBox_7);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 30, 121, 20));
        label_8 = new QLabel(groupBox_7);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 70, 49, 16));
        lineEdit_id = new QLineEdit(groupBox_7);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(100, 30, 113, 22));
        lineEdit_type = new QLineEdit(groupBox_7);
        lineEdit_type->setObjectName("lineEdit_type");
        lineEdit_type->setGeometry(QRect(100, 70, 113, 22));
        pushButton_12 = new QPushButton(groupBox_7);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(130, 320, 81, 31));
        pushButton_12->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        pushButton_ajouter = new QPushButton(groupBox_7);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(20, 320, 71, 31));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        lineEdit_nom = new QLineEdit(groupBox_7);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(100, 120, 113, 22));
        label_9 = new QLabel(groupBox_7);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 120, 91, 16));
        label_10 = new QLabel(groupBox_7);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 160, 91, 16));
        label_11 = new QLabel(groupBox_7);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 200, 121, 16));
        lineEdit_description = new QLineEdit(groupBox_7);
        lineEdit_description->setObjectName("lineEdit_description");
        lineEdit_description->setGeometry(QRect(100, 160, 113, 22));
        lineEdit_disponibilite = new QLineEdit(groupBox_7);
        lineEdit_disponibilite->setObjectName("lineEdit_disponibilite");
        lineEdit_disponibilite->setGeometry(QRect(110, 200, 113, 22));
        lineEdit_fournisseur = new QLineEdit(groupBox_7);
        lineEdit_fournisseur->setObjectName("lineEdit_fournisseur");
        lineEdit_fournisseur->setGeometry(QRect(110, 230, 113, 22));
        label_12 = new QLabel(groupBox_7);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 230, 121, 16));
        label_13 = new QLabel(groupBox_7);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 260, 121, 16));
        lineEdit_adresse = new QLineEdit(groupBox_7);
        lineEdit_adresse->setObjectName("lineEdit_adresse");
        lineEdit_adresse->setGeometry(QRect(110, 260, 113, 22));
        label_14 = new QLabel(groupBox_7);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 290, 121, 16));
        lineEdit_phone = new QLineEdit(groupBox_7);
        lineEdit_phone->setObjectName("lineEdit_phone");
        lineEdit_phone->setGeometry(QRect(110, 290, 113, 22));
        label_4 = new QLabel(Page2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 60, 881, 16));
        label_4->setStyleSheet(QString::fromUtf8("/* Style avec fond blanc, bords arrondis et ombre tr\303\250s sombre */\n"
"QWidget {\n"
"    background-color: rgba(255, 255, 255, 255); /* Fond blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    box-shadow: 0px 8px 16px rgba(0, 0, 0, 0.8); /* Ombre tr\303\250s sombre et plus marqu\303\251e */\n"
"}\n"
""));
        tableView_2 = new QTableView(Page2);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(470, 250, 641, 192));
        lineEdit_id_4 = new QLineEdit(Page2);
        lineEdit_id_4->setObjectName("lineEdit_id_4");
        lineEdit_id_4->setGeometry(QRect(670, 700, 113, 22));
        pushButton_supprimer_2 = new QPushButton(Page2);
        pushButton_supprimer_2->setObjectName("pushButton_supprimer_2");
        pushButton_supprimer_2->setGeometry(QRect(500, 493, 101, 31));
        pushButton_supprimer_2->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        groupBox_15 = new QGroupBox(Page2);
        groupBox_15->setObjectName("groupBox_15");
        groupBox_15->setGeometry(QRect(880, 450, 831, 81));
        groupBox_15->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral pour le QGroupBox */\n"
"QGroupBox {\n"
"    background-color: transparent;  /* Fond transparent */\n"
"    border: 1px solid transparent;  /* Bordure transparente */\n"
"    border-radius: 10px;            /* Coins arrondis */\n"
"    padding: 10px;                  /* Espacement interne */\n"
"}\n"
"\n"
"/* Style pour le QPushButton */\n"
"QPushButton {\n"
"    background-color: #ebb620; /* Jaune dor\303\251 */\n"
"    color: rgba(0, 0, 0, 220); /* Texte noir avec l\303\251g\303\250re transparence */\n"
"    border-radius: 5px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #d9a519; /* Jaune dor\303\251 plus fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: #b68d17; /* Jaune dor\303\251 encore plus fonc\303\251 lors du clic */\n"
"}\n"
"\n"
"/* Style pour le QLineEdit */\n"
"QLineEdit {\n"
"    background-color: rgba(255, 255, 255, 255);\n"
"    b"
                        "order: 2px solid rgba(0, 0, 0, 0);\n"
"    border-bottom-color: #ebb620; /* Bordure inf\303\251rieure jaune dor\303\251 */\n"
"    color: rgb(0, 0, 0);\n"
"    padding-bottom: 7px;\n"
"}\n"
""));
        pushButton_rechercheid_2 = new QPushButton(Page2);
        pushButton_rechercheid_2->setObjectName("pushButton_rechercheid_2");
        pushButton_rechercheid_2->setGeometry(QRect(680, 550, 91, 24));
        pushButton_rechercheid_2->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        groupBox_8 = new QGroupBox(Page2);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setGeometry(QRect(470, 110, 181, 131));
        groupBox_8->setStyleSheet(QString::fromUtf8("/* Style pour le QGroupBox avec la couleur #e8ded7 */\n"
"QGroupBox {\n"
"    background-color: #e8ded7; /* Couleur beige clair */\n"
"    border: 1px solid #d1c6b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px; /* Espacement interne */\n"
"}\n"
""));
        groupBox_8->setFlat(true);
        groupBox_8->setCheckable(false);
        buttonTrier_2 = new QPushButton(groupBox_8);
        buttonTrier_2->setObjectName("buttonTrier_2");
        buttonTrier_2->setGeometry(QRect(40, 80, 101, 41));
        buttonTrier_2->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        comboBox_188 = new QComboBox(groupBox_8);
        comboBox_188->addItem(QString());
        comboBox_188->addItem(QString());
        comboBox_188->addItem(QString());
        comboBox_188->addItem(QString());
        comboBox_188->addItem(QString());
        comboBox_188->addItem(QString());
        comboBox_188->addItem(QString());
        comboBox_188->setObjectName("comboBox_188");
        comboBox_188->setGeometry(QRect(10, 30, 161, 41));
        groupBox_9 = new QGroupBox(Page2);
        groupBox_9->setObjectName("groupBox_9");
        groupBox_9->setGeometry(QRect(690, 110, 181, 131));
        groupBox_9->setStyleSheet(QString::fromUtf8("/* Style pour le QGroupBox avec la couleur #e8ded7 */\n"
"QGroupBox {\n"
"    background-color: #e8ded7; /* Couleur beige clair */\n"
"    border: 1px solid #d1c6b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px; /* Espacement interne */\n"
"}\n"
""));
        groupBox_9->setFlat(true);
        groupBox_9->setCheckable(false);
        buttonRechercher_2 = new QPushButton(groupBox_9);
        buttonRechercher_2->setObjectName("buttonRechercher_2");
        buttonRechercher_2->setGeometry(QRect(40, 80, 101, 41));
        buttonRechercher_2->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        comboBox_19 = new QComboBox(groupBox_9);
        comboBox_19->addItem(QString());
        comboBox_19->addItem(QString());
        comboBox_19->addItem(QString());
        comboBox_19->addItem(QString());
        comboBox_19->addItem(QString());
        comboBox_19->setObjectName("comboBox_19");
        comboBox_19->setGeometry(QRect(10, 51, 151, 20));
        lineEdit_recherche_4 = new QLineEdit(groupBox_9);
        lineEdit_recherche_4->setObjectName("lineEdit_recherche_4");
        lineEdit_recherche_4->setGeometry(QRect(30, 20, 113, 22));
        pushButton_modifier_2 = new QPushButton(Page2);
        pushButton_modifier_2->setObjectName("pushButton_modifier_2");
        pushButton_modifier_2->setGeometry(QRect(970, 700, 75, 24));
        pushButton_modifier_2->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        label_19 = new QLabel(Page2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(560, 80, 131, 31));
        QFont font1;
        font1.setBold(true);
        label_19->setFont(font1);
        pushButton_afficher_2 = new QPushButton(Page2);
        pushButton_afficher_2->setObjectName("pushButton_afficher_2");
        pushButton_afficher_2->setGeometry(QRect(754, 493, 91, 31));
        pushButton_afficher_2->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        pushButton_rechercheid_3 = new QPushButton(Page2);
        pushButton_rechercheid_3->setObjectName("pushButton_rechercheid_3");
        pushButton_rechercheid_3->setGeometry(QRect(820, 700, 91, 24));
        pushButton_rechercheid_3->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        groupBox_10 = new QGroupBox(Page2);
        groupBox_10->setObjectName("groupBox_10");
        groupBox_10->setGeometry(QRect(930, 110, 181, 131));
        groupBox_10->setStyleSheet(QString::fromUtf8("/* Style pour le QGroupBox avec la couleur #e8ded7 */\n"
"QGroupBox {\n"
"    background-color: #e8ded7; /* Couleur beige clair */\n"
"    border: 1px solid #d1c6b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px; /* Espacement interne */\n"
"}\n"
""));
        groupBox_10->setFlat(true);
        groupBox_10->setCheckable(false);
        pushButton_statistiques_2 = new QPushButton(groupBox_10);
        pushButton_statistiques_2->setObjectName("pushButton_statistiques_2");
        pushButton_statistiques_2->setGeometry(QRect(40, 80, 101, 41));
        pushButton_statistiques_2->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        pushButton_pdf_2 = new QPushButton(groupBox_10);
        pushButton_pdf_2->setObjectName("pushButton_pdf_2");
        pushButton_pdf_2->setGeometry(QRect(40, 30, 101, 41));
        pushButton_pdf_2->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        pushButton_modifier_3 = new QPushButton(Page2);
        pushButton_modifier_3->setObjectName("pushButton_modifier_3");
        pushButton_modifier_3->setGeometry(QRect(830, 550, 75, 24));
        pushButton_modifier_3->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
"QPushButton {\n"
"    background-color: #dbaf8e; /* Couleur beige clair */\n"
"   color: #000; /* Texte blanc */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"     border: 1px  solid #c68c61; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style au survol */\n"
"QPushButton:hover {\n"
"    background-color: #d49f74; /* Couleur plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style lorsqu'il est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #c68c61; /* Couleur encore plus fonc\303\251e au clic */\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"}\n"
""));
        comboBox = new QComboBox(Page2);
        comboBox->addItem(QString::fromUtf8("statistiques"));
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(180, 80, 151, 31));
        QFont font2;
        font2.setBold(false);
        comboBox->setFont(font2);
        comboBox->setStyleSheet(QString::fromUtf8("/* Style simplifi\303\251 pour le QComboBox */\n"
"QComboBox {\n"
"    background-color: #ebb620; /* Jaune dor\303\251 */\n"
"    \n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QComboBox:hover {\n"
"    background-color: #d9a519; /* Jaune dor\303\251 plus fonc\303\251 */\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"QComboBox:pressed, QComboBox:on {\n"
"    background-color: #b68d17; /* Jaune fonc\303\251 */\n"
"}\n"
"\n"
"/* Style du menu d\303\251roulant */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ebb620; /* Fond dor\303\251 */\n"
"    color: #000; /* Texte noir */\n"
"    selection-background-color: #b68d17; /* Fond dor\303\251 fonc\303\251 lors de la s\303\251lection */\n"
"}\n"
""));
        comboBox->setInsertPolicy(QComboBox::InsertPolicy::InsertAtBottom);
        comboBox->setDuplicatesEnabled(false);
        lineEdit_id_5 = new QLineEdit(Page2);
        lineEdit_id_5->setObjectName("lineEdit_id_5");
        lineEdit_id_5->setGeometry(QRect(530, 550, 113, 22));
        pushButton_10 = new QPushButton(Page2);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(30, 30, 131, 41));
        stackedWidget->addWidget(Page2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1380, 22));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName("toolBar_2");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Projet", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Ressource", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "T\303\242che", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Consultant", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        label->setText(QString());
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "Ressource", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        pushButton_25->setText(QCoreApplication::translate("MainWindow", "T\303\242che", nullptr));
        label_6->setText(QString());
        pushButton_26->setText(QCoreApplication::translate("MainWindow", "Consultant", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Projet", nullptr));
        importer->setText(QCoreApplication::translate("MainWindow", "IMPORT", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        pushButton_ajouter_4->setText(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        buttonRechercher->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        comboBox_18->setItemText(0, QCoreApplication::translate("MainWindow", "Rechercher_par_ID", nullptr));
        comboBox_18->setItemText(1, QCoreApplication::translate("MainWindow", "Rechercher_par_Nom", nullptr));
        comboBox_18->setItemText(2, QCoreApplication::translate("MainWindow", "Rechercher_par_Statut", nullptr));

        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "id_projet ", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "statut ", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        pushButton_ajouter_2->setText(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "nom ", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "description  ", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        pushButton_rechercheid->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        backup->setText(QCoreApplication::translate("MainWindow", "BACK UP", nullptr));
        pushButton_QR->setText(QCoreApplication::translate("MainWindow", "QR", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        pushButton_ajouter_3->setText(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        buttonTrier->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        comboBox_10->setItemText(0, QCoreApplication::translate("MainWindow", "Trier_par_ID", nullptr));
        comboBox_10->setItemText(1, QCoreApplication::translate("MainWindow", "Trier_par_Nom", nullptr));
        comboBox_10->setItemText(2, QCoreApplication::translate("MainWindow", "Trier_par_Description", nullptr));
        comboBox_10->setItemText(3, QCoreApplication::translate("MainWindow", "Trier_par_Statut", nullptr));

        pushButton_afficher->setText(QCoreApplication::translate("MainWindow", "afficher", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "PDF & Statistiques", nullptr));
        pushButton_ajouter_5->setText(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        pushButton_pdf->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        pushButton_statistiques->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "RETOUR", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "Ressource", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Projet", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "T\303\242che", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "ADVISORA", nullptr));
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "Consultant", nullptr));
        groupBox_2->setTitle(QString());
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Ressource", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "T\303\242che", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Projet", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "consultant", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "id_ressource ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "type ", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "nom ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "description  ", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "disponibilite ", nullptr));
        lineEdit_fournisseur->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "fournisseur ", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "adresse ", nullptr));
        lineEdit_adresse->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "phone ", nullptr));
        lineEdit_phone->setText(QString());
        label_4->setText(QString());
        pushButton_supprimer_2->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        groupBox_15->setTitle(QString());
        pushButton_rechercheid_2->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        buttonTrier_2->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        comboBox_188->setItemText(0, QCoreApplication::translate("MainWindow", "Trier_par_ID", nullptr));
        comboBox_188->setItemText(1, QCoreApplication::translate("MainWindow", "Trier_par_Nom", nullptr));
        comboBox_188->setItemText(2, QCoreApplication::translate("MainWindow", "Trier_par_Type", nullptr));
        comboBox_188->setItemText(3, QCoreApplication::translate("MainWindow", "Trier_par_Disponibilite", nullptr));
        comboBox_188->setItemText(4, QCoreApplication::translate("MainWindow", "Trier_par_Fournisseur", nullptr));
        comboBox_188->setItemText(5, QCoreApplication::translate("MainWindow", "Trier_par_Adresse", nullptr));
        comboBox_188->setItemText(6, QCoreApplication::translate("MainWindow", "Trier_par_Phone", nullptr));

        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        buttonRechercher_2->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        comboBox_19->setItemText(0, QCoreApplication::translate("MainWindow", "Rechercher_par_ID", nullptr));
        comboBox_19->setItemText(1, QCoreApplication::translate("MainWindow", "Rechercher_par_Nom", nullptr));
        comboBox_19->setItemText(2, QCoreApplication::translate("MainWindow", "Rechercher_par_Type", nullptr));
        comboBox_19->setItemText(3, QCoreApplication::translate("MainWindow", "Rechercher_par_Disponibilite", nullptr));
        comboBox_19->setItemText(4, QCoreApplication::translate("MainWindow", "Rechercher_par_Fournisseur", nullptr));

        pushButton_modifier_2->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "ADVISORS", nullptr));
        pushButton_afficher_2->setText(QCoreApplication::translate("MainWindow", "afficher", nullptr));
        pushButton_rechercheid_3->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("MainWindow", "PDF & Statistiques", nullptr));
        pushButton_statistiques_2->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        pushButton_pdf_2->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        pushButton_modifier_3->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Nouvel \303\251l\303\251ment", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Nouvel \303\251l\303\251ment", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Nouvel \303\251l\303\251ment", nullptr));

        comboBox->setPlaceholderText(QString());
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "RETOUR", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
