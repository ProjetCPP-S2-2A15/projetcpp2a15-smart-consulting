#include "mainwindow.h"
#include "database.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connect c;
    bool test=c.set_connection();
    if(test){
        w.show();
        qDebug()<<"database connected";
    }else{
        qDebug()<<"probleme";
    }
    return a.exec();
}
