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
   int cantFero = 0;
   int FeroRama = 0;
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
   void print_tree_structure(NodoArbol *bt, int spaces);

   NodoArbol * buscar (int dato, NodoArbol * arbol);
   void returnNivel (NodoArbol * arbol, int nivel);

   void preOrden(NodoArbol* nodo);
   void limpiarHormigas(NodoArbol*);
   void recorrerArbol(NodoArbol*);
   NodoArbol * obtenerMayor(NodoArbol*,int,int);
   int contarFeromonas(NodoArbol *);

   //spiderman
   void preOrdenSpiderman (NodoArbol* nodo);
   bool esHoja(int);

};
#endif // ARBOL_H
