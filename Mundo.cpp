#include "Globals.h"
#include "Humanos.h"
void Mundo::agregarPoblacion(int cantidad){
    for (int i=0; i<cantidad; i++){
        poblacionMundial.agregarHumano(new Humano());
    }
}
bool Mundo::verificarID(int nuevo){
    if(poblacionMundial.largo != 0){
        NodoHumano * tmp = poblacionMundial.primerNodo;
        while(tmp != NULL){
            if(tmp->persona->ID == nuevo)
                return false;
        }
        return true;
    }
    return true;
}
void Mundo::agregarLinea(QString line,int arreglo){
    switch (arreglo){
        case 1:
            nombres->append(line);
        case 2:
            apellidos->append(line);
        case 3:
            creencias->append(line);
        case 4:
            profresiones->append(line);
        case 5:
            paises->append(line);
    }
}
void Mundo::cargarArchivos(QString path,int arreglo){
    int cont = 1;
    QFile inputFile(path+".txt");
    if (inputFile.open(QIODevice::ReadOnly)){
          QTextStream in(&inputFile);
          while (!in.atEnd()){
             QString line = in.readLine(cont);
             agregarLinea(line,arreglo);
             cont++;
          }
          inputFile.close();
    }
}
void Mundo::iniciarMundo(){
        for(int i=1; i<=5;i++){
            cargarArchivos(files[i-1],i);
        }
    }
