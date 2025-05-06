#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Ressource {
public:
    Ressource();
    Ressource(int id, QString type, QString nom, QString description, QString disponibilite, QString fournisseur, QString adresse, QString phone);

    // Getters
    int getId() const;
    QString getType() const;
    QString getNom() const;
    QString getDescription() const;
    QString getDisponibilite() const;
    QString getFournisseur() const;
    QString getAdresse() const;
    QString getPhone() const;

    // Setters
    void setId(int id);
    void setType(const QString &type);
    void setNom(const QString &nom);
    void setDescription(const QString &description);
    void setDisponibilite(const QString &disponibilite);
    void setFournisseur(const QString &fournisseur);
    void setAdresse(const QString &adresse);
    void setPhone(const QString &phone);

    // Méthodes pour une ressource
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier(int id);
    bool supprimer(int id);

private:
    int id;
    QString type;
    QString nom;
    QString description;
    QString disponibilite;
    QString fournisseur;
    QString adresse;
    QString phone;
};



#endif // RESSOURCE_H
