#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <fstream>
#include <string>
#include <QtCore>
#define COUNT 10

using namespace std;
struct NodoHumano;
struct ListaHumano;
struct NodoArbol{
   NodoHumano * humano;
   NodoArbol * izquierdo;
   NodoArbol * derecho;
   NodoArbol(NodoHumano * nuevo){
       izquierdo = derecho = NULL;
       humano = nuevo;
   }
};
struct Arbol{
   NodoArbol * raiz;
   Arbol(){
       raiz = NULL;
   }

   NodoArbol* agregarNodo(NodoArbol * nodo,NodoHumano * nuevo);
   void insertar (NodoHumano * dato);
   void crearArbol();
   void llenarArbol(ListaHumano *);
   QString obternerNivel(int nivel);
   QString print2DUtil(QString resultado, NodoArbol *root, int space);
   QString print2D(NodoArbol *root);

};
#endif // ARBOL_H
