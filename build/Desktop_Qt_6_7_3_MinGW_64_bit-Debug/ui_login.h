/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_titre;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_connexion;
    QPushButton *pushButton_motdepasseoublie;
    QPushButton *pushButton_inscription;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(360, 340);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName("verticalLayout");
        label_titre = new QLabel(Login);
        label_titre->setObjectName("label_titre");
        label_titre->setStyleSheet(QString::fromUtf8("font: bold 14pt \"Segoe UI\"; color: #2c3e50;"));
        label_titre->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_titre);

        lineEdit_username = new QLineEdit(Login);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setStyleSheet(QString::fromUtf8("padding: 6px; border-radius: 10px; border: 1px solid #bdc3c7;"));

        verticalLayout->addWidget(lineEdit_username);

        lineEdit_password = new QLineEdit(Login);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setStyleSheet(QString::fromUtf8("padding: 6px; border-radius: 10px; border: 1px solid #bdc3c7;"));
        lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(lineEdit_password);

        pushButton_connexion = new QPushButton(Login);
        pushButton_connexion->setObjectName("pushButton_connexion");
        pushButton_connexion->setStyleSheet(QString::fromUtf8("background-color: #3498db; color: white; padding: 6px; border-radius: 10px;"));

        verticalLayout->addWidget(pushButton_connexion);

        pushButton_motdepasseoublie = new QPushButton(Login);
        pushButton_motdepasseoublie->setObjectName("pushButton_motdepasseoublie");
        pushButton_motdepasseoublie->setStyleSheet(QString::fromUtf8("color: #2980b9;"));
        pushButton_motdepasseoublie->setFlat(true);

        verticalLayout->addWidget(pushButton_motdepasseoublie);

        pushButton_inscription = new QPushButton(Login);
        pushButton_inscription->setObjectName("pushButton_inscription");
        pushButton_inscription->setStyleSheet(QString::fromUtf8("color: #16a085;"));
        pushButton_inscription->setFlat(true);

        verticalLayout->addWidget(pushButton_inscription);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Connexion", nullptr));
        label_titre->setText(QCoreApplication::translate("Login", "Connexion \303\240 Smart Consulting", nullptr));
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("Login", "Nom d'utilisateur", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("Login", "Mot de passe", nullptr));
        pushButton_connexion->setText(QCoreApplication::translate("Login", "Se connecter", nullptr));
        pushButton_motdepasseoublie->setText(QCoreApplication::translate("Login", "Mot de passe oubli\303\251 ?", nullptr));
        pushButton_inscription->setText(QCoreApplication::translate("Login", "Cr\303\251er un compte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
