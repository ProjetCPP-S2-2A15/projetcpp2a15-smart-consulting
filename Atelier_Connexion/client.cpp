#include "client.h"
#include <QPainter>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QDate>
#include "ui_mainwindow.h"


client::client() {

    id = 0;
    nom = "";
    email = "";
    telephone = "";
    adresse = "";
    secteur = "";
}

client::client(int id, QString nom, QString email, QString telephone, QString adresse, QString secteur) {
    this->id = id;
    this->nom = nom;
    this->email = email;
    this->telephone = telephone;
    this->adresse = adresse;
    this->secteur = secteur;
}

// Ajouter un client
bool client::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (ID, NOM, EMAIL, TELEPHONE, ADRESSE, SECTEUR) "
                  "VALUES (:id, :nom, :email, :telephone, :adresse, :secteur)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":adresse", adresse);
    query.bindValue(":secteur", secteur);

    return query.exec();
}

// Afficher les clients
QSqlQueryModel* client::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query("SELECT ID, NOM, EMAIL, TELEPHONE, ADRESSE, SECTEUR FROM CLIENT");
    query.exec();
    model->setQuery(std::move(query));
    return model;
}
// Supprimer un client
bool client::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENT WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        ajouterHistorique("Suppression", id); // Ajouter dans l'historique
        qDebug() << "Client supprimé avec succès.";
        return true;
    } else {
        qDebug() << "Erreur lors de la suppression : " << query.lastError().text();
        return false;
    }
}

// Modifier un client
bool client::modifier(int id, QString nom, QString email, QString telephone, QString adresse, QString secteur) {
    // Préparation de la requête pour modifier les informations du client
    QSqlQuery query;
    query.prepare("UPDATE CLIENT SET NOM = :nom, EMAIL = :email, TELEPHONE = :telephone, ADRESSE = :adresse, SECTEUR = :secteur WHERE ID = :id");

    // Bind des valeurs des paramètres dans la requête SQL
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":adresse", adresse);
    query.bindValue(":secteur", secteur);

    // Exécution de la requête
    if (query.exec()) {
        // Si la modification a réussi, on ajoute dans l'historique
        ajouterHistorique("Modification", id); // Ajouter dans l'historique
        qDebug() << "Modification réussie pour ID:" << id;

        return true;
    } else {
        // En cas d'erreur, afficher l'erreur SQL dans les logs
        qDebug() << "Erreur lors de la modification pour ID:" << id << " : " << query.lastError().text();
        return false;
    }
}


QSqlQueryModel* client::rechercherParAdresse(const QString& adresse) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID, NOM, EMAIL, TELEPHONE, ADRESSE, SECTEUR FROM CLIENT WHERE ADRESSE LIKE :adresse");
    query.bindValue(":adresse", "%" + adresse + "%"); // Paramètre lié pour éviter les injections SQL

    if (query.exec()) {
        model->setQuery(std::move(query));  // Utilisation de std::move pour éviter la copie
    } else {
        qDebug() << "Erreur lors de la recherche par adresse : " << query.lastError().text();
    }

    return model;
}

bool client::ajouterHistorique(QString typeModification, int idClient) {
    QSqlQuery query;
    query.prepare("INSERT INTO HISTORIQUE (TYPE_MODIFICATION, ID_CLIENT, TIMESTAMP) VALUES (:type, :id, CURRENT_TIMESTAMP)");
    query.bindValue(":type", typeModification);
    query.bindValue(":id", idClient);

    if (query.exec()) {
        qDebug() << "Historique ajouté avec succès : Action =" << typeModification << ", ID Client =" << idClient;
        return true;
    } else {
        qDebug() << "Erreur lors de l'ajout à l'historique : " << query.lastError().text();
        qDebug() << "Requête SQL : " << query.lastQuery();
        return false;
    }
}

// ✅ Cette fonction est maintenant en-dehors de 'ajouterHistorique'
QSqlQueryModel* client::trierParNom() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query("SELECT ID, NOM, EMAIL, TELEPHONE, ADRESSE, SECTEUR FROM CLIENT ORDER BY NOM ASC");
    query.exec();
    model->setQuery(std::move(query));
    return model;
}


bool client::exporterPDF(const QString& fileName, QTableWidget* table) {

    QPdfWriter pdf(fileName);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    QPainter painter(&pdf);
    if (!painter.isActive()) {
        qDebug() << "Impossible d'ouvrir le fichier PDF.";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT ID, NOM, EMAIL, TELEPHONE, ADRESSE, SECTEUR FROM CLIENT");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête SQL :" << query.lastError();
        return false;
    }

    int y = 50;
    int pageHeight = pdf.height();

    if (!query.next()) {
        painter.drawText(50, y, "Aucun client trouvé dans la base de données.");
        painter.end();
        return true;
    }

    query.previous(); // Revenir au début

    // En-têtes avec police en gras
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.drawText(50, y, "ID");
    painter.drawText(100, y, "Nom");
    painter.drawText(250, y, "Email");
    painter.drawText(400, y, "Téléphone");
    painter.drawText(550, y, "Adresse");
    painter.drawText(700, y, "Secteur");
    painter.drawLine(50, y + 10, 800, y + 10);
    y += 30;

    painter.setFont(QFont("Arial", 10));

    // Calcul dynamique de la largeur des colonnes
    QVector<int> columnWidths;
    for (int col = 0; col < table->columnCount(); ++col) {
        int maxWidth = 0;
        for (int row = 0; row < table->rowCount(); ++row) {
            QString text = table->item(row, col) ? table->item(row, col)->text() : "";
            maxWidth = std::max(maxWidth, QFontMetrics(painter.font()).horizontalAdvance(text));
        }
        columnWidths.append(maxWidth + 20); // Ajouter un peu d'espace supplémentaire
    }

    // Remplir les données dans le PDF
    while (query.next()) {
        if (y > pageHeight - 50) {
            pdf.newPage();
            y = 50;
            // Réafficher les en-têtes sur la nouvelle page
            painter.drawText(50, y, "ID");
            painter.drawText(100, y, "Nom");
            painter.drawText(250, y, "Email");
            painter.drawText(400, y, "Téléphone");
            painter.drawText(550, y, "Adresse");
            painter.drawText(700, y, "Secteur");
            painter.drawLine(50, y + 10, 800, y + 10);
            y += 30;
        }

        painter.drawText(50, y, query.value(0).toString());
        painter.drawText(100, y, query.value(1).toString());
        painter.drawText(250, y, query.value(2).toString());
        painter.drawText(400, y, query.value(3).toString());
        painter.drawText(550, y, query.value(4).toString());
        painter.drawText(700, y, query.value(5).toString());
        y += 20;
    }

    painter.end();
    return true;
}


QMap<QString, int> client::getStatistiquesParSecteur() {
    QMap<QString, int> stats;  // Contiendra le secteur et le nombre de clients associés
    QSqlQuery query;

    // Préparation de la requête pour compter les clients par secteur
    query.prepare("SELECT SECTEUR, COUNT(*) as Nombre FROM CLIENT GROUP BY SECTEUR");

    if (!query.exec()) {
        // Gestion d'erreur si la requête échoue
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        return stats;  // Retourne un QMap vide en cas d'erreur
    }

    // Si la requête s'exécute correctement, on parcourt les résultats
    while (query.next()) {
        QString secteur = query.value(0).toString();
        int nombre = query.value(1).toInt();
        stats[secteur] = nombre;  // Ajoute le secteur et le nombre de clients au QMap
    }

    return stats;
}
