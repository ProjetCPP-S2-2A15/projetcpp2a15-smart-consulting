#ifndef CONSULTANT_H
#define CONSULTANT_H

#include <QString>

class Consultant {
public:
    Consultant();
    Consultant(int id, QString nom, QString email, QString specialite, QString disponibilite);

    int getId() const;
    QString getNom() const;
    QString getEmail() const;
    QString getSpecialite() const;
    QString getDisponibilite() const;

private:
    int id;
    QString nom, email, specialite, disponibilite;
};

#endif // CONSULTANT_H
