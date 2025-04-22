#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "projet.h"
#include <QMainWindow>

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
    void on_pushButton_ajouter_2_clicked();
    void on_pushButton_rechercheid_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_afficher_clicked();
    void on_pushButton_pdf_clicked();
    void on_buttonRechercher_clicked();
    void on_buttonTrier_clicked();
    void on_pushButton_statistiques_clicked();
    void on_importer_clicked();
    void on_exportButton_clicked();
    void on_pushButton_QR_clicked();

    void on_backup_clicked();

private:
    Ui::MainWindow *ui;
    Projet projet;
};

#endif // MAINWINDOW_H
