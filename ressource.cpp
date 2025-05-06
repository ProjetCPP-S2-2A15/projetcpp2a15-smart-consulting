#include "ressource.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QSqlError>
#include <QDebug>

Ressource::Ressource() {}

Ressource::Ressource(int id, QString type, QString nom, QString description, QString disponibilite, QString fournisseur, QString adresse, QString phone)
    : id(id), type(type), nom(nom), description(description), disponibilite(disponibilite), fournisseur(fournisseur), adresse(adresse), phone(phone) {}

// Getters
int Ressource::getId() const { return id; }
QString Ressource::getType() const { return type; }
QString Ressource::getNom() const { return nom; }
QString Ressource::getDescription() const { return description; }
QString Ressource::getDisponibilite() const { return disponibilite; }
QString Ressource::getFournisseur() const { return fournisseur; }
QString Ressource::getAdresse() const { return adresse; }
QString Ressource::getPhone() const { return phone; }

// Setters
void Ressource::setId(int id) { this->id = id; }
void Ressource::setType(const QString &type) { this->type = type; }
void Ressource::setNom(const QString &nom) { this->nom = nom; }
void Ressource::setDescription(const QString &description) { this->description = description; }
void Ressource::setDisponibilite(const QString &disponibilite) { this->disponibilite = disponibilite; }
void Ressource::setFournisseur(const QString &fournisseur) { this->fournisseur = fournisseur; }
void Ressource::setAdresse(const QString &adresse) { this->adresse = adresse; }
void Ressource::setPhone(const QString &phone) { this->phone = phone; }

// Ajouter une ressource
bool Ressource::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO ressource (id_ressource, type, nom, description, disponibilite, fournisseur, adresse, phone) "
                  "VALUES (:id, :type, :nom, :description, :disponibilite, :fournisseur, :adresse, :phone)");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":fournisseur", fournisseur);
    query.bindValue(":adresse", adresse);
    query.bindValue(":phone", phone);
    return query.exec();
}
// Afficher la liste des ressources
QSqlQueryModel* Ressource::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ressource");
    return model;
}
// Modifier une ressource
bool Ressource::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE ressource SET type = :type, nom = :nom, description = :description, disponibilite = :disponibilite, "
                  "fournisseur = :fournisseur, adresse = :adresse, phone = :phone WHERE id_ressource = :id");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":fournisseur", fournisseur);
    query.bindValue(":adresse", adresse);
    query.bindValue(":phone", phone);
    return query.exec();
}

// Supprimer une ressource
bool Ressource::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM ressource WHERE id_ressource = :id");
    query.bindValue(":id", id);
    return query.exec();
}
