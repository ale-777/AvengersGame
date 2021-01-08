#ifndef AVENGERS_H
#define AVENGERS_H
#include <iostream>
#include <fstream>
#include <string>
#include <QtCore>
using namespace std;

struct Avengers{
    QString bitacora;

    Avengers(){
        bitacora = " ";
    }

    void generarArchivo ();

    QString Thor (int nivel);
};

#endif // AVENGERS_H
