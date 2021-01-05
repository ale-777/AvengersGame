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
    int corvus;
    ListaHumano * listaCorvus;

    TeamAniquileishon(){
        bitacora="";
        corvus = 0;
    }

    void generarArchivo ();
    QString Corvus ();
};


#endif // ANIQUILACION_H
