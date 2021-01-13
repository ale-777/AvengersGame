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
    QString bitacoraAntMan;

    //Spiderman
    QString bitacoraSpiderman;
    QString infoTemporalSpiderman;
    int contTemporalSpiderman;

    QString infoTemporalIronMan;
    int contTemporalIronMan;

    int contTemporalThor;
    QString rutaHormiga;



    Avengers(){
        bitacora = " ";
        infoTemporalIronMan = " ";
        contTemporalIronMan = 0;
        bitacoraIronman = "";
        bitacoraThor = "";
        contTemporalThor = 0;
        bitacoraSpiderman = "";
        bitacoraAntMan = "";
        infoTemporalSpiderman = "";
        contTemporalSpiderman = 0;

    }

    void generarArchivo ();
    void generarArchivoPJ (QString info);

    QString Thor (int nivel);
    QString IronMan ();

    void algoritmoAntMan(int);

    QString Spiderman();

    void consultaAvengers();
    void generarArchivoHormigas ();
};

#endif // AVENGERS_H
