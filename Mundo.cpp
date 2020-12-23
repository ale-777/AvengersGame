#include "Globals.h"

void Mundo::agregarPoblacion(int cantidad){
    for (int i=0; i<cantidad; i++){
        qDebug()<<i;
        poblacionMundial.agregarHumano(new Humano());
    }

}
bool Mundo::verificarID(int nuevo){
    if(poblacionMundial.largo != 0){
        NodoHumano * tmp = poblacionMundial.primerNodo;
        while(tmp != NULL){
            if(tmp->persona->ID == nuevo)
                return false;
            tmp = tmp->siguiente;
        }
        return true;
    }
    return true;
}
void Mundo::agregarLinea(QString line,int arreglo, int contLineas){

    qDebug ()<<line;

    switch (arreglo){
        case 1:
            nombres[contLineas] = line;
            break;
        case 2:
            apellidos[contLineas] = line;
            break;
        case 3:
            creencias[contLineas] = line;
            break;
        case 4:
            profresiones[contLineas] = line;
            break;
        case 5:
            paises[contLineas] = line;
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
              qDebug()<<contLineas;
             QString line = in.readLine();

             agregarLinea(line,arreglo,contLineas);
             cont++;
             contLineas++;
          }
          inputFile.close();
    }
}



void Mundo::iniciarMundo(){

    for(int i=1; i<=5;i++){
         cargarArchivos(files[i-1],i);
    }
}

void Mundo::imprimirPoblacion(){
    NodoHumano * tmp = poblacionMundial.primerNodo;

    while(tmp != NULL){
        tmp->persona->imprimirHumano();
        tmp = tmp->siguiente;
    }
}
