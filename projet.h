#ifndef PROJET_H
#define PROJET_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Projet {
public:
    Projet();
    Projet(int id_projet, QString nom, QString description, QString statut);

    // Getters
    int getIdProjet() const;
    QString getNom() const;
    QString getDescription() const;
    QString getStatut() const;

    // Setters
    void setIdProjet(int id_projet);
    void setNom(const QString &nom);
    void setDescription(const QString &description);
    void setStatut(const QString &statut);

    // Méthodes pour un projet
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier(int id_projet);
    bool supprimer(int id_projet);

private:
    int id_projet;
    QString nom;
    QString description;
    QString statut;
};

#endif // PROJET_H
