#include "Mailing.h"
#include <QTcpSocket>  // Indispensable pour gérer la connexion SMTP
#include <QDebug>      // Pour afficher les erreurs

Mailing::Mailing() {}

bool Mailing::envoyerEmail(QString destinataire, QString sujet, QString contenu) {
    QTcpSocket socket;

    // Connexion au serveur SMTP de Gmail
    socket.connectToHost("smtp.gmail.com", 587);

    if (!socket.waitForConnected(5000)) {
        qDebug() << "Erreur de connexion au serveur SMTP";
        return false;
    }

    QTextStream stream(&socket);

    // EHLO pour identifier la session au serveur SMTP
    stream << "EHLO smtp.gmail.com\r\n";

    // Définir l'adresse de l'expéditeur (remplacez par l'adresse réelle de l'expéditeur)
    stream << "MAIL FROM: <allanscottmba@gmail.com>\r\n";

    // Définir le destinataire
    stream << "RCPT TO: <" << destinataire << ">\r\n";

    // Indication que nous envoyons des données
    stream << "DATA\r\n";

    // Envoi des informations du message
    stream << "From: allanscottmba@gmail.com\r\n";
    stream << "To: " << destinataire << "\r\n";
    stream << "Subject: " << sujet << "\r\n\r\n";
    stream << contenu << "\r\n.\r\n";  // Fin du message

    // Commande de déconnexion
    stream << "QUIT\r\n";

    // Attendre que le message soit bien envoyé
    socket.waitForBytesWritten(5000);
    socket.disconnectFromHost();

    return true;
}
