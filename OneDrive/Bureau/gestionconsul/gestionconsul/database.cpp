#include "database.h"



connect::connect(){
}
bool connect::set_connection()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ProjetConsult2A");
    db.setUserName("moujib");
    db.setPassword("moujib");

    if(db.open()){
        return true;
    }
    else{
        return false;
    }

}
