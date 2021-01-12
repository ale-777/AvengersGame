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
        resultado += "    ";
    }
    resultado += QString::number(root->humano->persona->ID)+"\n";

    for (int i = COUNT; i < space; i++){
        resultado += "    ";
    }
    resultado += "Index: "+QString::number(root->humano->persona->index)+"\n";

    for (int i = COUNT; i < space; i++){
        resultado += "    ";
    }
    resultado += root->humano->persona->nombre + " "+ root->humano->persona->apellido+"\n";

    for (int i = COUNT; i < space; i++){
        resultado += "    ";
    }
    resultado += "Vivo: "+QString::number(root->humano->persona->vivo)+"\n";

    for (int i = COUNT; i < space; i++){
        resultado += "    ";
    }
    resultado += "Amigos: "+QString::number(root->humano->persona->amigos.largo)+"\n";

    for (int i = COUNT; i < space; i++){
        resultado += "    ";
    }
    resultado += "Familiares: "+QString::number(root->humano->persona->cantFamiliares());

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
void Arbol::limpiarHormigas(NodoArbol * raiz){
    if (raiz != NULL){
        raiz->FeroRama = 0;
        raiz->cantFero = 0;
        limpiarHormigas(raiz->izquierdo);
        limpiarHormigas(raiz->derecho);
    }
}
void Arbol::recorrerArbol(NodoArbol * raiz){
    std::uniform_int_distribution<int> dist(0, 1);
    int dir = dist(* QRandomGenerator::global());
    if(raiz->derecho != NULL){
        raiz->cantFero++;
        if (dir == 0){
            avengers.rutaHormiga += "Izquierda a nodo: \n";//+QString::number(raiz->izquierdo->humano->persona->ID)+"\nTotal de feromonas: "+raiz->cantFero+"\n\n";
            recorrerArbol(raiz->izquierdo);
        }
        else{
            avengers.rutaHormiga += "Derecha a nodo: \n";//+QString::number(raiz->derecho->humano->persona->ID)+"\nTotal de feromonas: "+raiz->cantFero+"\n\n";
            recorrerArbol(raiz->derecho);
        }
    }
    else{
        raiz->cantFero++;
    }
}
int Arbol::contarFeromonas(NodoArbol * raiz){
    if (raiz!=NULL){
        //qDebug()<< raiz->cantFero + contarFeromonas(raiz->izquierdo) + contarFeromonas(raiz->derecho);
        return raiz->cantFero + contarFeromonas(raiz->izquierdo) + contarFeromonas(raiz->derecho);

    }
    else
        return 0;
}
NodoArbol *Arbol::obtenerMayor(NodoArbol * raiz, int cont, int primerMayor){
    qDebug()<<"contador "<<cont<<" Mayor "<<primerMayor;
    if(raiz->izquierdo != NULL && raiz->derecho != NULL){
        if(contarFeromonas(raiz->izquierdo) > contarFeromonas(raiz->derecho)){
            if (primerMayor != 0){
                if (cont+raiz->cantFero+raiz->izquierdo->cantFero < primerMayor){
                    qDebug()<<"izquierdo";
                    return obtenerMayor(raiz->izquierdo,cont+raiz->cantFero,primerMayor);
                }
                else{
                    qDebug()<<"derecho";
                   return obtenerMayor(raiz->derecho,cont+raiz->cantFero,primerMayor);
                }
            }

            return obtenerMayor(raiz->izquierdo,cont+raiz->cantFero,primerMayor);
        }
        else if(contarFeromonas(raiz->izquierdo)< contarFeromonas(raiz->derecho)){
            if (primerMayor != 0){
                if (cont+raiz->cantFero+raiz->derecho->cantFero < primerMayor){
                    qDebug()<<"izquierdo";
                    return obtenerMayor(raiz->derecho,cont+raiz->cantFero,primerMayor);
                }
                else {
                    qDebug()<<"derecho";
                    return obtenerMayor(raiz->izquierdo,cont+raiz->cantFero,primerMayor);
                    }
             }
              return obtenerMayor(raiz->derecho,cont+raiz->cantFero,primerMayor);
        }
        else{
            NodoArbol * mayorIzquierdo = obtenerMayor(raiz->izquierdo,cont+raiz->cantFero,primerMayor);
            NodoArbol * mayorDerecho = obtenerMayor(raiz->derecho,cont+raiz->cantFero,primerMayor);
            if (contarFeromonas(mayorDerecho) > contarFeromonas(mayorIzquierdo)){
                return obtenerMayor(raiz->izquierdo,cont+raiz->cantFero,primerMayor);
            }
            else{
                return obtenerMayor(raiz->derecho,cont+raiz->cantFero,primerMayor);
            }

       }
    }
    raiz->FeroRama = cont + raiz->cantFero;

    qDebug()<<raiz->FeroRama;
    return raiz;
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

//****************************SPIDERMAN***************************************************************
void Arbol::preOrdenSpiderman (NodoArbol* nodo)
{
   if (nodo != NULL)
   {
     arbolAListaParaSpiderman.agregarHumano(nodo->humano->persona); //convierte el arbol a una lista de humanos
     preOrdenSpiderman(nodo->izquierdo);
     preOrdenSpiderman(nodo->derecho);
   }

}

bool Arbol::esHoja(int index){
    if (buscar(index, raiz)!=NULL){
        if (buscar(index, raiz)->izquierdo == NULL){
            return true;
        }
        return false;
    }
    return false;
}


//*****************************************************************************************************
