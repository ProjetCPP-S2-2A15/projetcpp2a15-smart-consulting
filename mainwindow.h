#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ressource.h"
#include "sms.h"
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QQuickWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QSqlQueryModel>
#include <QQmlContext>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>




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
    void on_pushButton_ajouter_clicked();
    void on_pushButton_rechercheid_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_afficher_clicked();
    void on_pushButton_pdf_clicked();
    void on_buttonRechercher_clicked();
    void on_buttonTrier_clicked();
    void on_pushButton_statistiques_clicked();
    void refreshMap();
    void readSerial();
private:


    void checkRFID(const QString &rfid);
    QSerialPort *serial;


    Ui::MainWindow *ui;
    Ressource res;  // Utilisation de la classe Ressource au lieu de Etablissement
    QSystemTrayIcon *trayIcon;
};

#endif // MAINWINDOW_H
