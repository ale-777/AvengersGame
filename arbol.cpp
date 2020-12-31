#include "Globals.h"
NodoArbol* Arbol::agregarNodo(NodoArbol * nodo, NodoHumano * nuevo){
     if (nodo == NULL){
         return new NodoArbol(nuevo);
     }
     else if(nodo->humano->persona->index > nuevo->persona->index)
         nodo->izquierdo = agregarNodo(nodo->izquierdo, nuevo);
     else
         nodo->derecho = agregarNodo(nodo->derecho, nuevo);
     return nodo;
}
