#ifndef TACHE_H
#define TACHE_H
#include <QString>
#include "connection.h"
#include <QDebug>

class tache
{
public:
    tache();
    bool ajouterTache(const int ID,const QString& nom, const QString& description, const int consultant, const QString& echeance, const QString& statut);
    bool modifierTache(int id, const QString& nom, const QString& description, const int consultant, const QString& echeance, const QString& statut);
    bool supprimerTache(int id);
};

#endif // TACHE_H
