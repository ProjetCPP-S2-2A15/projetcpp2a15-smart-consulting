#include "consultant.h"

Consultant::Consultant() {}

Consultant::Consultant(int id, QString nom, QString email, QString specialite, QString disponibilite)
    : id(id), nom(nom), email(email), specialite(specialite), disponibilite(disponibilite) {}

int Consultant::getId() const { return id; }
QString Consultant::getNom() const { return nom; }
QString Consultant::getEmail() const { return email; }
QString Consultant::getSpecialite() const { return specialite; }
QString Consultant::getDisponibilite() const { return disponibilite; }
