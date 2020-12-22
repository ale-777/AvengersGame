#ifndef MUNDO_H
#define MUNDO_H
#include "Humanos.h"
#include <QFile>
#include <QTextStream>
#include <string>
#include <QMessageBox>
#include <QString>
using namespace std ;

struct Mundo;

struct Mundo{
    ListaHumano * poblacionMundial;
    QString nombres[1000];
    QString apellidos[100];
    QString creencias[10];
    QString paises[100];
    QString profresiones[50];
    QString files[5]={"nombres","apellidos","creencias","profesiones","paises"};
    Mundo(){
        for(int i=1; i<=5;i++){
            cargarArchivos(files[i-1],i);
        }
        poblacionMundial = new ListaHumano();
    }
    void agregarPoblacion(int cantidad);
    bool verificarID(int nuevo);
    void agregarLinea(QString line,int arreglo);
    void cargarArchivos(QString path,int arreglo);
};

#endif // MUNDO_H
