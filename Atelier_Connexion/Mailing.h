#ifndef MAILING_H
#define MAILING_H
#include <QString>
#include <QTextStream>
#include <QTcpSocket>
#include <QDebug>

class Mailing
{
public:
    Mailing();
    bool envoyerEmail(QString destinataire, QString sujet, QString contenu);
};

#endif // MAILING_H

