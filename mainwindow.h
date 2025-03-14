#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "connection.h"
#include "tache.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    tache tache;

private slots:


private:
    Connection cnx;
    Ui::MainWindow *ui;
    //bool ajouterTache(QString nom, QString specialite, QString email, double taux_horaire, QString dispo);
    void on_btnAjouter_clicked();
    void afficherTaches();
    void on_btnModifier_clicked();
    void on_btnSupprimer_clicked();

};
#endif // MAINWINDOW_H
