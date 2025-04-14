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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_2;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_12;
    QPushButton *pushButton_9;
    QLineEdit *lineEdit_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_3;
    QPushButton *pushButton_chat;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1023, 589);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 151, 571));
        label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(34, 32, 82, 255), stop:1 rgba(0, 0, 0, 255));\n"
"border-radius: 10px;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, -80, 991, 661));
        label_2->setStyleSheet(QString::fromUtf8("background-color:rgba(250,250,250,250);\n"
"border-radius:10px;"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 131, 471));
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
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 80, 142, 62));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"\n"
"    color: black;  /* D\303\251finir la couleur du texte en noir */\n"
"    border: 1px solid black;  /* Optionnel : pour ajouter une bordure noire */\n"
"}\n"
""));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(0, 170, 140, 60));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(0, 240, 140, 60));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(0, 300, 140, 60));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(0, 360, 140, 60));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 0, 141, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setBold(true);
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(150, -10, 881, 61));
        label_4->setStyleSheet(QString::fromUtf8("/* Style avec fond blanc, bords arrondis et ombre tr\303\250s sombre */\n"
"QWidget {\n"
"    background-color: rgba(255, 255, 255, 255); /* Fond blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    box-shadow: 0px 8px 16px rgba(0, 0, 0, 0.8); /* Ombre tr\303\250s sombre et plus marqu\303\251e */\n"
"}\n"
""));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(540, 10, 131, 31));
        QFont font1;
        font1.setBold(true);
        label_5->setFont(font1);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(420, 130, 831, 81));
        groupBox_2->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral pour le QGroupBox */\n"
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
        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(20, 20, 91, 24));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(130, 20, 113, 22));
        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(260, 20, 91, 24));
        pushButton_8->setStyleSheet(QString::fromUtf8(""));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(360, 20, 113, 22));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(430, 220, 561, 192));
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(160, 120, 241, 281));
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
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 70, 121, 20));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 110, 81, 16));
        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(100, 70, 113, 22));
        pushButton_12 = new QPushButton(groupBox_3);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(130, 240, 75, 24));
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
        pushButton_9 = new QPushButton(groupBox_3);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(30, 240, 75, 24));
        pushButton_9->setStyleSheet(QString::fromUtf8("/* Style pour le QPushButton avec la couleur #dbaf8e */\n"
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
        lineEdit_5 = new QLineEdit(groupBox_3);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(100, 110, 113, 22));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 150, 91, 16));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 170, 91, 16));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 190, 121, 16));
        lineEdit_7 = new QLineEdit(groupBox_3);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(100, 150, 113, 22));
        lineEdit_8 = new QLineEdit(groupBox_3);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(100, 190, 113, 22));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(480, 430, 75, 24));
        pushButton_11->setStyleSheet(QString::fromUtf8(""));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(610, 430, 75, 24));
        pushButton_10->setStyleSheet(QString::fromUtf8(""));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(730, 430, 75, 24));
        pushButton_chat = new QPushButton(centralwidget);
        pushButton_chat->setObjectName("pushButton_chat");
        pushButton_chat->setGeometry(QRect(830, 430, 75, 24));
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        label->raise();
        groupBox->raise();
        label_4->raise();
        label_5->raise();
        groupBox_2->raise();
        tableWidget->raise();
        groupBox_3->raise();
        pushButton_11->raise();
        pushButton_10->raise();
        pushButton_3->raise();
        pushButton_chat->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1023, 22));
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
        label->setText(QString());
        label_2->setText(QString());
        groupBox->setTitle(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Consultant", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Ressource", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "T\303\242che", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Projet", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        label_4->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "ADVISORS", nullptr));
        groupBox_2->setTitle(QString());
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Exportation", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "specialit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "disponibilit\303\251", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Nom-Prenom", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251", nullptr));
        label_10->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "statistiques", nullptr));
        pushButton_chat->setText(QCoreApplication::translate("MainWindow", "chat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
