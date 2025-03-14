#include "consultantmanager.h"

ConsultantManager::ConsultantManager(QSqlDatabase db) {
    this->db = db;
}

// 🔹 CREATE (Ajouter un consultant)
bool ConsultantManager::ajouterConsultant(const Consultant& consultant) {
    QSqlQuery query;
    query.prepare("INSERT INTO CONSULTANT (nom, email, specialite, disponibilite) "
                  "VALUES (:nom, :email, :specialite, :disponibilite)");
    query.bindValue(":id", consultant.getId());
    query.bindValue(":nom", consultant.getNom());
    query.bindValue(":email", consultant.getEmail());
    query.bindValue(":specialite", consultant.getSpecialite());
    query.bindValue(":disponibilite", consultant.getDisponibilite());

    if (!query.exec()) {
        qDebug() << "Erreur ajout consultant:" << query.lastError().text();
        return false;
    }
    return true;
}

// 🔹 READ (Afficher la liste des consultants)
QSqlQueryModel* ConsultantManager::afficherConsultants() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id_consultant, nom, email, specialite, disponibilite FROM CONSULTANT");
    return model;
}

// 🔹 UPDATE (Modifier un consultant)
bool ConsultantManager::modifierConsultant(const Consultant& consultant) {
    QSqlQuery query;
    query.prepare("UPDATE CONSULTANT SET nom=:nom, email=:email, specialite=:specialite, "
                  "disponibilite=:disponibilite WHERE id_consultant=:id");
    query.bindValue(":id", consultant.getId());
    query.bindValue(":nom", consultant.getNom());
    query.bindValue(":email", consultant.getEmail());
    query.bindValue(":specialite", consultant.getSpecialite());
    query.bindValue(":disponibilite", consultant.getDisponibilite());

    if (!query.exec()) {
        qDebug() << "Erreur modification consultant:" << query.lastError().text();
        return false;
    }
    return true;
}

// 🔹 DELETE (Supprimer un consultant)
bool ConsultantManager::supprimerConsultant(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM CONSULTANT WHERE id_consultant=:id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur suppression consultant:" << query.lastError().text();
        return false;
    }
    return true;
}
