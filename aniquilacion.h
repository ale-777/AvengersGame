//Editado
#ifndef ANIQUILACION_H
#define ANIQUILACION_H
#include <iostream>
#include <fstream>
#include <string>
#include <QtCore>
using namespace std;
struct ListaHumano;


struct TeamAniquileishon{
    QString bitacora;
    QString infoTemporalNebula;
    int contTemporalNebula;
    int contThanos;
    QString infoTemporalEbonyMaw;
    int contTemporalEbonyMaw;




    TeamAniquileishon(){
        bitacora=" ";
        infoTemporalNebula = "";
        contTemporalNebula = 0;
        contThanos = 0;
        infoTemporalEbonyMaw = "";
        contTemporalEbonyMaw = 0;
    }

    void generarArchivo ();
    QString Corvus ();
    QString Midnight ();
    QString Black (int rutina, QString deporte);
    QString Nebula (int id);
    QString Thanos (int,int,int);

    QString consultaThanos();

    QString EbonyMaw(int id);

};


#endif // ANIQUILACION_H
