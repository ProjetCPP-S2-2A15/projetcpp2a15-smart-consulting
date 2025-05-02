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

class Fournisseur {
public:
    // Constructeur
    Fournisseur(const QString &name = "", const QString &location = "");

    // Méthode pour obtenir les coordonnées
    bool getCoordinatesFromLocation(double &latitude, double &longitude) const;

    // Méthode pour afficher les fournisseurs (retourne un modèle SQL)
    QSqlQueryModel* afficher() const;

    // Setter pour la localisation
    void setLocation(const QString &location);

private:
    QString name;       // Nom du fournisseur
    QString location;   // Localisation du fournisseur (format "latitude,longitude")
};

#endif // RESSOURCE_H
