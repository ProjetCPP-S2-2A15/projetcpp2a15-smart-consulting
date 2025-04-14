/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit_chat;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_message;
    QPushButton *pushButton_envoyer;

    void setupUi(QDialog *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName("ChatWindow");
        ChatWindow->resize(500, 400);
        verticalLayout = new QVBoxLayout(ChatWindow);
        verticalLayout->setObjectName("verticalLayout");
        textEdit_chat = new QTextEdit(ChatWindow);
        textEdit_chat->setObjectName("textEdit_chat");
        textEdit_chat->setReadOnly(true);

        verticalLayout->addWidget(textEdit_chat);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit_message = new QLineEdit(ChatWindow);
        lineEdit_message->setObjectName("lineEdit_message");

        horizontalLayout->addWidget(lineEdit_message);

        pushButton_envoyer = new QPushButton(ChatWindow);
        pushButton_envoyer->setObjectName("pushButton_envoyer");

        horizontalLayout->addWidget(pushButton_envoyer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QDialog *ChatWindow)
    {
        ChatWindow->setWindowTitle(QCoreApplication::translate("ChatWindow", "Chat en direct", nullptr));
        lineEdit_message->setPlaceholderText(QCoreApplication::translate("ChatWindow", "\303\211crire un message...", nullptr));
        pushButton_envoyer->setText(QCoreApplication::translate("ChatWindow", "Envoyer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
