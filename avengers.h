#ifndef AVENGERS_H
#define AVENGERS_H
#include <iostream>
#include <fstream>
#include <string>
#include <QtCore>
using namespace std;

struct Avengers{
    QString bitacora;

    QString bitacoraIronman;
    QString bitacoraThor;

    QString infoTemporalIronMan;
    int contTemporalIronMan;

    Avengers(){
        bitacora = " ";
        infoTemporalIronMan = " ";
        contTemporalIronMan = 0;
        bitacoraIronman = "";
        bitacoraThor = "";

    }

    void generarArchivo ();

    QString Thor (int nivel);
    QString IronMan ();
};

#endif // AVENGERS_H
