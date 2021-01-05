#ifndef MUNDO_H
#define MUNDO_H
#include <QFile>
#include <QTextStream>
#include <string>
#include <QMessageBox>
#include <QString>
using namespace std ;

struct Humano;
struct NodoHumano;
struct Mundo;
struct Arbol;
struct NodoArbol;
struct Mundo{
    //ListaHumano * poblacionMundial;
    QString nombresHombre[1000];
    QString nombresMujer[1000];
    QString apellidos[100];
    QString creencias[10];
    QString paises[100];
    QString profresiones[50];
    QString deportes[38];
    QString files[7]={"nombresHombres","nombresMujeres","apellidos","creencias","profesiones","paises","deportes"};
    int cantidadArbol = 0;
    Mundo(){}
    void iniciarMundo();
    void agregarPoblacion(int cantidad);
    bool verificarID(int nuevo);
    void agregarLinea(QString line,int arreglo, int contLineas);
    void cargarArchivos(QString path,int arreglo);
    QString imprimirPoblacion ();
    void sumarPecados();
    void sumarBuenasAcciones();
    void crearLazos();
    int redondearArbol(float);
    int cantNiveles(float cant);
    Humano* consultaID(int id);
    QString horaFecha ();
};

#endif // MUNDO_H
