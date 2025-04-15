QT += core gui sql
QT += core gui widgets sql printsupport charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    chatwindow.cpp \
    consultant.cpp \
    consultantmanager.cpp \
    database.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    register.cpp \
    reinitialisation.cpp \


HEADERS += \
    chatwindow.h \
    chatwindow.h \
    consultant.h \
    consultantmanager.h \
    database.h \
    login.h \
    mainwindow.h \
    register.h \
    reinitialisation.h \


FORMS += \
    chatwindow.ui \
    login.ui \
    mainwindow.ui \
    register.ui \
    reinitialisation.ui
    register.ui \

# Déploiement par défaut (ok)
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
