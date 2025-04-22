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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
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
    QPushButton *pushButton_afficher;
    QPushButton *pushButton_rechercheid;
    QTableView *tableView;
    QPushButton *pushButton_supprimer;
    QLabel *label_4;
    QLabel *label;
    QPushButton *pushButton_modifier;
    QLineEdit *lineEdit_id_3;
    QLabel *label_5;
    QComboBox *comboBox;
    QGroupBox *groupBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QLabel *label_24;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_ajouter_3;
    QPushButton *buttonTrier;
    QComboBox *comboBox_10;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_ajouter_4;
    QPushButton *buttonRechercher;
    QComboBox *comboBox_18;
    QLineEdit *lineEdit_recherche_3;
    QGroupBox *groupBox_6;
    QPushButton *pushButton_ajouter_5;
    QPushButton *pushButton_pdf;
    QPushButton *pushButton_statistiques;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1250, 674);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(180, 140, 241, 351));
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
        pushButton_afficher = new QPushButton(centralwidget);
        pushButton_afficher->setObjectName("pushButton_afficher");
        pushButton_afficher->setGeometry(QRect(760, 433, 81, 31));
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
        pushButton_rechercheid = new QPushButton(centralwidget);
        pushButton_rechercheid->setObjectName("pushButton_rechercheid");
        pushButton_rechercheid->setGeometry(QRect(670, 483, 91, 31));
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
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(460, 190, 641, 192));
        pushButton_supprimer = new QPushButton(centralwidget);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(490, 433, 91, 31));
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
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 0, 881, 61));
        label_4->setStyleSheet(QString::fromUtf8("/* Style avec fond blanc, bords arrondis et ombre tr\303\250s sombre */\n"
"QWidget {\n"
"    background-color: rgba(255, 255, 255, 255); /* Fond blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    box-shadow: 0px 8px 16px rgba(0, 0, 0, 0.8); /* Ombre tr\303\250s sombre et plus marqu\303\251e */\n"
"}\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 151, 571));
        label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(34, 32, 82, 255), stop:1 rgba(0, 0, 0, 255));\n"
"border-radius: 10px;"));
        pushButton_modifier = new QPushButton(centralwidget);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(820, 483, 81, 31));
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
        lineEdit_id_3 = new QLineEdit(centralwidget);
        lineEdit_id_3->setObjectName("lineEdit_id_3");
        lineEdit_id_3->setGeometry(QRect(520, 490, 113, 22));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(550, 20, 131, 31));
        QFont font;
        font.setBold(true);
        label_5->setFont(font);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString::fromUtf8("statistiques"));
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(170, 20, 151, 31));
        QFont font1;
        font1.setBold(false);
        comboBox->setFont(font1);
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
        comboBox->setInsertPolicy(QComboBox::InsertPolicy::NoInsert);
        comboBox->setDuplicatesEnabled(false);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 20, 131, 471));
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
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setBold(true);
        label_24->setFont(font2);
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(470, 50, 181, 131));
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
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(690, 50, 181, 131));
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
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(890, 50, 181, 131));
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
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1250, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "id_projet ", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "statut ", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        pushButton_ajouter_2->setText(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "nom ", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "description  ", nullptr));
        pushButton_afficher->setText(QCoreApplication::translate("MainWindow", "afficher", nullptr));
        pushButton_rechercheid->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        label_4->setText(QString());
        label->setText(QString());
        pushButton_modifier->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "ADVISORS", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Nouvel \303\251l\303\251ment", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Nouvel \303\251l\303\251ment", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Nouvel \303\251l\303\251ment", nullptr));

        comboBox->setPlaceholderText(QString());
        groupBox->setTitle(QString());
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Consultant", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Ressource", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "T\303\242che", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Projet", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        pushButton_ajouter_3->setText(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        buttonTrier->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        comboBox_10->setItemText(0, QCoreApplication::translate("MainWindow", "Trier_par_ID", nullptr));
        comboBox_10->setItemText(1, QCoreApplication::translate("MainWindow", "Trier_par_Nom", nullptr));
        comboBox_10->setItemText(2, QCoreApplication::translate("MainWindow", "Trier_par_Description", nullptr));
        comboBox_10->setItemText(3, QCoreApplication::translate("MainWindow", "Trier_par_Statut", nullptr));

        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        pushButton_ajouter_4->setText(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        buttonRechercher->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        comboBox_18->setItemText(0, QCoreApplication::translate("MainWindow", "Rechercher_par_ID", nullptr));
        comboBox_18->setItemText(1, QCoreApplication::translate("MainWindow", "Rechercher_par_Nom", nullptr));
        comboBox_18->setItemText(2, QCoreApplication::translate("MainWindow", "Rechercher_par_Statut", nullptr));

        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "PDF & Statistiques", nullptr));
        pushButton_ajouter_5->setText(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        pushButton_pdf->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        pushButton_statistiques->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
