QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT       += core gui sql network charts
QT += quick widgets location positioning sql
QT += charts sql
QT += core gui widgets sql printsupport
QT += sql
QT += core gui sql





QT       += core gui
QT += core gui widgets sql printsupport
QT += charts sql
QT += core gui serialport sql
QT += quick widgets
CONFIG += c++11
QT += charts
QT += quickwidgets
QT += quick widgets charts sql
CONFIG += c++11

QT += quick widgets location positioning sql



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT       += core gui sql network charts

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    connection.cpp \
    consultant.cpp \
<<<<<<< HEAD
=======
    mailing.cpp \
>>>>>>> c2b1c55 (gestion ressource projet consultant)
    main.cpp \
    mainwindow.cpp \
    projet.cpp \
    ressource.cpp

HEADERS += \
    client.h \
    connection.h \
    consultant.h \
<<<<<<< HEAD
=======
    mailing.h \
>>>>>>> c2b1c55 (gestion ressource projet consultant)
    mainwindow.h \
    projet.h \
    ressource.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
