

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projet.h"
#include "ressource.h"
#include "consultant.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>
#include <QStringListModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTextDocument>
#include <QtCore/QCoreApplication>
#include <QtGui/QPainter>
#include <QtGui/QFont>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QToolTip>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlError>
#include <QDialog>
#include <QVBoxLayout>
#include <QCursor>
#include <QtCore/QCoreApplication>
#include <QtGui/QPainter>
#include <QtGui/QFont>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QToolTip>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlError>
#include <QDialog>
#include <QVBoxLayout>
#include <QCursor>
#include <QQuickWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QSqlQuery>
#include <QQmlContext>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);

    serial->setPortName("COM14"); //
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadWrite)) {
        connect(serial, &QSerialPort::readyRead, this, &MainWindow::readSerial);
    } else {
        QMessageBox::warning(this, "Serial Error", serial->errorString());
    }

    ui->stackedWidget->setCurrentIndex(1);
// moujib crud
    connect(ui->pushButton_31, &QPushButton::clicked, this, &MainWindow::on_pushButton_9_clicked);
    // Connecter le bouton pushButton_4 à la fonction showPage1
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::showPage1);
    //  connecter le bouton ressource à page 2
    connect(ui->pushButton_19, &QPushButton::clicked, this, &MainWindow::showPage2);
    //
     connect(ui->pushButton_22, &QPushButton::clicked, this, &MainWindow::showPage3);
    //connecter bouton connexion à page 4
     connect(ui->pushButton_connexion, &QPushButton::clicked, this, &MainWindow::on_pushButton_connexion_clicked);
    // page 5
      connect(ui->pushButton_inscription, &QPushButton::clicked, this, &MainWindow::showPage5);
   // retour page 3
      connect(ui->pushButton_37, &QPushButton::clicked, this, &MainWindow::showHomePage3);
       connect(ui->pushButton_38, &QPushButton::clicked, this, &MainWindow::showHomePage3_2);
      // page 3
        connect(ui->pushButton_39, &QPushButton::clicked, this, &MainWindow::showHomePage3_2);


    //connecter le bouton retour de projet à page 1
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::showHomePage);
    //connecter le bouton retour du ressource  à page 1

    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::showHomePage2);
    connect(ui->pushButton_ajouter_2, &QPushButton::clicked, this, &::MainWindow::on_pushButton_ajouter_2_clicked);
    connect(ui->pushButton_ajouter, &QPushButton::clicked, this, &MainWindow::on_pushButton_ajouter_clicked);
    connect(ui->pushButton_afficher, &QPushButton::clicked, this, &MainWindow::on_pushButton_afficher_clicked);
    connect(ui->pushButton_supprimer, &QPushButton::clicked, this, &MainWindow::on_pushButton_supprimer_clicked);
    connect(ui->pushButton_modifier, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_clicked);
    connect(ui->pushButton_afficher_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_afficher_clicked2);
    connect(ui->pushButton_modifier_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_clicked2);
     connect(ui->pushButton_supprimer_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_supprimer_clicked2);
     connect(ui->buttonRechercher, &QPushButton::clicked, this, &MainWindow::on_buttonRechercher_clicked);
     connect(ui->buttonTrier, &QPushButton::clicked, this, &MainWindow::on_buttonTrier_clicked);
     connect(ui->pushButton_statistiques, &QPushButton::clicked, this, &MainWindow::on_pushButton_statistiques_clicked);
      connect(ui->pushButton_pdf, &QPushButton::clicked, this, &MainWindow::on_pushButton_pdf_clicked);
      connect(ui->pushButton_pdf_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_pdf_clicked2);
      connect(ui->buttonRechercher_2, &QPushButton::clicked, this, &MainWindow::on_buttonRechercher_clicked2);
       connect(ui->buttonTrier_2, &QPushButton::clicked, this, &MainWindow::on_buttonTrier_clicked2);
      connect(ui->pushButton_statistiques_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_statistiques_clicked2);
       connect(ui->pushButton_QR, &QPushButton::clicked, this, &MainWindow::on_pushButton_QR_clicked);
      // reini
        connect(ui->pushButton_valider, &QPushButton::clicked, this, &MainWindow::on_pushButton_valider_clicked);
      //motdepasse
        connect(ui->pushButton_motdepasseoublie, &QPushButton::clicked, this, &MainWindow::on_pushButton_mdp_oublie_clicked);
        //page login de consultant

        //inscrip
        connect(ui->pushButton_inscrire, &QPushButton::clicked, this, &MainWindow::on_pushButton_inscrire_clicked);
        //affichage consultant
        connect(ui->pushButton_30, &QPushButton::clicked, this, &MainWindow::loadConsultants);
        //modifier consultant
        connect(ui->pushButton_32, &QPushButton::clicked, this, &MainWindow::on_pushButton_32_clicked);
        // supprimer un consultant

         connect(ui-> pushButton_33, &QPushButton::clicked, this, &MainWindow:: on_pushButton_11_clicked);
         //pdf

         connect(ui->  pushButton_35, &QPushButton::clicked, this, &MainWindow:: on_pushButton_8_clicked);
         //stat

         connect(ui->  pushButton_36, &QPushButton::clicked, this, &MainWindow:: on_pushButton_3_clicked);
         //recherche
         connect(ui->lineEdit_specialite, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_textChanged);
         //arduini
          connect(ui->pushButton_pointage, &QPushButton::clicked, this, &MainWindow::on_pushButton_pointage_clicked);





}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::verifierIdentifiants(const QString &username, const QString &password)
{
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "⚠️ Base de données non ouverte !";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM UTILISATEUR WHERE username = 'islem' AND mot_de_passe = 'guesmi' ");
    query.bindValue(":username", username.trimmed());
    query.bindValue(":password", password.trimmed());

    if (query.exec() && query.next()) {
        return true;  // Identifiants valides
    } else {
        qDebug() << "❌ Aucune correspondance trouvée ou erreur SQL:" << query.lastError().text();
        return false;
    }
}


// bouton connexion
void MainWindow::on_pushButton_connexion_clicked()
{
    // Récupérer les données saisies par l'utilisateur
    QString username = ui->lineEdit_nom->text().trimmed();
    QString password = ui->lineEdit_password->text().trimmed();

    // Affichage dans la console pour vérification
    qDebug() << "Tentative de connexion avec:";
    qDebug() << "Nom d'utilisateur :" << username;
    qDebug() << "Mot de passe      :" << password;

    // Vérifier les identifiants dans la base de données
    if (verifierIdentifiants(username, password)) {
        qDebug() << "✅ Connexion réussie. Accès à la page 4.";
        ui->stackedWidget->setCurrentIndex(4);  // Afficher la page 4 après connexion
    } else {
        qDebug() << "❌ Connexion échouée. Identifiants incorrects.";
        QMessageBox::warning(this, "Erreur de connexion", "Nom d'utilisateur ou mot de passe incorrect.");
    }
}



// Fonction qui change la page du QStackedWidget
void MainWindow::showPage1() {
    ui->stackedWidget->setCurrentIndex(0);  // Affiche la page 1
}
// page 5
void MainWindow::showPage5()
{
    // Changer pour la page 2 (index 2)
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::showPage2()
{
    // Changer pour la page 2 (index 2)
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::showPage3()
{
    // Changer pour la page 2 (index 2)
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::showPage33()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::showPage6()
{
    // Changer pour la page 2 (index 6)
    ui->stackedWidget->setCurrentIndex(6);
}
void MainWindow::showHomePage()
{
     ui->stackedWidget->setCurrentIndex(1); // Retour à la Page 0 (index 1)
}

void MainWindow::showHomePage2()
{
    ui->stackedWidget->setCurrentIndex(1); // Retour à la Page 0 (index 1)
}
void MainWindow::showHomePage3()
{
    ui->stackedWidget->setCurrentIndex(3); // Retour à la Page 0 (index 1)
}
void MainWindow::showHomePage3_2()
{
    ui->stackedWidget->setCurrentIndex(3); // Retour à la Page 0 (index 1)
}

// inscrire
void MainWindow::on_pushButton_inscrire_clicked()
{
    qDebug() << "Inscription appelée";
    QString username = ui->lineEdit_username_2->text();
    QString password = ui->lineEdit_password_2->text();
    QString question = ui->lineEdit_question->text();
    QString reponse  = ui->lineEdit_reponse->text();

    if (username.isEmpty() || password.isEmpty() || question.isEmpty() || reponse.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs !");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO UTILISATEUR (username, mot_de_passe, question_secrete, reponse_secrete) "
                  "VALUES (:u, :p, :q, :r)");
    query.bindValue(":u", username);
    query.bindValue(":p", password);
    query.bindValue(":q", question);
    query.bindValue(":r", reponse);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Utilisateur inscrit avec succès !");
        ui->stackedWidget->setCurrentIndex(3);  // Revenir à la page de connexion
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'inscription : " + query.lastError().text());
    }
}

// reinitialisation
//motdepasse
void MainWindow::on_pushButton_mdp_oublie_clicked()
{
    QString username = ui->lineEdit_username->text().trimmed();  // Nom d'utilisateur saisi

    if (username.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez entrer votre nom d'utilisateur.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT question_secrete FROM UTILISATEUR WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        QString question = query.value(0).toString();
        utilisateurActuel = username; // mémorise l'utilisateur pour la suite
        ui->label_question->setText(question); // affiche la question sur la page suivante
        ui->stackedWidget->setCurrentIndex(6); // aller à la page de réinitialisation
    } else {
        QMessageBox::warning(this, "Erreur", "Nom d'utilisateur introuvable.");
    }
}


void MainWindow::preparerReinitialisation(const QString &username, const QString &question)
{
    utilisateurActuel = username;  // Stocker l'utilisateur pour le traitement suivant
    ui->label_question->setText(question);  // Mettre à jour l'UI avec la question secrète
    ui->stackedWidget->setCurrentIndex(6);    // Accéder à la page de réinitialisation (par exemple index 5)
}


void MainWindow::on_pushButton_valider_clicked()
{
    QString reponse = ui->lineEdit_reponse_2->text().trimmed();
    QString nouveauMDP = ui->lineEdit_nouveau_mdp->text().trimmed();

    qDebug() << "Nom utilisateur:" << utilisateurActuel;

    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Erreur", "Base de données non ouverte !");
        return;
    }

    if (reponse.isEmpty() || nouveauMDP.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT reponse_secrete FROM UTILISATEUR WHERE username = :username");
    query.bindValue(":username", utilisateurActuel);

    if (query.exec() && query.next()) {
        QString bonneReponse = query.value(0).toString();
        if (bonneReponse == reponse) {
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE UTILISATEUR SET mot_de_passe = :mdp WHERE username = :username");
            updateQuery.bindValue(":mdp", nouveauMDP);
            updateQuery.bindValue(":username", utilisateurActuel);

            if (updateQuery.exec()) {
                QMessageBox::information(this, "Succès", "Mot de passe mis à jour !");
                ui->stackedWidget->setCurrentIndex(3);
            } else {
                QMessageBox::critical(this, "Erreur", "Erreur lors de la mise à jour.");
            }
        } else {
            QMessageBox::warning(this, "Erreur", "Réponse incorrecte.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Utilisateur introuvable.");
    }
}



// ajouter consultant

// Ajouter un consultant
void MainWindow::on_pushButton_9_clicked() {
    QString email = ui->lineEdit_4->text();
    QString nom = ui->lineEdit_5->text();
    QString specialite = ui->lineEdit_7->text();
    QString disponibilite = ui->lineEdit_8->text();


    if (email.isEmpty() || nom.isEmpty() || specialite.isEmpty() || disponibilite.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs !");
        return;
    }

    // Création du consultant sans ID
    Consultant consultant(nom, email, specialite, disponibilite);
    if (consultant.ajouterConsultant(consultant)) {
        QMessageBox::information(this, "Succès", "Consultant ajouté !");

        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();

    }else {
            // QMessageBox::critical(this, "Erreur", "Échec de l'ajout du consultant ");
        }

}
// ajouter un projet
void MainWindow::on_pushButton_ajouter_2_clicked()
{
    int id_projet = ui->lineEdit_id_2->text().toInt();
    QString nom = ui->lineEdit_nom_3->text();
    QString description = ui->lineEdit_description_3->text();
    QString statut = ui->lineEdit_statut_->text();

    Projet p(id_projet, nom, description, statut);
    if (p.ajouter()) {
        QMessageBox::information(this, "Succès", "Projet ajouté avec succès");
    } else {
        // QMessageBox::critical(this, "Erreur", "Échec de l'ajout du projet");
    }
}
//affichage consultant
void MainWindow::loadConsultants() {
    QSqlQuery query;
    query.prepare("SELECT id_consultant, nom, email, specialite, disponibilite FROM CONSULTANT");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec du chargement des consultants !");
        return;
    }

    ui->tableWidget->clear();  // Nettoyer la table avant d'ajouter de nouvelles données
    ui->tableWidget->setRowCount(0);  // Réinitialiser le nombre de lignes
    ui->tableWidget->setColumnCount(5);  // Assurer le bon nombre de colonnes

    QStringList headers = {"ID", "Nom", "Email", "Spécialité", "Disponibilité"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);  // Définir les en-têtes

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("id_consultant").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("nom").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("email").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("specialite").toString()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("disponibilite").toString()));
        row++;
    }
    ui->tableWidget->sortItems(1, Qt::AscendingOrder); // colonne 1 = nom

}

void MainWindow::on_pushButton_32_clicked() {
    int row = ui->tableWidget->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner un consultant !");
        return;
    }

    // Lire l'ancien email depuis la table (colonne 2 → email)
    QString ancienEmail = ui->tableWidget->item(row, 2)->text();

    // Lire les nouvelles valeurs depuis les champs
    QString nom = ui->lineEdit_4->text();
    QString email = ui->lineEdit_2->text();
    QString specialite = ui->lineEdit_5->text();
    QString disponibilite = ui->lineEdit_7->text();

    Consultant consultant(nom, email, specialite, disponibilite);
    if (consultant.modifierConsultant(ancienEmail, consultant)) {
        QMessageBox::information(this, "Succès", "Consultant modifié !");

    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification !");
    }
}


// Supprimer un consultant
void MainWindow::on_pushButton_11_clicked() {
    int row = ui->tableWidget->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner un consultant !");
        return;
    }

    int id = ui->tableWidget->item(row, 0)->text().toInt();

    if (consultant->supprimerConsultant(id)) {
        QMessageBox::information(this, "Succès", "Consultant supprimé !");
        loadConsultants();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression !");
    }
}

//ajouter ressource

void MainWindow::on_pushButton_ajouter_clicked()
{

    qDebug() << "ajouter 1 :";

    int id_ressource = ui->lineEdit_id->text().toInt();
    QString type = ui->lineEdit_type->text();
    QString nom = ui->lineEdit_nom->text();
    QString description = ui->lineEdit_description->text();
    QString disponibilite = ui->lineEdit_disponibilite->text();
    QString fournisseur = ui->lineEdit_fournisseur->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString phone = ui->lineEdit_phone->text();

    qDebug() << "ajouter 2 :";


    Ressource r(id_ressource, type, nom, description, disponibilite, fournisseur, adresse, phone);
        // Set values and attempt to add the Fournisseur to the database

    qDebug() << "ajouter 3 :";

    res.setId(id_ressource);
    res.setType(type);
    res.setNom(nom);
    res.setDescription(description);
    res.setDisponibilite(disponibilite);
    res.setFournisseur(fournisseur);
    res.setAdresse(adresse);
    res.setPhone(phone);


    if (r.ajouter()) {
        qDebug() << "ajouter 4 :";


        QMessageBox::information(this, "Success", "Ressource added successfully.");
        //  trayIcon->showMessage("Notification", "Ressource added successfully.", QSystemTrayIcon::Information, 3000);



        // Create a custom message using the input data
        QString message = QString("Hello! A new ressource has been added:\n"
                                  "Nom: %1\n"
                                  "Type: %2\n"
                                  "fournisseur: %3\n"
                                  "adresse: %4")
                              .arg(nom)
                              .arg(type)
                              .arg(fournisseur)
                              .arg(adresse);




        // Clear fields and refresh table
        /*ui->ID->clear();
        ui->nom->clear();
        ui->contact->clear();
        ui->telephone->clear();
        ui->paiement->setCurrentIndex(0);
        ui->tableView->setModel(FTemp.afficher());*/
    }
}

void MainWindow::on_pushButton_afficher_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM projet");

    QSqlQueryModel *model = new QSqlQueryModel(this);
    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, tr("ID Projet"));
        model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, tr("Description"));
        model->setHeaderData(3, Qt::Horizontal, tr("Statut"));
    }

    ui->tableView->setModel(model);
}
void MainWindow::on_pushButton_supprimer_clicked()
{
    int id_projet = ui->lineEdit_id_2->text().toInt();
    Projet p;
    if (p.supprimer(id_projet)) {
        QMessageBox::information(this, "Succès", "Projet supprimé avec succès");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression du projet");
    }
}
void MainWindow::on_pushButton_modifier_clicked()
{
    int id_projet = ui->lineEdit_id_2->text().toInt();
    QString nom = ui->lineEdit_nom_3->text();
    QString description = ui->lineEdit_description_3->text();
    QString statut = ui->lineEdit_statut_->text();

    Projet p(id_projet, nom, description, statut);
    if (p.modifier(id_projet)) {
        QMessageBox::information(this, "Succès", "Projet modifié avec succès");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la modification du projet");
    }
}


void MainWindow::on_pushButton_afficher_clicked2()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM ressource");

    QSqlQueryModel *model = new QSqlQueryModel(this);

    if (query.exec()) {
        model->setQuery(query);
        // Si vous souhaitez personnaliser les en-têtes de colonne
        model->setHeaderData(0, Qt::Horizontal, tr("ID Ressource"));
        model->setHeaderData(1, Qt::Horizontal, tr("Type"));
        model->setHeaderData(2, Qt::Horizontal, tr("Nom"));
        model->setHeaderData(3, Qt::Horizontal, tr("Description"));
        model->setHeaderData(4, Qt::Horizontal, tr("Disponibilité"));
        model->setHeaderData(5, Qt::Horizontal, tr("Fournisseur"));
        model->setHeaderData(6, Qt::Horizontal, tr("Adresse"));
        model->setHeaderData(7, Qt::Horizontal, tr("Téléphone"));
    } else {
        // Gestion de l'erreur
    }

    ui->tableView_2->setModel(model);
}

void MainWindow::on_pushButton_modifier_clicked2()
{
    int id_ressource = ui->lineEdit_id->text().toInt();
    QString type = ui->lineEdit_type->text();
    QString nom = ui->lineEdit_nom->text();
    QString description = ui->lineEdit_description->text();
    QString disponibilite = ui->lineEdit_disponibilite->text();
    QString fournisseur = ui->lineEdit_fournisseur->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString phone = ui->lineEdit_phone->text();

    Ressource r(id_ressource, type, nom, description, disponibilite, fournisseur, adresse, phone);
    if (r.modifier(id_ressource)) {
        QMessageBox::information(this, "Succès", "Ressource modifiée avec succès");
    } else {
    }
}

void MainWindow::on_pushButton_supprimer_clicked2()
{
    int id_ressource = ui->lineEdit_id->text().toInt();
    Ressource r;
    if (r.supprimer(id_ressource)) {
        QMessageBox::information(this, "Succès", "Ressource supprimée avec succès");
    } else {
    }
}


void MainWindow::on_buttonRechercher_clicked()
{
    QString input = ui->lineEdit_recherche_3->text().trimmed();
    QString modeRecherche = ui->comboBox_18->currentText().trimmed();
    qDebug() << "Mode de recherche sélectionné :" << modeRecherche;

    // Recherche par ID de projet
    if (modeRecherche == "Rechercher_par_ID") {
        QRegularExpression regex("^\\d+$");
        if (!regex.match(input).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Veuillez entrer un identifiant valide (nombre entier).");
            return;
        }

        int idProjet = input.toInt();

        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("SELECT id_projet, nom, description, statut FROM projet WHERE id_projet = :idProjet");
        query.bindValue(":idProjet", idProjet);

        if (!query.exec()) {
            QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
            return;
        }

        if (query.size() == 0) {
            QMessageBox::information(this, "Aucune correspondance", "Aucun projet trouvé avec cet identifiant.");
            return;
        }

        model->setQuery(std::move(query));
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    }

    // Recherche par nom de projet
    else if (modeRecherche == "Rechercher_par_Nom") {
        if (input.isEmpty()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le nom du projet ne peut pas être vide.");
            return;
        }

        // Exécution de la requête pour rechercher par nom
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("SELECT id_projet, nom, description, statut FROM projet WHERE nom LIKE :nom");
        query.bindValue(":nom", "%" + input + "%");

        if (!query.exec()) {
            QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
            return;
        }

        if (query.size() == 0) {
            QMessageBox::information(this, "Aucune correspondance", "Aucun projet trouvé avec ce nom.");
            return;
        }

        model->setQuery(std::move(query));
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    }

    // Recherche par statut (texte)
    else if (modeRecherche == "Rechercher_par_Statut") {
        if (input.isEmpty()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le statut ne peut pas être vide.");
            return;
        }

        // Exécution de la requête pour rechercher par statut
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("SELECT id_projet, nom, description, statut FROM projet WHERE statut LIKE :statut");
        query.bindValue(":statut", "%" + input + "%");

        if (!query.exec()) {
            QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
            return;
        }

        if (query.size() == 0) {
            QMessageBox::information(this, "Aucune correspondance", "Aucun projet trouvé avec ce statut.");
            return;
        }

        model->setQuery(std::move(query));
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    }

    else {
        QMessageBox::warning(this, "Mode inconnu", "Mode de recherche inconnu");
    }
}


void MainWindow::on_buttonTrier_clicked()
{
    QString modeTri = ui->comboBox_10->currentText().trimmed();
    qDebug() << "Mode de tri sélectionné : " << modeTri;

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Determine the column to sort based on user selection
    if (modeTri == "Trier_par_ID") {
        // Tri par ID du projet
        query.prepare("SELECT id_projet, nom, description, statut "
                      "FROM projet ORDER BY id_projet ASC");
    }
    else if (modeTri == "Trier_par_Nom") {
        // Tri par nom du projet
        query.prepare("SELECT id_projet, nom, description, statut "
                      "FROM projet ORDER BY nom ASC");
    }
    else if (modeTri == "Trier_par_Description") {
        // Tri par description du projet
        query.prepare("SELECT id_projet, nom, description, statut "
                      "FROM projet ORDER BY description ASC");
    }
    else if (modeTri == "Trier_par_Statut") {
        // Tri par statut du projet
        query.prepare("SELECT id_projet, nom, description, statut "
                      "FROM projet ORDER BY statut ASC");
    }
    else {
        QMessageBox::warning(this, "Mode de tri inconnu", "Mode de tri inconnu.");
        return;
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        return;
    }

    qDebug() << "Requête exécutée avec succès !";

    if (query.size() == 0) {
        QMessageBox::information(this, "Aucun résultat", "Aucun projet trouvé.");
    } else {
        model->setQuery(query);

        // Définir les en-têtes des colonnes pour les projets
        model->setHeaderData(0, Qt::Horizontal, "ID Projet");
        model->setHeaderData(1, Qt::Horizontal, "Nom");
        model->setHeaderData(2, Qt::Horizontal, "Description");
        model->setHeaderData(3, Qt::Horizontal, "Statut");

        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();

        qDebug() << "Données affichées dans le tableau.";
    }
}
void MainWindow::on_pushButton_statistiques_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT statut, COUNT(*) FROM projet GROUP BY statut");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        return;
    }

    // Create a pie chart series
    QPieSeries *series = new QPieSeries();

    // Create a chart object to add the slices
    QChart *chart = new QChart();
    chart->setTitle("Répartition des projets (par statut)");

    while (query.next()) {
        QString statut = query.value(0).toString();  // Get the status of the project
        int count = query.value(1).toInt();          // Count of projects with that status

        // Create a slice for each distinct statut
        QPieSlice *slice = new QPieSlice(statut, count);
        slice->setLabelVisible(true);

        // Set the label to display the statut and the count
        QString label = statut + ": " + QString::number(count) + " projets";
        slice->setLabel(label);
        slice->setLabelPosition(QPieSlice::LabelInsideHorizontal);
        slice->setLabelFont(QFont("Arial", 6, QFont::Bold));

        // Connect hover signal to show tooltip
        connect(slice, &QPieSlice::hovered, this, [=](bool state){
            if (state) {
                QToolTip::showText(QCursor::pos(),
                                   "Statut: " + statut +
                                       "\nNombre de projets: " + QString::number(count));
            } else {
                QToolTip::hideText();
            }
        });

        // Append the slice to the series
        series->append(slice);
    }

    // Add the series to the chart
    chart->addSeries(series);

    // Set up the chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create a dialog to display the chart
    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->setWindowTitle("Statistiques");
    dialog->resize(700, 500);
    dialog->exec();
}


void MainWindow::on_pushButton_pdf_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT id_projet, nom, description, statut FROM projet");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Problème avec la base de données.");
        return;
    }

    // HTML avec grande taille de police et titre bien visible
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
                    font-size: 48px; /* taille de police réduite pour plus d'espace */
                }
                th, td {
                    border: 1px solid black;
                    padding: 17px;
                    text-align: center;
                }
                th {
                    background-color: #f2f2f2;
                }
            </style>
        </head>
        <body>
            <table>
                <tr>
                    <th>ID Projet</th>
                    <th>Nom</th>
                    <th>Description</th>
                    <th>Statut</th>
                </tr>
    )";

    // Remplissage du tableau avec les données de la table 'projet'
    while (query.next()) {
        html += "<tr>";
        html += "<td>" + query.value(0).toString() + "</td>";
        html += "<td>" + query.value(1).toString() + "</td>";
        html += "<td>" + query.value(2).toString() + "</td>";
        html += "<td>" + query.value(3).toString() + "</td>";
        html += "</tr>";
    }

    html += R"(
            </table>
        </body>
        </html>
    )";

    // Choix du fichier
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer PDF", "", "*.pdf");
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf")) fileName += ".pdf";

    // Configuration du PDF
    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setResolution(300); // haute qualité
    pdfWriter.setPageMargins(QMargins(60, 60, 60, 60)); // marges

    QTextDocument doc;
    doc.setHtml(html);
    doc.setPageSize(QSizeF(pdfWriter.width(), pdfWriter.height()));

    QPainter painter(&pdfWriter);
    doc.drawContents(&painter);
    painter.end();

    QMessageBox::information(this, "Succès", "PDF généré avec succès !");
}



void MainWindow::on_pushButton_pdf_clicked2()
{
    QSqlQuery query;
    query.prepare("SELECT id_ressource, type, nom, description, disponibilite, fournisseur, adresse, phone FROM ressource");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Problème avec la base de données.");
        return;
    }

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
                    font-size: 36px;
                }
                th, td {
                    border: 1px solid black;
                    padding: 8px;
                    text-align: center;
                }
                th {
                    background-color: #f2f2f2;
                }
            </style>
        </head>
        <body>            <table>
                <tr>
                    <th>ID</th>
                    <th>Type</th>
                    <th>Nom</th>
                    <th>Description</th>
                    <th>Disponibilité</th>
                    <th>Fournisseur</th>
                    <th>Adresse</th>
                    <th>Téléphone</th>
                </tr>
    )";

    while (query.next()) {
        html += "<tr>";
        for (int i = 0; i < 8; ++i) {
            html += "<td>" + query.value(i).toString() + "</td>";
        }
        html += "</tr>";
    }

    html += R"(
            </table>
        </body>
        </html>
    )";

    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer PDF", "", "*.pdf");
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf")) fileName += ".pdf";

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setResolution(300);
    pdfWriter.setPageMargins(QMargins(60, 60, 60, 60));

    QTextDocument doc;
    doc.setHtml(html);
    doc.setPageSize(QSizeF(pdfWriter.width(), pdfWriter.height()));

    QPainter painter(&pdfWriter);
    doc.drawContents(&painter);
    painter.end();

    QMessageBox::information(this, "Succès", "PDF généré avec succès !");
}


void MainWindow::on_buttonRechercher_clicked2()
{
    QString input = ui->lineEdit_recherche_4->text().trimmed();
    QString modeRecherche = ui->comboBox_19->currentText().trimmed();
    qDebug() << "Mode de recherche sélectionné :" << modeRecherche;

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Recherche par ID
    if (modeRecherche == "Rechercher_par_ID") {
        QRegularExpression regex("^\\d+$");
        if (!regex.match(input).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Veuillez entrer un ID valide (nombre entier).");
            return;
        }

        query.prepare("SELECT * FROM ressource WHERE id_ressource = :id");
        query.bindValue(":id", input.toInt());


    }


    // Recherche par nom
    else if (modeRecherche == "Rechercher_par_Nom") {
        if (input.isEmpty()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le champ nom ne peut pas être vide.");
            return;
        }

        query.prepare("SELECT * FROM ressource WHERE nom LIKE :nom");
        query.bindValue(":nom", "%" + input + "%");


    }

    // Recherche par type
    else if (modeRecherche == "Rechercher_par_Type") {
        if (input.isEmpty()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le champ type ne peut pas être vide.");
            return;
        }

        query.prepare("SELECT * FROM ressource WHERE type LIKE :type");
        query.bindValue(":type", "%" + input + "%");


    }

    // Recherche par disponibilité
    else if (modeRecherche == "Rechercher_par_Disponibilite") {
        if (input.isEmpty()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le champ disponibilité ne peut pas être vide.");
            return;
        }

        query.prepare("SELECT * FROM ressource WHERE disponibilite LIKE :dispo");
        query.bindValue(":dispo", "%" + input + "%");
    }

    // Recherche par fournisseur
    else if (modeRecherche == "Rechercher_par_Fournisseur") {
        if (input.isEmpty()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le champ fournisseur ne peut pas être vide.");
            return;
        }

        query.prepare("SELECT * FROM ressource WHERE fournisseur LIKE :fournisseur");
        query.bindValue(":fournisseur", "%" + input + "%");



    }

    else {
        QMessageBox::warning(this, "Mode inconnu", "Mode de recherche inconnu");
        return;
    }

    // Exécution de la requête
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        return;
    }
    model->setQuery(std::move(query));
    ui->tableView_2->setModel(model);
    ui->tableView_2->resizeColumnsToContents();

}



void MainWindow::on_buttonTrier_clicked2()
{
    QString modeTri = ui->comboBox_188->currentText().trimmed();
    qDebug() << "Mode de tri sélectionné : " << modeTri;

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    if (modeTri == "Trier_par_ID") {
        // Tri par ID de ressource
        query.prepare("SELECT * FROM ressource ORDER BY id_ressource ASC");
    }
    else if (modeTri == "Trier_par_Nom") {
        // Tri par nom
        query.prepare("SELECT * FROM ressource ORDER BY nom ASC");
    }
    else if (modeTri == "Trier_par_Type") {
        // Tri par type
        query.prepare("SELECT * FROM ressource ORDER BY type ASC");
    }
    else if (modeTri == "Trier_par_Disponibilite") {
        // Tri par disponibilité
        query.prepare("SELECT * FROM ressource ORDER BY disponibilite ASC");
    }
    else if (modeTri == "Trier_par_Fournisseur") {
        // Tri par fournisseur
        query.prepare("SELECT * FROM ressource ORDER BY fournisseur ASC");
    }
    else if (modeTri == "Trier_par_Adresse") {
        // Tri par adresse
        query.prepare("SELECT * FROM ressource ORDER BY adresse ASC");
    }
    else if (modeTri == "Trier_par_Phone") {
        // Tri par téléphone (numérique ou alphabétique)
        query.prepare("SELECT * FROM ressource ORDER BY phone ASC");
    }
    else {
        QMessageBox::warning(this, "Mode de tri inconnu", "Mode de tri inconnu.");
        return;
    }

    // Exécution de la requête
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        return;
    }

    qDebug() << "Requête exécutée avec succès !";

    // Si aucune donnée n'est retournée
    if (query.size() == 0) {
        QMessageBox::information(this, "Aucun résultat", "Aucune ressource trouvée.");
    } else {
        model->setQuery(query);

        // Définir les en-têtes des colonnes pour la table des ressources
        model->setHeaderData(0, Qt::Horizontal, "ID Ressource");
        model->setHeaderData(1, Qt::Horizontal, "Type");
        model->setHeaderData(2, Qt::Horizontal, "Nom");
        model->setHeaderData(3, Qt::Horizontal, "Description");
        model->setHeaderData(4, Qt::Horizontal, "Disponibilité");
        model->setHeaderData(5, Qt::Horizontal, "Fournisseur");
        model->setHeaderData(6, Qt::Horizontal, "Adresse");
        model->setHeaderData(7, Qt::Horizontal, "Téléphone");

        // Mettre à jour le modèle dans le tableau
        ui->tableView_2->setModel(model);
        ui->tableView_2->resizeColumnsToContents();

        qDebug() << "Données triées et affichées dans le tableau.";
    }
}


void MainWindow::on_pushButton_statistiques_clicked2()
{
    // Préparer la requête pour récupérer les types et le nombre de ressources pour chaque type
    QSqlQuery query;
    query.prepare("SELECT type, COUNT(*) FROM ressource GROUP BY type");
    query.exec();

    // Créer un objet QPieSeries pour les tranches du graphique
    QPieSeries *series = new QPieSeries();

    // Créer un graphique QChart pour ajouter les tranches
    QChart *chart = new QChart();
    chart->setTitle("Répartition des ressources par type");

    // Traiter chaque ligne de résultat et ajouter une tranche au graphique
    while (query.next()) {
        QString type = query.value(0).toString();  // Récupère le type
        int count = query.value(1).toInt();       // Nombre de ressources pour ce type

        // Créer une tranche pour chaque type
        QPieSlice *slice = new QPieSlice(type, count);  // Le label est le type et la taille est le nombre
        slice->setLabelVisible(true);  // Afficher l'étiquette sur la tranche

        // Définir l'étiquette pour chaque tranche avec le nom du type et le nombre de ressources
        QString label = type + " (" + QString::number(count) + " ressources)";
        slice->setLabel(label);

        // Ajouter la tranche à la série
        series->append(slice);
    }

    // Ajouter la série de tranches au graphique

    chart->addSeries(series);

    // Configurer l'angle du demi-cercle (le graphique sera un demi-cercle)
    series->setPieStartAngle(0);
    series->setPieEndAngle(180);

    // Créer un QChartView pour afficher le graphique avec le rendu antialiasing
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Créer un dialogue pour afficher le graphique dans une fenêtre séparée
    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->setWindowTitle("Statistiques des Ressources par Type");
    dialog->resize(700, 500);  // Redimensionner la fenêtre du graphique
    dialog->exec();  // Afficher la fenêtre de statistiques
}


void MainWindow::on_pushButton_QR_clicked()
{
    // Répertoire pour enregistrer les QR codes
    QString outputDir = QString("%1/QR_Codes").arg(QDir::currentPath());
    if (!QDir(outputDir).exists()) {
        if (QDir().mkdir(outputDir)) {
            qDebug() << "Répertoire créé pour les QR codes : " << outputDir;
        } else {
            QMessageBox::critical(this, "Erreur", "Impossible de créer le répertoire pour les QR codes.");
            return;
        }
    }

    // Vérifier si qrencode.exe existe
    QString qrencodePath = "Document/integrationEssay2/build/qr_generator.exe";
    if (!QFile::exists(qrencodePath)) {
        QMessageBox::critical(this, "Erreur", QString("Le fichier qrencode.exe est introuvable au chemin : %1").arg(qrencodePath));
        qDebug() << "Le fichier qrencode.exe est introuvable.";
        return;
    } else {
        qDebug() << "qrencode.exe trouvé à : " << qrencodePath;
    }

    // Requête SQL pour récupérer les projets
    QSqlQuery query;
    if (!query.exec("SELECT id_projet, nom, description, statut FROM projet")) {
        QString errorMsg = QString("Erreur SQL : %1").arg(query.lastError().text());
        QMessageBox::critical(this, "Erreur SQL", errorMsg);
        qDebug() << errorMsg;
        return;
    }

    // Parcourir les projets et générer un QR code pour chacun
    while (query.next()) {
        QString idProjet = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString description = query.value(2).toString();
        QString statut = query.value(3).toString();

        // Contenu à encoder dans le QR code
        QString qrCodeData = QString("Projet ID: %1\nNom: %2\nDescription: %3\nStatut: %4")
                                 .arg(idProjet).arg(nom).arg(description).arg(statut);

        QString filePath = QString("%1/Projet_%2.png").arg(outputDir).arg(idProjet);

        // Commande pour générer le QR code
        QString command = QString("\"%1\" -o \"%2\" \"%3\"")
                              .arg(qrencodePath)
                              .arg(filePath)
                              .arg(qrCodeData);

        qDebug() << "Commande générée : " << command;

        // Exécuter le processus
        QProcess process;
        process.start(command);

        if (!process.waitForStarted()) {
            QMessageBox::critical(this, "Erreur", QString("Impossible de démarrer le processus pour générer le QR code : %1").arg(command));
            qDebug() << "Impossible de démarrer le processus : " << command;
            return;
        }

        if (!process.waitForFinished()) {
            QMessageBox::critical(this, "Erreur", QString("Échec de l'exécution de la commande : %1").arg(command));
            qDebug() << "Commande échouée : " << command;
            return;
        }

        // Vérifier si le fichier QR code a été généré
        if (!QFile::exists(filePath)) {
            qDebug() << "Échec de génération pour ID projet : " << idProjet << ", fichier attendu : " << filePath;
        } else {
            QImage qrImage(filePath);
            if (qrImage.isNull()) {
                qDebug() << "Échec de chargement de l'image : " << filePath;
                continue;
            }

            int textHeight = 30;
            QImage newImage(qrImage.width(), qrImage.height() + textHeight, QImage::Format_RGB32);
            newImage.fill(Qt::white);

            QPainter painter(&newImage);
            painter.drawImage(0, 0, qrImage);

            painter.setPen(QPen(Qt::black));
            painter.setFont(QFont("Arial", 12));
            QString text = nom;
            int textWidth = painter.fontMetrics().horizontalAdvance(text);
            int x = (newImage.width() - textWidth) / 2;
            int y = qrImage.height() + 20;
            painter.drawText(x, y, text);
            painter.end();

            // Sauvegarder l'image modifiée avec texte
            if (!newImage.save(filePath)) {
                qDebug() << "Échec de la sauvegarde de l'image avec texte : " << filePath;
            } else {
                qDebug() << "QR code généré avec texte pour le projet : " << nom << ", fichier : " << filePath;
            }
        }
    }

    QMessageBox::information(this, "Succès", QString("Les QR codes ont été générés dans : %1").arg(outputDir));
    qDebug() << "Génération des QR codes terminée avec succès.";
}



#include <QRegularExpression>
#include <QtSerialPort/QSerialPort>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>


void MainWindow::readSerial() {
    // Tant qu’il y a des lignes complètes à lire...
    while (serial->canReadLine()) {
        QByteArray line = serial->readLine();
        QString text = QString::fromUtf8(line).trimmed();
        qDebug() << "[SERIAL] Ligne reçue:" << text;

        // On ne garde que les chaînes hex majuscules (4 à 20 caractères)
        static const QRegularExpression rx("^[0-9A-F]{4,20}$");
        if (!rx.match(text).hasMatch()) {
            qDebug() << "[SERIAL] Ignorée (pas un UID valide)";
            continue;
        }

        // Normalisation en majuscules
        QString code = text.toUpper();
        qDebug() << "[SERIAL] UID valide détecté:" << code;

        checkRFID(code);
    }
}


void MainWindow::checkRFID(const QString &rfid) {
    QString code = rfid.trimmed().toUpper();

    QSqlQuery query;
    const QString sql = R"(
        SELECT STATUT
          FROM PROJET
         WHERE TRIM(UPPER(RFID)) = :rfid
    )";
    query.prepare(sql);
    query.bindValue(":rfid", code);

    qDebug() << "[SQL] Testing RFID value:" << code;

    if (!query.exec()) {
        qDebug() << "[SQL] Exec error:" << query.lastError().text();
        QMessageBox::critical(this,
                              "Database Error",
                              query.lastError().text());
        serial->write("CLOSE\n");
        return;
    }

    int count = 0;
    QString statut;
    while (query.next()) {
        statut = query.value(0).toString();
        ++count;
        qDebug() << "[SQL] Statut trouvé:" << statut;
    }
    qDebug() << "[SQL] Lignes matchées:" << count;

    if (count == 0) {
        QMessageBox::warning(this,
                             "RFID introuvable",
                             QString("Aucun projet associé à ce RFID '%1'.").arg(code));
        serial->write("CLOSE\n");
        return;
    }

    statut = statut.trimmed().toLower();
    if (statut == "terminé" || statut == "termine") {
        QMessageBox::information(this,
                                 "Accès autorisé",
                                 QString("Statut 'terminé' pour RFID '%1'").arg(code));
        serial->write("OPEN\n");
    } else {
        QMessageBox::warning(this,
                             "Accès refusé",
                             QString("Statut '%1' ≠ 'terminé' pour RFID '%2'")
                                 .arg(statut).arg(code));
        serial->write("CLOSE\n");
    }
}

// pdf consultant
void MainWindow::on_pushButton_8_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT id_consultant, nom, email, specialite, disponibilite FROM CONSULTANT");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Problème avec la base de données.");
        return;
    }

    // HTML avec grande taille de police et titre bien visible
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
                    font-size: 48px; /* taille de police réduite pour plus d'espace */
                }
                th, td {
                    border: 1px solid black;
                    padding: 17px;
                    text-align: center;
                }
                th {
                    background-color: #f2f2f2;
                }
            </style>
        </head>
        <body>
            <table>
                <tr>
                    <th>ID Projet</th>
                    <th>Nom</th>
                    <th>Description</th>
                    <th>Statut</th>
                </tr>
    )";

    // Remplissage du tableau avec les données de la table 'projet'
    while (query.next()) {
        html += "<tr>";
        html += "<td>" + query.value(0).toString() + "</td>";
        html += "<td>" + query.value(1).toString() + "</td>";
        html += "<td>" + query.value(2).toString() + "</td>";
        html += "<td>" + query.value(3).toString() + "</td>";
        html += "</tr>";
    }

    html += R"(
            </table>
        </body>
        </html>
    )";

    // Choix du fichier
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer PDF", "", "*.pdf");
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf")) fileName += ".pdf";

    // Configuration du PDF
    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setResolution(300); // haute qualité
    pdfWriter.setPageMargins(QMargins(60, 60, 60, 60)); // marges

    QTextDocument doc;
    doc.setHtml(html);
    doc.setPageSize(QSizeF(pdfWriter.width(), pdfWriter.height()));

    QPainter painter(&pdfWriter);
    doc.drawContents(&painter);
    painter.end();

    QMessageBox::information(this, "Succès", "PDF généré avec succès !");
}

//stat consultant
void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT disponibilite, COUNT(*) FROM consultant GROUP BY disponibilite");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        return;
    }

    // Create a pie chart series
    QPieSeries *series = new QPieSeries();

    // Create a chart object to add the slices
    QChart *chart = new QChart();
    chart->setTitle("statistiques des consultants");

    while (query.next()) {
        QString statut = query.value(0).toString();  // Get the status of the project
        int count = query.value(1).toInt();          // Count of projects with that status

        // Create a slice for each distinct statut
        QPieSlice *slice = new QPieSlice(statut, count);
        slice->setLabelVisible(true);

        // Set the label to display the statut and the count
        QString label = statut + ": " + QString::number(count) + " consultants";
        slice->setLabel(label);
        slice->setLabelPosition(QPieSlice::LabelInsideHorizontal);
        slice->setLabelFont(QFont("Arial", 6, QFont::Bold));

        // Connect hover signal to show tooltip
        connect(slice, &QPieSlice::hovered, this, [=](bool state){
            if (state) {
                QToolTip::showText(QCursor::pos(),
                                   "Statut: " + statut +
                                       "\nNombre  des consultants: " + QString::number(count));
            } else {
                QToolTip::hideText();
            }
        });

        // Append the slice to the series
        series->append(slice);
    }

    // Add the series to the chart
    chart->addSeries(series);

    // Set up the chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create a dialog to display the chart
    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->setWindowTitle("Statistiques");
    dialog->resize(700, 500);
    dialog->exec();
}

//rechercher consultant

void MainWindow::on_lineEdit_textChanged(const QString &text)
{
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *item = ui->tableWidget->item(row, 3); // colonne 3 = spécialité
        if (item && !item->text().contains(text, Qt::CaseInsensitive)) {
            ui->tableWidget->setRowHidden(row, true);
        } else {
            ui->tableWidget->setRowHidden(row, false);
        }
    }
}

//arduino moujib

void MainWindow::on_pushButton_pointage_clicked()
{
    if (!arduino->isOpen()) {
        arduino->setPortName("COM7"); // adapte le COM port
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);

        if (!arduino->open(QIODevice::ReadWrite)) {
            QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le port série !");
            return;
        }

        connect(arduino, &QSerialPort::readyRead, this, &MainWindow::lireDonneesArduino);
    }
    QMessageBox::information(this, "Pointage", "Tapez votre ID sur le clavier Arduino.");
}

void MainWindow::lireDonneesArduino()
{
    serialBuffer += arduino->readAll();
    if (serialBuffer.contains("\n")) { // On attend un retour chariot (\n)
        QString id = serialBuffer.trimmed(); // Trim le \n et espaces
        serialBuffer.clear(); // clear au lieu de = ""

        qDebug() << "ID reçu : " << id;

        QSqlQuery query;
        query.prepare("SELECT * FROM consultant WHERE id_consultant = :id");
        query.bindValue(":id", id.toInt());
        if (query.exec() && query.next()) {
            arduino->write("Bienvenue\n"); // Envoyer le message à Arduino
            qDebug() << "Consultant trouvé. Message Bienvenue envoyé.";
        } else {
            arduino->write("Erreur ID\n");
            qDebug() << "Consultant introuvable. Message Erreur ID envoyé.";
        }
    }
}
