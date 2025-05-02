#include "mainwindow.h"

#include <QApplication>
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Connection c;

    bool test=c.createconnect();
    MainWindow w;
    w.show();
    if(test)


    {QMessageBox::information(nullptr, QObject::tr("Succés"),
                                 QObject::tr("Connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    return a.exec();

}
