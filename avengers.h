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

    int contTemporalAntman;


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
        contTemporalAntman = 0;

    }

    QString generarArchivo ();
    QString generarArchivoPJ (QString info);

    QString Thor (int nivel);
    QString IronMan ();

    QString algoritmoAntMan(int);

    QString Spiderman();

    void consultaAvengers();
    void generarArchivoHormigas ();

    void enviarCorreoAvengers(string asunto, QString archivo);
};

#endif // AVENGERS_H
