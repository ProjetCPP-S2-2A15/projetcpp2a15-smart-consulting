#include "projet.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

Projet::Projet() {}

Projet::Projet(int id_projet, QString nom, QString description, QString statut)
    : id_projet(id_projet), nom(nom), description(description), statut(statut) {}

// Getters
int Projet::getIdProjet() const { return id_projet; }
QString Projet::getNom() const { return nom; }
QString Projet::getDescription() const { return description; }
QString Projet::getStatut() const { return statut; }

// Setters
void Projet::setIdProjet(int id_projet) { this->id_projet = id_projet; }
void Projet::setNom(const QString &nom) { this->nom = nom; }
void Projet::setDescription(const QString &description) { this->description = description; }
void Projet::setStatut(const QString &statut) { this->statut = statut; }

// Ajouter un projet
bool Projet::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO projet (id_projet, nom, description, statut) "
                  "VALUES (:id_projet, :nom, :description, :statut)");
    query.bindValue(":id_projet", id_projet);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":statut", statut);
    return query.exec();
}
// Afficher la liste des projets
QSqlQueryModel* Projet::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM projet");
    return model;
}
// Supprimer un projet
bool Projet::supprimer(int id_projet) {
    QSqlQuery query;
    query.prepare("DELETE FROM projet WHERE id_projet = :id_projet");
    query.bindValue(":id_projet", id_projet);
    return query.exec();
}

// Modifier un projet
bool Projet::modifier(int id_projet) {
    QSqlQuery query;
    query.prepare("UPDATE projet SET nom = :nom, description = :description, statut = :statut WHERE id_projet = :id_projet");
    query.bindValue(":id_projet", id_projet);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":statut", statut);
    return query.exec();
}
