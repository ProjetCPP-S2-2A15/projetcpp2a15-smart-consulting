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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_connexion;
    QPushButton *pushButton_motdepasseoublie;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(320, 200);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName("verticalLayout");
        lineEdit_username = new QLineEdit(Login);
        lineEdit_username->setObjectName("lineEdit_username");

        verticalLayout->addWidget(lineEdit_username);

        lineEdit_password = new QLineEdit(Login);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit_password);

        pushButton_connexion = new QPushButton(Login);
        pushButton_connexion->setObjectName("pushButton_connexion");

        verticalLayout->addWidget(pushButton_connexion);

        pushButton_motdepasseoublie = new QPushButton(Login);
        pushButton_motdepasseoublie->setObjectName("pushButton_motdepasseoublie");

        verticalLayout->addWidget(pushButton_motdepasseoublie);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Connexion", nullptr));
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("Login", "Nom d'utilisateur", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("Login", "Mot de passe", nullptr));
        pushButton_connexion->setText(QCoreApplication::translate("Login", "Connexion", nullptr));
        pushButton_motdepasseoublie->setText(QCoreApplication::translate("Login", "Mot de passe oubli\303\251 ?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
