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
        poblacionMundial = new ListaHumano();
        for(int i=1; i<=2;i++){
            cargarArchivos(files[i-1],i);
        }
    }
    void agregarPoblacion(int cantidad){
        for (int i=0; i<cantidad; i++){
            poblacionMundial->agregarHumano(new Humano());
        }
    }
    bool verificarID(int nuevo){
        if(poblacionMundial->largo != 0){
            NodoHumano * tmp = poblacionMundial->primerNodo;
            while(tmp != NULL){
                if(tmp->persona->ID == nuevo)
                    return false;
            }
            return true;
        }
        return true;
    }
    void agregarLinea(QString line,int arreglo){
        switch (arreglo){
            case 1:
                nombres->append(line);
            case 2:
                apellidos->append(line);
            case 3:
                creencias->append(line);
            case 4:
                profresiones->append(line);
            case 5:
                paises->append(line);
        }
    }
    void cargarArchivos(QString path,int arreglo){
        int cont = 1;
        QFile inputFile(path+".txt");
        if (inputFile.open(QIODevice::ReadOnly)){
              QTextStream in(&inputFile);
              while (!in.atEnd()){
                 QString line = in.readLine(cont);
                 agregarLinea(line,arreglo);
                 cont++;
              }
              inputFile.close();
        }
    }
};

#endif // MUNDO_H
