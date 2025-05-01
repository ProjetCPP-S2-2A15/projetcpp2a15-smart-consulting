#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPieSeries>
#include <QPieSlice>
#include <QChart>
#include <QChartView>
#include <QVBoxLayout>
#include <QDialog>
#include <QToolTip>
#include <QCursor>
#include <QSqlQuery>
#include <QSqlError>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTextDocument>
#include <QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Établir la connexion à la base de données
    cnx.createconnect();

    // Configuration du calendrier - à faire avant de charger les dates
    setupCalendar();

    // Configuration des connexions
    setupConnections();

    // Charger et afficher les tâches
    afficherTaches();
    loadReservedDates();
    loadTachesNotifications();
}

void MainWindow::setupConnections()
{
    // Connexion des boutons aux slots appropriés
    connect(ui->pushButton_16, &QPushButton::clicked, this, &MainWindow::on_btnAjouter_clicked);
    connect(ui->pushButton_19, &QPushButton::clicked, this, &MainWindow::on_btnSupprimer_clicked);
    connect(ui->pushButton_20, &QPushButton::clicked, this, &MainWindow::on_btnModifier_clicked);
    connect(ui->pushButton_recherche, &QPushButton::clicked, this, &MainWindow::on_pushButton_recherche_clicked);
    connect(ui->buttonTrier, &QPushButton::clicked, this, &MainWindow::on_buttonTrier_clicked);
    connect(ui->pushButton_statistiques, &QPushButton::clicked, this, &MainWindow::on_pushButton_statistiques_clicked);
}

void MainWindow::loadReservedDates()
{
    // Effacer les dates précédemment réservées
    reservedDates.clear();

    // Requête pour récupérer toutes les dates de tâches
    QSqlQuery query("SELECT ECHEANCE FROM TACHE");

    while (query.next()) {
        QDate taskDate = QDate::fromString(query.value(0).toString(), "yyyy-MM-dd");
        if (taskDate.isValid()) {
            reservedDates.insert(taskDate);
            qDebug() << "Date réservée ajoutée : " << taskDate.toString();
        }
    }

    // Mettre à jour l'affichage des dates réservées
    highlightReservedDates();
}

void MainWindow::highlightReservedDates()
{
    // Vérifier si le calendrier existe
    if (!calendarWidget) {
        qDebug() << "Calendrier non initialisé";
        return;
    }

    // Créer un format pour les dates réservées
    QTextCharFormat reservedFormat;
    reservedFormat.setBackground(Qt::red);
    reservedFormat.setForeground(Qt::white);
    reservedFormat.setFontWeight(QFont::Bold);

    // Réinitialiser tous les formats de date
    calendarWidget->setDateTextFormat(QDate(), QTextCharFormat());

    // Surligner les dates réservées
    for (const QDate &date : reservedDates) {
        qDebug() << "Surlignage de la date : " << date.toString();
        calendarWidget->setDateTextFormat(date, reservedFormat);
    }
}

void MainWindow::setupCalendar()
{
    // Créer le widget calendrier s'il n'existe pas déjà
    calendarWidget = new QCalendarWidget(this);

    // Configuration du calendrier
    calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    calendarWidget->setNavigationBarVisible(true);
    calendarWidget->setGridVisible(true);
    calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);

    // Configuration de palette pour éviter les problèmes de couleur
    QPalette palette = calendarWidget->palette();
    palette.setColor(QPalette::Base, Qt::white);  // Fond blanc
    palette.setColor(QPalette::Text, Qt::black);  // Texte noir
    calendarWidget->setPalette(palette);

    // Style CSS pour plus de personnalisation
    calendarWidget->setStyleSheet(R"(
        QCalendarWidget QWidget {
            background-color: white;
        }
        QCalendarWidget QToolButton {
            color: black;
            background-color: #f0f0f0;
        }
        QCalendarWidget QMenu {
            color: black;
            background-color: white;
        }
    )");

    // Configuration du layout
    QVBoxLayout *calendarLayout = new QVBoxLayout();
    calendarLayout->addWidget(calendarWidget);
    calendarLayout->setContentsMargins(0, 0, 0, 0);  // Éliminer les marges

    // Vérifier et configurer le widget dans l'UI
    if (ui->calendarWidget) {
        // Supprimer ancien layout
        QLayout* oldLayout = ui->calendarWidget->layout();
        if (oldLayout) {
            delete oldLayout;
        }

        // Appliquer nouveau layout
        ui->calendarWidget->setLayout(calendarLayout);

        // Contraintes de taille
        ui->calendarWidget->setMinimumHeight(250);  // Hauteur minimale
    } else {
        qDebug() << "Erreur : Widget calendar manquant dans l'UI";
    }

    // Connexions du calendrier
    connect(calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::onCalendarDateClicked);
    connect(calendarWidget, &QCalendarWidget::currentPageChanged, this, &MainWindow::highlightReservedDates);
}

void MainWindow::onCalendarDateClicked(const QDate &date)
{
    // Mettre à jour le champ de date d'échéance
    ui->dateEditEcheance->setDate(date);

    // Vérifier si la date est déjà réservée
    if (reservedDates.contains(date)) {
        QMessageBox::warning(this, "Date Réservée",
            "Cette date est déjà réservée pour une tâche. Voulez-vous choisir une autre date ?");
    }
}

void MainWindow::onDateChanged(const QDate &date)
{
    // Cette méthode est appelée lorsque la date change dans le dateEditEcheance
    if (reservedDates.contains(date)) {
        QMessageBox::warning(this, "Date Réservée",
                             "Cette date est déjà réservée pour une tâche. Veuillez choisir une autre date.");
    }
}

void MainWindow::updateReservedDates()
{
    // Mettre à jour la liste des dates réservées
    loadReservedDates();

    // Mettre à jour l'affichage du calendrier
    highlightReservedDates();
}

void MainWindow::on_btnAjouter_clicked()
{
    int Id = ui->lineEditID->text().toInt();
    QString nom = ui->lineEditNom->text();
    QString description = ui->lineEditDescription->text();
    int consultant = ui->lineEditConsultant->text().toInt();
    QDate dateEcheance = ui->dateEditEcheance->date();
    QString echeance = dateEcheance.toString("yyyy-MM-dd");
    QString statut = ui->comboBoxStatut->currentText();

    if (nom.isEmpty() || description.isEmpty() || ui->lineEditID->text().isEmpty() || ui->lineEditConsultant->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    // Vérification de la date
    if (reservedDates.contains(dateEcheance)) {
        QMessageBox::warning(this, "Date Réservée",
            "Cette date est déjà réservée pour une tâche. Veuillez choisir une autre date.");
        return;
    }

    if (tache.ajouterTache(Id, nom, description, consultant, echeance, statut)) {
        QMessageBox::information(this, "Succès", "Tâche ajoutée avec succès !");

        // Ajouter la nouvelle date aux dates réservées
        reservedDates.insert(dateEcheance);

        // Mettre à jour l'affichage et les dates réservées
        afficherTaches();
        highlightReservedDates();

        // Réinitialiser les champs
        ui->lineEditID->clear();
        ui->lineEditNom->clear();
        ui->lineEditDescription->clear();
        ui->lineEditConsultant->clear();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout de la tâche.");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficherTaches()
{
    QSqlQuery query("SELECT ID_TACHE, NOM, DESCRIPTION, CONSULTANT_ASSIGNE, ECHEANCE, STATUT FROM TACHE");
    int row = 0;
    ui->tableWidget->setRowCount(0); // Réinitialiser la table

    // Définir les en-têtes
    QStringList headers = {"ID", "Nom", "Description", "Consultant", "Échéance", "Statut"};
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    while (query.next()) {
        ui->tableWidget->insertRow(row);
        for (int col = 0; col < 6; ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }

    // Ajuster la largeur des colonnes
    ui->tableWidget->resizeColumnsToContents();
}

void MainWindow::loadTachesNotifications()
{
    QList<QPair<int, QString>> tachesDemain = tache.getTachesEcheanceDemain();

    QString message;

    if (tachesDemain.isEmpty()) {
        message = "🎉 Aucune tâche avec échéance demain.";
    } else {
        message = "📋 Tâches prévues pour demain :\n\n";
        for (const auto& tacheItem : tachesDemain) {
            message += QString("🔔 ID: %1 | Nom: %2\n")
                           .arg(tacheItem.first)
                           .arg(tacheItem.second);
        }
    }

    QMessageBox::information(this, "Notifications - Tâches de demain", message);
}

void MainWindow::on_btnModifier_clicked() {
    int id = ui->lineEditID->text().toInt();
    QString nom = ui->lineEditNom->text();
    QString description = ui->lineEditDescription->text();
    int consultant = ui->lineEditConsultant->text().toInt();
    QDate nouvelleDate = ui->dateEditEcheance->date();
    QString echeance = nouvelleDate.toString("yyyy-MM-dd");
    QString statut = ui->comboBoxStatut->currentText();

    // Vérifier si l'ID existe
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT ECHEANCE FROM TACHE WHERE ID_TACHE = :id");
    checkQuery.bindValue(":id", id);

    if (!checkQuery.exec() || !checkQuery.next()) {
        QMessageBox::warning(this, "Erreur", "Tâche non trouvée. Vérifiez l'ID.");
        return;
    }

    // Obtenir l'ancienne date
    QDate ancienneDate = QDate::fromString(checkQuery.value(0).toString(), "yyyy-MM-dd");

    // Si la date a changé, vérifier si la nouvelle date est déjà réservée
    if (ancienneDate != nouvelleDate && reservedDates.contains(nouvelleDate)) {
        QMessageBox::warning(this, "Date Réservée",
            "La nouvelle date est déjà réservée pour une autre tâche. Veuillez choisir une autre date.");
        return;
    }

    if (tache.modifierTache(id, nom, description, consultant, echeance, statut)) {
        QMessageBox::information(this, "Succès", "Tâche modifiée avec succès !");

        // Mettre à jour les dates réservées
        if (ancienneDate != nouvelleDate) {
            reservedDates.remove(ancienneDate);
            reservedDates.insert(nouvelleDate);
            highlightReservedDates();
        }

        afficherTaches();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la modification.");
    }
}

void MainWindow::on_btnSupprimer_clicked() {
    int id = ui->lineEditID->text().toInt();

    // Récupérer la date de la tâche avant de la supprimer
    QSqlQuery query;
    query.prepare("SELECT ECHEANCE FROM TACHE WHERE ID_TACHE = :id");
    query.bindValue(":id", id);

    QDate dateASupprimer;
    if (query.exec() && query.next()) {
        dateASupprimer = QDate::fromString(query.value(0).toString(), "yyyy-MM-dd");
    } else {
        QMessageBox::warning(this, "Erreur", "Tâche non trouvée. Vérifiez l'ID.");
        return;
    }

    if (tache.supprimerTache(id)) {
        QMessageBox::information(this, "Succès", "Tâche supprimée !");

        // Vérifier si d'autres tâches utilisent la même date
        query.prepare("SELECT COUNT(*) FROM TACHE WHERE ECHEANCE = :date");
        query.bindValue(":date", dateASupprimer.toString("yyyy-MM-dd"));

        if (query.exec() && query.next() && query.value(0).toInt() == 0) {
            // Aucune autre tâche n'utilise cette date, donc on peut la retirer
            reservedDates.remove(dateASupprimer);
            highlightReservedDates();
        }

        afficherTaches();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression.");
    }
}

void MainWindow::on_pushButton_recherche_clicked()
{
    QString critere = ui->comboBox_2->currentText();  // ex: "recherche_par_id", "recherche_par_statut", "Consultant"
    QString valeurRecherche = ui->lineEdit_recherche->text();  // ce que l'utilisateur entre

    QString requete;

    if (critere == "recherche_par_id") {
        requete = "SELECT * FROM TACHE WHERE ID_TACHE = :valeur";
    }
    else if (critere == "recherche_par_statut") {
        requete = "SELECT * FROM TACHE WHERE STATUT = :valeur";
    }
    else if (critere == "recherche_par_consultant") {
        requete = "SELECT * FROM TACHE WHERE CONSULTANT_ASSIGNE = :valeur";
    }
    else {
        QMessageBox::warning(this, "Erreur", "Critère de recherche invalide.");
        return;
    }

    QSqlQuery query;
    query.prepare(requete);
    query.bindValue(":valeur", valeurRecherche);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "La recherche a échoué : " + query.lastError().text());
        return;
    }

    // Vider le contenu précédent du QTableWidget
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);

        // On suppose que les colonnes sont dans cet ordre : ID_TACHE, NOM, DESCRIPTION, CONSULTANT_ASSIGNE, ECHEANCE, STATUT
        for (int col = 0; col < 6; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            ui->tableWidget->setItem(row, col, item);
        }
        row++;
    }
}

void MainWindow::on_buttonTrier_clicked()
{
    QString modeTri = ui->comboBox_3->currentText().trimmed();
    qDebug() << "Mode de tri sélectionné : " << modeTri;

    QString requete;

    if (modeTri == "Trier_par_Statut") {
        requete = "SELECT * FROM TACHE ORDER BY STATUT ASC";
    }
    else if (modeTri == "Trier_par_Consultant") {
        requete = "SELECT * FROM TACHE ORDER BY CONSULTANT_ASSIGNE ASC";
    }
    else if (modeTri == "Trier_par_Nom") {
        requete = "SELECT * FROM TACHE ORDER BY NOM ASC";
    }
    else {
        QMessageBox::warning(this, "Mode de tri inconnu", "Veuillez sélectionner un critère de tri valide.");
        return;
    }

    QSqlQuery query;
    if (!query.exec(requete)) {
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        return;
    }

    // Nettoyage du QTableWidget
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        for (int col = 0; col < 6; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            ui->tableWidget->setItem(row, col, item);
        }
        row++;
    }

    // Optionnel : définir les entêtes si tu veux les afficher après clearContents
    QStringList headers = {"ID_TACHE", "NOM", "DESCRIPTION", "CONSULTANT_ASSIGNE", "ECHEANCE", "STATUT"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    qDebug() << "Tri terminé et affiché dans le tableau.";
}

void MainWindow::on_pushButton_statistiques_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT STATUT, COUNT(*) FROM TACHE GROUP BY STATUT");
    query.exec();

    QPieSeries *series = new QPieSeries();
    QChart *chart = new QChart();
    chart->setTitle("Répartition des tâches par statut");

    while (query.next()) {
        QString statut = query.value(0).toString();
        int count = query.value(1).toInt();

        QPieSlice *slice = new QPieSlice(statut + " (" + QString::number(count) + ")", count);
        slice->setLabelVisible(true);
        slice->setLabelFont(QFont("Arial", 10, QFont::Bold));
        slice->setLabelPosition(QPieSlice::LabelInsideHorizontal);

        connect(slice, &QPieSlice::hovered, this, [=](bool state) {
            if (state) {
                QToolTip::showText(QCursor::pos(), "Statut: " + statut + "\nNombre de tâches: " + QString::number(count));
            } else {
                QToolTip::hideText();
            }
        });

        series->append(slice);
    }

    chart->addSeries(series);
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->setWindowTitle("Statistiques des Tâches");
    dialog->resize(600, 400);
    dialog->exec();
}

void MainWindow::on_pushButton_pdf_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT ID_TACHE, NOM, DESCRIPTION, CONSULTANT_ASSIGNE, ECHEANCE, STATUT FROM TACHE");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Problème avec la base de données.");
        return;
    }

    // HTML avec style propre
    QString html = R"(
        <html>
        <head>
            <style>
                body {
                    font-family: Arial, sans-serif;
                }
                table {
                    border-collapse: collapse;
                    width: 100%;
                    font-size: 32pt;
                }
                th, td {
                    border: 1px solid black;
                    padding: 8px;
                    text-align: center;
                }
                th {
                    background-color: #f2f2f2;
                }
                h2 {
                    text-align: center;
                    font-size: 38pt;
                    margin-bottom: 20px;
                }
            </style>
        </head>
        <body>
            <table>
                <tr>
                    <th>ID</th>
                    <th>Nom</th>
                    <th>Description</th>
                    <th>Consultant Assigné</th>
                    <th>Échéance</th>
                    <th>Statut</th>
                </tr>
    )";

    // Remplir les lignes
    while (query.next()) {
        html += "<tr>";
        for (int i = 0; i < 6; ++i) {
            html += "<td>" + query.value(i).toString().toHtmlEscaped() + "</td>";
        }
        html += "</tr>";
    }

    html += R"(
            </table>
        </body>
        </html>
    )";

    // Sélection de l'emplacement
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer PDF", "", "*.pdf");
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf")) fileName += ".pdf";

    // Création du PDF
    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setResolution(300);
    pdfWriter.setPageMargins(QMargins(50, 50, 50, 50));

    QTextDocument doc;
    doc.setHtml(html);
    doc.setPageSize(QSizeF(pdfWriter.width(), pdfWriter.height()));

    QPainter painter(&pdfWriter);
    doc.drawContents(&painter);
    painter.end();

    QMessageBox::information(this, "Succès", "PDF généré avec succès !");
}
