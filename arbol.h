#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <fstream>
using namespace std;
struct NodoHumano;

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
};
#endif // ARBOL_H
