#ifndef HUMANOS_H
#define HUMANOS_H
#include <Globals.h>
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
    NodoHumano * ultimoNodo;
    int largo;
    ListaHumano(){
        primerNodo = ultimoNodo = NULL;
        largo = 0;
    }
    void agregarHumano(Humano * nuevo){
        if (primerNodo == NULL){
            primerNodo = ultimoNodo = new NodoHumano(nuevo);
        }
        else{
            ultimoNodo->siguiente = new NodoHumano(nuevo);
            ultimoNodo = ultimoNodo->siguiente;
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
};
struct Humano{
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
    int pecados[7]; // Lujuria,Gula,Avaricia,Pereza,Ira,Envidia,Soberbia
    int buenasAcciones[7];//Castidad, Ayuno,Donación,Calma,Solidaridad,Humildad

    //Personas
    ListaHumano amigos;
    int estadoMarital;
    Humano * Pareja;
    ListaHumano hijos;

    //Paises
    QString paisOrigen;
    QString continente;
    ListaPaises paisesVisitados;
    Humano(){
        ID = generarID();
        nombre = generarNombre();
        apellido = generarApellido();
        genero = generarGenero();
        creencia = generarCreencia();
        profesion = generarProfresion();
        generarFecha();
        grupoEtario = calcularGrupo();
        vivo = true;

    }
    void generarFecha();
    QString generarGenero();
    QString generarProfresion();
    QString generarCreencia();
    QString generarNombre();
    QString generarApellido();
    QString calcularGrupo();
    int generarID();

};
#endif // HUMANOS_H
