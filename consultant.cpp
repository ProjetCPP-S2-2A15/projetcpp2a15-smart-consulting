#include "consultant.h"
#include <QTextDocument>
#include <QFileDialog>
#include <QTextCursor>
#include <QTextTable>
#include <QTextTableFormat>
#include <QPrinter>

Consultant::Consultant() {}

Consultant::Consultant(QString nom, QString email, QString specialite, QString disponibilite)
    : nom(nom), email(email), specialite(specialite), disponibilite(disponibilite) {}


// Getters

int Consultant::getId() const { return id; }
QString Consultant::getNom() const { return nom; }
QString Consultant::getEmail() const { return email; }
QString Consultant::getSpecialite() const { return specialite; }
QString Consultant::getDisponibilite() const { return disponibilite; }

// Setters




//  CREATE (Ajouter un consultant)
bool Consultant::ajouterConsultant(const Consultant& consultant) {
    QSqlQuery query;
    query.prepare("INSERT INTO CONSULTANT ( nom, email, specialite, disponibilite) "
                  "VALUES ( :nom, :email, :specialite, :disponibilite)");

    // Ne pas lier ID_CONSULTANT, car il est généré automatiquement
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

// READ (Afficher la liste des consultants)
QSqlQueryModel* Consultant::afficherConsultants() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id_consultant, nom, email, specialite, disponibilite FROM CONSULTANT");
    return model;
}

bool Consultant::modifierConsultant(const QString& ancienEmail, const Consultant& consultant) {
    QSqlQuery query;
    query.prepare("UPDATE CONSULTANT SET nom = :nom, email = :email, "
                  "specialite = :specialite, disponibilite = :disponibilite "
                  "WHERE email = :ancienEmail");
    query.bindValue(":nom", consultant.getNom());
    query.bindValue(":email", consultant.getEmail());
    query.bindValue(":specialite", consultant.getSpecialite());
    query.bindValue(":disponibilite", consultant.getDisponibilite());
    query.bindValue(":ancienEmail", ancienEmail);

    if (!query.exec()) {
        qDebug() << "Erreur modification consultant:" << query.lastError().text();
        return false;
    }
    return true;
}
// DELETE (Supprimer un consultant)
bool Consultant::supprimerConsultant(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM CONSULTANT WHERE id_consultant=:id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur suppression consultant:" << query.lastError().text();
        return false;
    }
    return true;
}
