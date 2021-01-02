#include "Globals.h"
#include <iomanip>
#include <cmath>
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


void Arbol::crearArbol(){
    int cantNodos = planeta.redondearArbol((poblacionMundial.largo)*0.01);
    qDebug()<<"Cant nodos "<<cantNodos;
    double secuencia = ceil((poblacionMundial.largo * 1.0) / (cantNodos * 1.0));
    qDebug()<<"secuencia "<<secuencia;

    //hacer la lista con los nodos
    ListaHumano *listaNodos = poblacionMundial.nodosArbol(secuencia);
    NodoHumano *raizPrincipal = listaNodos->centroLista();
    ListaHumano *primerMitad = listaNodos->primerMitadOrden();
    ListaHumano *segundaMitad = listaNodos->segundaMitad();

    qDebug()<<"Lista nodos: ";
    listaNodos->mostrarLista();


    qDebug()<<"Raiz: ";
    raizPrincipal->persona->imprimirPruebas();

    qDebug()<<"Lista primer mitad: ";
    primerMitad->mostrarLista();

    qDebug()<<"Lista segunda mitad: ";
    segundaMitad->mostrarLista();

    llenarArbol(listaNodos);

}

void Arbol::llenarArbol(ListaHumano *lista){
    qDebug()<<"agrega: ";
    lista->centroLista()->persona->imprimirPruebas();

    agregarNodo(raiz, lista->centroLista());
    if (lista->largo > 1){
        llenarArbol(lista->primerMitadOrden());
        llenarArbol(lista->segundaMitad());
    }

}
