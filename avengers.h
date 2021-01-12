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


    QString rutaHormiga;



    Avengers(){
        bitacora = " ";
        infoTemporalIronMan = " ";
        contTemporalIronMan = 0;
        bitacoraIronman = "";
        bitacoraThor = "";
        bitacoraSpiderman = "";
        bitacoraAntMan = "";
        infoTemporalSpiderman = "";
        contTemporalSpiderman = 0;

    }

    void generarArchivo ();

    QString Thor (int nivel);
    QString IronMan ();

    void algoritmoAntMan(int);

    QString Spiderman();

    void consultaAvengers();
    void generarArchivoHormigas ();
};

#endif // AVENGERS_H
