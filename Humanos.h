#ifndef HUMANOS_H
#define HUMANOS_H
#include <Mundo.h>
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
  string pais;
  NodoPais * siguiente;
  NodoPais * anterior;
  NodoPais(string _pais){
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
    void agregarPais(string nuevo){
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
    Mundo * planeta;
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
    Humano(Mundo* _planeta){
        planeta = _planeta;
        ID = generarID();
        nombre = generarNombre();
        apellido = generarApellido();
        genero = generarGenero();
        creencia = generarCreencia();
        profesion = generarProfresion();
        vivo = true;

    }
    void generarFecha(){
        std::uniform_int_distribution<int> dist(1920, 2020);
        anno = dist(* QRandomGenerator::global());
        std::uniform_int_distribution<int> dist2(1, 12);
        mes = dist2(* QRandomGenerator::global());
        int max = 28;
        if (mes == 2){
            if((anno%4==0 && anno%100!=0) || anno%400==0){
                max = 29;
            }
        }
        std::uniform_int_distribution<int> dist3(1, max);
        anno = dist3(* QRandomGenerator::global());
    }
    QString generarGenero(){
        std::uniform_int_distribution<int> dist(0, 1);
        int rand = dist(* QRandomGenerator::global());
        if (rand == 1){
            return "Hombre";
        }
        return "Mujer";
    }
    QString generarProfresion(){
        std::uniform_int_distribution<int> dist(1, 50);
        int rand = dist(* QRandomGenerator::global());
        return planeta->profresiones[rand];
    }
    QString generarCreencia(){
        std::uniform_int_distribution<int> dist(1, 10);
        int rand = dist(* QRandomGenerator::global());
        return planeta->creencias[rand];
    }
    QString generarNombre(){
        std::uniform_int_distribution<int> dist(1, 1000);
        int rand = dist(* QRandomGenerator::global());
        return planeta->nombres[rand];
    }
    QString generarApellido(){
        std::uniform_int_distribution<int> dist(1, 100);
        int rand = dist(* QRandomGenerator::global());
        return planeta->apellidos[rand];
    }
    int generarID(){
        bool repetir = true;
        std::uniform_int_distribution<int> dist(0, 9999999);
        int rand;
        while(repetir){
            rand = dist(* QRandomGenerator::global());
            if(planeta->verificarID(rand))
                return rand;
        }
    }

};
#endif // HUMANOS_H
