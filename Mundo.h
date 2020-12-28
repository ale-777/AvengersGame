#ifndef MUNDO_H
#define MUNDO_H
#include <QFile>
#include <QTextStream>
#include <string>
#include <QMessageBox>
#include <QString>
using namespace std ;

struct Mundo;

struct Mundo{
    //ListaHumano * poblacionMundial;
    QString nombres[1000];
    QString apellidos[100];
    QString creencias[10];
    QString paises[100];
    QString profresiones[50];
    QString files[5]={"nombres","apellidos","creencias","profesiones","paises"};
    Mundo(){}
    void iniciarMundo();
    void agregarPoblacion(int cantidad);
    bool verificarID(int nuevo);
    void agregarLinea(QString line,int arreglo, int contLineas);
    void cargarArchivos(QString path,int arreglo);
    void imprimirPoblacion ();
    void sumarPecados();
    void sumarBuenasAcciones();
    void crearLazos();
};

#endif // MUNDO_H
