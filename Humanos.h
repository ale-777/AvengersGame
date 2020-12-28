#ifndef HUMANOS_H
#define HUMANOS_H
#include <string>
#include <QtCore>
#include <bits/uniform_int_dist.h>
using namespace std ;

struct NodoHumano;
struct ListaAmigos;
struct Humano;

struct NodoHumano{
  Humano * persona;
  NodoHumano * siguiente;
  NodoHumano * anterior;
  NodoHumano(Humano * _persona){
      persona = _persona;
      siguiente= anterior = NULL;
  }

};
struct ListaHumano{
    NodoHumano * primerNodo;

    int largo;
    ListaHumano(){
        primerNodo = NULL;
        largo = 0;
    }


    void agregarHumano(Humano * nuevo){
        if (primerNodo == NULL){
            primerNodo = new NodoHumano(nuevo);
            primerNodo->siguiente= primerNodo;
            primerNodo->anterior = primerNodo;

        }
        else{
            NodoHumano * nuevoHumano = new NodoHumano(nuevo);
            nuevoHumano->siguiente = primerNodo;
            nuevoHumano->anterior = primerNodo->anterior;
            primerNodo->anterior->siguiente = nuevoHumano;
            primerNodo->anterior = nuevoHumano;
            primerNodo = nuevoHumano;
        }
        largo ++;
    }
};
struct NodoPais{
  QString pais;
  NodoPais * siguiente;
  NodoPais * anterior;
  NodoPais(QString _pais){
      pais = _pais;
      siguiente= anterior = NULL;
  }

};
struct ListaPaises{
    NodoPais * primerNodo;
    NodoPais * ultimoNodo;
    ListaPaises(){
        primerNodo = ultimoNodo = NULL;
    }
    void agregarPais(QString nuevo){
        if (primerNodo == NULL){
            primerNodo = ultimoNodo = new NodoPais(nuevo);
        }
        else{
            ultimoNodo->siguiente = new NodoPais(nuevo);
            ultimoNodo = ultimoNodo->siguiente;
        }
    }

    //VERIFICAR
    bool VerificarPais(QString check){
        NodoPais * tmp = primerNodo;
        while(tmp != NULL){
            if (tmp->pais == check)
                return false;
        }
        return true;
    }
};
struct Humano{
    int index;
    int ID;
    QString nombre;
    QString apellido;
    QString genero;
    QString creencia;
    QString profesion;
    bool vivo;
    //Fecha de nacimiento
    int dia;
    int mes;
    int anno;
    QString grupoEtario;
    // Etica
    int pecados[7] = {0,0,0,0,0,0,0}; // Lujuria,Gula,Avaricia,Pereza,Ira,Envidia,Soberbia
    int buenasAcciones[7] = {0,0,0,0,0,0,0};;//Castidad, Ayuno,Donación,Calma,Solidaridad,Humildad

    //Personas
    ListaHumano amigos;
    int estadoMarital;
    Humano * Pareja;
    ListaHumano hijos;

    //Paises
    QString paisOrigen;
    QString continente;
    ListaPaises paisesVisitados;


    //CONSTRUCTOR
    Humano(){

    }
    Humano(int _index){
        index = _index;
        ID = generarID();
        nombre = generarNombre();
        apellido = generarApellido();
        genero = generarGenero();
        creencia = generarCreencia();
        profesion = generarProfresion();
        generarFecha();
        calcularGrupo();
        vivo = true;
        paisOrigen = generarPais();

    }
    void generarFecha();
    QString generarGenero();
    QString generarProfresion();
    QString generarCreencia();
    QString generarNombre();
    QString generarApellido();
    void calcularGrupo();
    int generarID();
    QString generarPais();
    int generarCantidadE();
    void generarExperiencias();
    void imprimirHumano();
    void asignarPecados();
    void asignarBuenasAcciones();

};
#endif // HUMANOS_H
