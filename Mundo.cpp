#include "Globals.h"
int Mundo::redondearArbol(float cant){
   int res = 0;
   int pot = 1;
   while (res < cant){
       res = (pow(2,pot))-1;
       pot++;
   }
   return res;
}
void Mundo::agregarPoblacion(int cantidad){
    for (int i=0; i<cantidad; i++){
        poblacionMundial.agregarHumano(new Humano(poblacionMundial.largo));
    }
    cantidadArbol = redondearArbol(poblacionMundial.largo*0.01);
    crearLazos();

}
bool Mundo::verificarID(int nuevo){
    if(poblacionMundial.largo != 0){
        if (poblacionMundial.primerNodo != NULL){
            NodoHumano * tmp = poblacionMundial.primerNodo;
            do{
                if(tmp->persona->ID == nuevo)
                    return false;
                tmp = tmp->siguiente;

            }while(tmp!=poblacionMundial.primerNodo);
        }
        return true;
    }
    return true;}


void Mundo::agregarLinea(QString line,int arreglo, int contLineas){
    switch (arreglo){
        case 1:
            nombresHombre[contLineas] = line;
            break;
        case 2:
            nombresMujer[contLineas] = line;
            break;
        case 3:
            apellidos[contLineas] = line;
            break;
        case 4:
            creencias[contLineas] = line;
            break;
        case 5:
            profresiones[contLineas] = line;
            break;
        case 6:
            paises[contLineas] = line;
            break;
        case 7:
            qDebug()<<line<<Qt::endl;
            deportes[contLineas] = line;
            break;
    }
}

void Mundo::cargarArchivos(QString path,int arreglo){
    int cont = 1;
    int contLineas = 0;
    QFile inputFile(path+".txt");
    if (inputFile.open(QIODevice::ReadOnly)){

          QTextStream in(&inputFile);
          while (!in.atEnd()){
             QString line = in.readLine();

             agregarLinea(line,arreglo,contLineas);
             cont++;
             contLineas++;
          }
          inputFile.close();
    }
}



void Mundo::iniciarMundo(){

    for(int i=1; i<=7;i++){
         cargarArchivos(files[i-1],i);
    }

}

QString Mundo::imprimirPoblacion(){
    QString info = "";
    if (poblacionMundial.primerNodo != NULL){
        NodoHumano * tmp = poblacionMundial.primerNodo;
        do{
            info += tmp->persona->imprimirHumano();
            tmp = tmp->siguiente;
        }while(tmp!=poblacionMundial.primerNodo);
    }
    return info;
}

void Mundo::sumarPecados(){
    if (poblacionMundial.primerNodo != NULL){
        NodoHumano * tmp = poblacionMundial.primerNodo;
        do{
            tmp->persona->asignarPecados();
            tmp = tmp->siguiente;
        }while(tmp!=poblacionMundial.primerNodo);
    }
}

void Mundo::sumarBuenasAcciones(){
    if (poblacionMundial.primerNodo != NULL){
        NodoHumano * tmp = poblacionMundial.primerNodo;
        do{
            tmp->persona->asignarBuenasAcciones();
            tmp = tmp->siguiente;
        }while(tmp!=poblacionMundial.primerNodo);
    }

}

void Mundo::crearLazos(){
    if (poblacionMundial.primerNodo != NULL){
        NodoHumano * tmp = poblacionMundial.primerNodo;
        do{
            if (tmp->persona->amigos.largo == 0)
                tmp->persona->crearAmigos(tmp);
            tmp = tmp->siguiente;
        }while(tmp!=poblacionMundial.primerNodo);
    }
}
Humano* Mundo::consultaID(int id){
    if (poblacionMundial.primerNodo != NULL){
        NodoHumano * tmp = poblacionMundial.primerNodo;
        do{
            if (tmp->persona->ID == id){
                return tmp->persona;
            }
            tmp = tmp->siguiente;
        }while(tmp!=poblacionMundial.primerNodo);
    }
    return NULL;
}
