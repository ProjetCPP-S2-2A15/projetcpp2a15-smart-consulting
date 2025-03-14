#ifndef CONSULTANTMANAGER_H
#define CONSULTANTMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include "consultant.h"

class ConsultantManager {
public:
    ConsultantManager(QSqlDatabase db);
    bool ajouterConsultant(const Consultant& consultant);
    QSqlQueryModel* afficherConsultants();
    bool modifierConsultant(const Consultant& consultant);
    bool supprimerConsultant(int id);

private:
    QSqlDatabase db;
};

#endif // CONSULTANTMANAGER_H
