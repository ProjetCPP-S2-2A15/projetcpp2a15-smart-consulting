/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_question;
    QLineEdit *lineEdit_reponse;
    QPushButton *pushButton_inscrire;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->resize(360, 320);
        verticalLayout = new QVBoxLayout(Register);
        verticalLayout->setObjectName("verticalLayout");
        label_title = new QLabel(Register);
        label_title->setObjectName("label_title");
        label_title->setStyleSheet(QString::fromUtf8("font: bold 14pt \"Segoe UI\"; color: #2c3e50;"));
        label_title->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_title);

        lineEdit_username = new QLineEdit(Register);
        lineEdit_username->setObjectName("lineEdit_username");

        verticalLayout->addWidget(lineEdit_username);

        lineEdit_password = new QLineEdit(Register);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(lineEdit_password);

        lineEdit_question = new QLineEdit(Register);
        lineEdit_question->setObjectName("lineEdit_question");

        verticalLayout->addWidget(lineEdit_question);

        lineEdit_reponse = new QLineEdit(Register);
        lineEdit_reponse->setObjectName("lineEdit_reponse");

        verticalLayout->addWidget(lineEdit_reponse);

        pushButton_inscrire = new QPushButton(Register);
        pushButton_inscrire->setObjectName("pushButton_inscrire");
        pushButton_inscrire->setStyleSheet(QString::fromUtf8("background-color: #2ecc71; color: white; padding: 6px; border-radius: 10px;"));

        verticalLayout->addWidget(pushButton_inscrire);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Inscription", nullptr));
        label_title->setText(QCoreApplication::translate("Register", "Cr\303\251er un compte", nullptr));
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("Register", "Nom d'utilisateur", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("Register", "Mot de passe", nullptr));
        lineEdit_question->setPlaceholderText(QCoreApplication::translate("Register", "Question secr\303\250te", nullptr));
        lineEdit_reponse->setPlaceholderText(QCoreApplication::translate("Register", "R\303\251ponse secr\303\250te", nullptr));
        pushButton_inscrire->setText(QCoreApplication::translate("Register", "S'inscrire", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
