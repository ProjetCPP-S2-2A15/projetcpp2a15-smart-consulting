QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Ajout des fichiers sources (⚠️ Plus de doublons !)
SOURCES += \
    consultant.cpp \
    consultantmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    database.cpp  # Une seule fois !

# Ajout des fichiers d'en-tête (⚠️ Plus de doublons !)
HEADERS += \
    consultant.h \
    consultantmanager.h \
    mainwindow.h \
    database.h  # Une seule fois !

# Ajout des fichiers d'interface Qt Designer
FORMS += \
    mainwindow.ui

# Règles de déploiement par défaut
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
