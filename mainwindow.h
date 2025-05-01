#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QCalendarWidget>
#include <QSet>
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

private slots:
    // Méthodes du calendrier
    void onDateChanged(const QDate &date);
    void updateReservedDates();
    void onCalendarDateClicked(const QDate &date);

    // Slots pour les actions
    void on_btnAjouter_clicked();
    void on_btnModifier_clicked();
    void on_btnSupprimer_clicked();
    void on_pushButton_recherche_clicked();
    void on_buttonTrier_clicked();
    void on_pushButton_statistiques_clicked();
    void on_pushButton_pdf_clicked();

private:
    Ui::MainWindow *ui;
    Connection cnx;
    tache tache;
    QCalendarWidget *calendarWidget;
    QSet<QDate> reservedDates;

    // Méthodes internes
    void setupCalendar();
    void loadReservedDates();
    void highlightReservedDates();
    void afficherTaches();
    void loadTachesNotifications();
    void setupConnections();
};

#endif // MAINWINDOW_H
