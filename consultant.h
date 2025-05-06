#ifndef CONSULTANT_H
#define CONSULTANT_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QString>

class Consultant {
public:
    Consultant();
    Consultant( QString nom, QString email, QString specialite, QString disponibilite);

    int getId() const;
    QString getNom() const;
    QString getEmail() const;
    QString getSpecialite() const;
    QString getDisponibilite() const;

    Consultant(QSqlDatabase db);
    bool ajouterConsultant(const Consultant& consultant);
    QSqlQueryModel* afficherConsultants();
    bool modifierConsultant(int id , const Consultant& consultant);
    bool supprimerConsultant(int id);
    QSqlDatabase getDatabase() const;
    bool modifierConsultant(const QString& ancienEmail, const Consultant& consultant);



private:
     QSqlDatabase db;
    int id;
    QString nom, email, specialite, disponibilite;
};

#endif // CONSULTANT_H
