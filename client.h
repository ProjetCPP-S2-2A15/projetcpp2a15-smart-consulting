#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include <QMap>
#include <QTableWidget>


class client
{
public:
    client();
    client(int id, QString nom, QString email, QString telephone, QString adresse, QString secteur);

    // Getters
    int getId() const { return id; }
    QString getNom() const { return nom; }
    QString getEmail() const { return email; }
    QString getTelephone() const { return telephone; }
    QString getAdresse() const { return adresse; }
    QString getSecteur() const { return secteur; }
    QString getEtatConsultation() const { return etat_consultation; }
    QString getDureeConsultation() const { return duree_consultation; }

    // Setters
    void setId(int id) { this->id = id; }
    void setNom(QString nom) { this->nom = nom; }
    void setEmail(QString email) { this->email = email; }
    void setTelephone(QString telephone) { this->telephone = telephone; }
    void setAdresse(QString adresse) { this->adresse = adresse; }
    void setSecteur(QString secteur) { this->secteur = secteur; }
    void setEtatConsultation(QString etat) { this->etat_consultation = etat; }
    void setDureeConsultation(QString duree) { this->duree_consultation = duree; }
    bool envoyerEmail(QString destinataire, QString sujet, QString contenu);
    // Fonctionnalités CRUD (Create, Read, Update, Delete)
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier(int id, QString nom, QString email, QString telephone, QString adresse, QString secteur); // Ajout de la méthode modifier
    QSqlQueryModel* rechercherNom(QString nom);
    QSqlQueryModel* trierParSecteur();
    QSqlQueryModel* trierParNom();
    QSqlQueryModel* rechercherParAdresse(const QString& adresse);  // Ajout du const
    bool ajouterHistorique(QString typeModification, int idClient);
    bool exporterPDF(const QString& fileName, QTableWidget* table);

    // Export en PDF
    // Déclare la méthode pour obtenir les statistiques par secteur
    QMap<QString, int> getStatistiquesParSecteur();

    // Nouvelle méthode pour mettre à jour l'état et la durée de consultation
    bool mettreAJourEtatEtDuree(int idClient, QString nouvelEtat, QString nouvelleDuree);

private:
    int id;
    QString nom;
    QString email;
    QString telephone;
    QString adresse;
    QString secteur;
    QString etat_consultation;  // Nouvel attribut
    QString duree_consultation; // Nouvel attribut
};


#endif // CLIENT_H
