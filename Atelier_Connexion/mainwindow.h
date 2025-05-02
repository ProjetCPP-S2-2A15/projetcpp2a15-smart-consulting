#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSerialPort> // Ajout pour la gestion du port série
#include <QSqlQuery>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();



    void on_pushButton_10_clicked();

    void on_pushButton_trier_clicked();

    void on_pushButton_pdf_clicked();

    void on_lineEdit_recherche_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_mailling_clicked();
    void readArduinoData(); // Slot pour lire les données du port série

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort; // Déclaration du port série


    void setupSerialConnection(); // Fonction pour configurer le port série
};

#endif // MAINWINDOW_H
