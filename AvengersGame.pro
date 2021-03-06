QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Globals.cpp \
    Humanos.cpp \
    Mundo.cpp \
    aniquilacion.cpp \
    arbol.cpp \
    avengers.cpp \
    displayhumanos.cpp \
    main.cpp \
    mainwindow.cpp \
    ventanaaniquilacion.cpp \
    ventanaconsultas.cpp \
    ventanaganador.cpp \
    ventanasalvacion.cpp \
    verarbol.cpp

HEADERS += \
    Globals.h \
    Humanos.h \
    Mundo.h \
    aniquilacion.h \
    arbol.h \
    avengers.h \
    displayhumanos.h \
    mainwindow.h \
    ventanaaniquilacion.h \
    ventanaconsultas.h \
    ventanaganador.h \
    ventanasalvacion.h \
    verarbol.h

FORMS += \
    displayhumanos.ui \
    mainwindow.ui \
    ventanaaniquilacion.ui \
    ventanaconsultas.ui \
    ventanaganador.ui \
    ventanasalvacion.ui \
    verarbol.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    apellidos.txt \
    creencias.txt \
    nombres.txt \
    paises.txt \
    profesiones.txt
