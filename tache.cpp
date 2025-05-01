#include "tache.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


tache::tache() {}

bool tache::ajouterTache(const int ID,const QString& nom, const QString& description, const int consultant, const QString& echeance, const QString& statut) {
    QSqlQuery query;
    query.prepare("INSERT INTO TACHE (ID_TACHE,NOM, DESCRIPTION, CONSULTANT_ASSIGNE, ECHEANCE, STATUT) "
                  "VALUES (:id,:nom, :description, :consultant, TO_DATE(:echeance, 'YYYY-MM-DD'), :statut)");

    query.bindValue(":id",ID);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":consultant", consultant);
    query.bindValue(":echeance", echeance);
    query.bindValue(":statut", statut);

    if (!query.exec()) {
        qDebug() << "Erreur d'ajout de la tâche:" << query.lastError().text();
        return false;
    }
    return true;
}

bool tache::modifierTache(int id, const QString& nom, const QString& description, const int consultant, const QString& echeance, const QString& statut) {
    QSqlQuery query;
    query.prepare("UPDATE TACHE SET NOM = :nom,DESCRIPTION = :description,CONSULTANT_ASSIGNE=:consultant,echeance=TO_DATE(:echeance, 'YYYY-MM-DD'),statut=:statut WHERE ID_TACHE=:id");

    query.bindValue(":id",id);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":consultant", consultant);
    query.bindValue(":echeance", echeance);
    query.bindValue(":statut", statut);

    return query.exec();
}
bool tache::supprimerTache(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM TACHE WHERE ID_TACHE=:id");
    query.bindValue(":id", id);
    return query.exec();
}

QList<QPair<int, QString>> tache::getTachesEcheanceDemain() {
    QList<QPair<int, QString>> tachesList;

    qDebug() << "Début de la récupération des tâches dont l'échéance est demain.";

    QSqlQuery query;
    QString sql = "SELECT ID_TACHE, NOM FROM TACHE WHERE TRUNC(ECHEANCE) = TRUNC(SYSDATE + 1)";
    query.prepare(sql);

    qDebug() << "Requête SQL préparée:" << sql;

    if (query.exec()) {
        qDebug() << "Exécution de la requête réussie.";

        while (query.next()) {
            int id = query.value("ID_TACHE").toInt();
            QString nom = query.value("NOM").toString();
            tachesList.append(qMakePair(id, nom));
            qDebug() << "Tâche trouvée - ID:" << id << ", NOM:" << nom;
        }

        if (tachesList.isEmpty()) {
            qDebug() << "Aucune tâche trouvée avec une échéance demain.";
        }

    } else {
        qDebug() << "Erreur lors de l'exécution de la requête:"
                 << query.lastError().text();
    }

    qDebug() << "Récupération terminée. Nombre de tâches trouvées:" << tachesList.size();
    return tachesList;
}

