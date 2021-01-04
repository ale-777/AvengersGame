#include "aniquilacion.h"
#include "Globals.h"

void Corvus (){
    ListaHumano *heapPecados = new ListaHumano();

    if (poblacionMundial.primerNodo != NULL){
        NodoHumano * tmp = poblacionMundial.primerNodo;
        do{
            if (tmp->persona->vivo)
                heapPecados->agregarPorPecados(tmp->persona);
            //qDebug() <<tmp->persona->vivo;
            tmp = tmp->siguiente;
        }while(tmp!=poblacionMundial.primerNodo);
    }
    qDebug()<<"antes:";
    heapPecados->mostrarLista();
    qDebug()<<heapPecados->largo;

    heapPecados->matarCincoHp("Corvus");

    qDebug()<<"despues:";
    qDebug()<<heapPecados->largo;
}
