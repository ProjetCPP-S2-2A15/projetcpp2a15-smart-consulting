#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "consultantmanager.h"  // Inclusion de la classe de gestion des consultants

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

private slots:
    void on_pushButton_9_clicked();  // Ajouter un consultant
    void on_pushButton_10_clicked(); // Modifier un consultant
    void on_pushButton_11_clicked(); // Supprimer un consultant
    void loadConsultants();          // Charger les consultants dans le QTableWidget

private:
    Ui::MainWindow *ui;
    ConsultantManager *consultantManager; // Gestionnaire des consultants
};

#endif // MAINWINDOW_H
