#include "Globals.h"
#include <iomanip>
#include <cmath>
//:)
NodoArbol* Arbol::agregarNodo(NodoArbol * nodo, NodoHumano * nuevo){
    //qDebug()<<nuevo->persona->ID;
     if (nodo == NULL){
         //nodo = new NodoArbol(nuevo);
         return new NodoArbol(nuevo);
     }
     else if(nodo->humano->persona->index > nuevo->persona->index){
         nodo->izquierdo = agregarNodo(nodo->izquierdo, nuevo);
     }

     else
         nodo->derecho = agregarNodo(nodo->derecho, nuevo);
     return nodo;
}

void Arbol::insertar(NodoHumano * dato){
    raiz = agregarNodo (raiz , dato);
}

void Arbol::preOrden(NodoArbol* nodo)
{
   if (nodo != NULL)
   {
     arbolPreOrden.agregarHumano(nodo->humano->persona); //convierte el arbol a una lista de humanos
     preOrden(nodo->izquierdo);
     preOrden(nodo->derecho);
   }
}


void Arbol::crearArbol(){
    arbolMundial = Arbol();
    int cantNodos = planeta.redondearArbol((poblacionMundial.largo)*0.01);
    qDebug()<<"Cant nodos "<<cantNodos;
    double secuencia = ceil((poblacionMundial.largo * 1.0) / (cantNodos * 1.0));
    qDebug()<<"secuencia "<<secuencia;

    //hacer la lista con los nodos
    ListaHumano *listaNodos = poblacionMundial.nodosArbol(secuencia);

    llenarArbol(listaNodos);

}

void Arbol::llenarArbol(ListaHumano *lista){

    insertar(lista->centroLista());
    if (lista->largo > 1){
        llenarArbol(lista->primerMitadOrden());
        llenarArbol(lista->segundaMitad());
    }

}

QString Arbol::print2DUtil(QString resultado, NodoArbol *root, int space)  {

    if (root == NULL){
        return resultado;}

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    resultado = print2DUtil(resultado, root->derecho, space);

    // Print current node after space
    // count

    resultado += "\n";
    for (int i = COUNT; i < space; i++){
        resultado += "   ";
    }
    resultado += QString::number(root->humano->persona->ID)+"\n";

    for (int i = COUNT; i < space; i++){
        resultado += "   ";
    }
    resultado += "Index: "+QString::number(root->humano->persona->index);

    // Process left child
    resultado = print2DUtil(resultado, root->izquierdo, space);

    return resultado;
}

// Wrapper over print2DUtil()
QString Arbol::print2D(NodoArbol *root)  {
    // Pass initial space count as 0
    QString result = " ";
    return print2DUtil(result, root, 0);
}

void Arbol::print_tree_structure(NodoArbol *bt, int spaces)
{
  if(bt != NULL)
  {
    print_tree_structure(bt->derecho, spaces + 5);
    for(int i = 0; i < spaces; i++)
        cout << ' ';
    cout << "   " << bt->humano->persona->ID << endl;
    print_tree_structure(bt->izquierdo, spaces + 5);
  }
}

NodoArbol * Arbol::buscar (int dato, NodoArbol * arbol){
        if (arbol == NULL)
            return NULL;

        else if (arbol->humano->persona->index == dato)
            return arbol;

        else if (dato > arbol->humano->persona->index)
            return buscar(dato,arbol->derecho);

        return buscar(dato, arbol->izquierdo);
    }

void Arbol::returnNivel(NodoArbol *arbol, int nivel){
    if (arbol != NULL){
        if (nivel == 0){
            nivelXArbol.agregarHumano(arbol->humano->persona);
        }
        returnNivel(arbol->derecho, nivel-1);
        returnNivel(arbol->izquierdo, nivel-1);
    }

}
