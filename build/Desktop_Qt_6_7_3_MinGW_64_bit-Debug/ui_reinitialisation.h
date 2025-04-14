/********************************************************************************
** Form generated from reading UI file 'reinitialisation.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REINITIALISATION_H
#define UI_REINITIALISATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Reinitialisation
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_question;
    QLineEdit *lineEdit_reponse;
    QLineEdit *lineEdit_nouveau_mdp;
    QPushButton *pushButton_valider;

    void setupUi(QDialog *Reinitialisation)
    {
        if (Reinitialisation->objectName().isEmpty())
            Reinitialisation->setObjectName("Reinitialisation");
        Reinitialisation->resize(400, 220);
        verticalLayout = new QVBoxLayout(Reinitialisation);
        verticalLayout->setObjectName("verticalLayout");
        label_question = new QLabel(Reinitialisation);
        label_question->setObjectName("label_question");

        verticalLayout->addWidget(label_question);

        lineEdit_reponse = new QLineEdit(Reinitialisation);
        lineEdit_reponse->setObjectName("lineEdit_reponse");

        verticalLayout->addWidget(lineEdit_reponse);

        lineEdit_nouveau_mdp = new QLineEdit(Reinitialisation);
        lineEdit_nouveau_mdp->setObjectName("lineEdit_nouveau_mdp");
        lineEdit_nouveau_mdp->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit_nouveau_mdp);

        pushButton_valider = new QPushButton(Reinitialisation);
        pushButton_valider->setObjectName("pushButton_valider");

        verticalLayout->addWidget(pushButton_valider);


        retranslateUi(Reinitialisation);

        QMetaObject::connectSlotsByName(Reinitialisation);
    } // setupUi

    void retranslateUi(QDialog *Reinitialisation)
    {
        Reinitialisation->setWindowTitle(QCoreApplication::translate("Reinitialisation", "R\303\251initialisation du mot de passe", nullptr));
        label_question->setText(QCoreApplication::translate("Reinitialisation", "Question secr\303\250te affich\303\251e ici", nullptr));
        lineEdit_reponse->setPlaceholderText(QCoreApplication::translate("Reinitialisation", "Votre r\303\251ponse", nullptr));
        lineEdit_nouveau_mdp->setPlaceholderText(QCoreApplication::translate("Reinitialisation", "Nouveau mot de passe", nullptr));
        pushButton_valider->setText(QCoreApplication::translate("Reinitialisation", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reinitialisation: public Ui_Reinitialisation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REINITIALISATION_H
