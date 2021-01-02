#include "Globals.h"
void Humano::generarFecha(){
    std::uniform_int_distribution<int> dist(1920, 2020);
    anno = dist(* QRandomGenerator::global());
    std::uniform_int_distribution<int> dist2(1, 12);
    mes = dist2(* QRandomGenerator::global());
    int max = 31;
    if (mes == 2){
        if((anno%4==0 && anno%100!=0) || anno%400==0){
            max = 29;
        }
        else{
            max = 28;
        }
    }
    std::uniform_int_distribution<int> dist3(1, max);
    dia = dist3(* QRandomGenerator::global());
}
QString Humano::generarGenero(){
    std::uniform_int_distribution<int> dist(0, 1);
    int rand = dist(* QRandomGenerator::global());
    if (rand == 1){
        return "Hombre";
    }
    return "Mujer";
}
QString Humano::generarProfresion(){
    std::uniform_int_distribution<int> dist(1, 50);
    int rand = dist(* QRandomGenerator::global());
    return planeta.profresiones[rand];
}
QString Humano::generarCreencia(){
    std::uniform_int_distribution<int> dist(1, 10);
    int rand = dist(* QRandomGenerator::global());
    return planeta.creencias[rand];
}
QString Humano::generarNombre(){
    std::uniform_int_distribution<int> dist(1, 1000);
    int rand = dist(* QRandomGenerator::global());
    if (genero == "Hombre")
        return planeta.nombresHombre[rand];
    else
        return planeta.nombresMujer[rand];
}
QString Humano::generarApellido(){
    std::uniform_int_distribution<int> dist(1, 100);
    int rand = dist(* QRandomGenerator::global());
    return planeta.apellidos[rand];
}
int Humano::generarID(){
    bool repetir = true;
    std::uniform_int_distribution<int> dist(0, 9999999);
    int rand;
    while(repetir){

        rand = dist(* QRandomGenerator::global());
        if(planeta.verificarID(rand))
            return rand;
    }
    return 0;
}
void Humano::calcularGrupo(){
    int edad = 2021-anno;
    if (edad<=1){
        grupoEtario = "Infantil";
    }
    else if(edad<=4){
        grupoEtario = "Pre-escolar";
    }
    else if(edad<=10){
        grupoEtario = "Escolar";
    }
    else if(edad<=14){
        grupoEtario = "Pubertad";
    }
    else if(edad<=19){
        grupoEtario = "Adolescencia";
    }
    else if(edad<=24){
        grupoEtario = "Joven";
    }
    else if(edad<=34){
        grupoEtario = "Adulto Joven";
    }
    else if(edad<=64){
        grupoEtario = "Adulto Maduro";
    }
    else{
        grupoEtario = "Adulto Mayor";
    }
}
QString Humano::generarPais(){
    std::uniform_int_distribution<int> dist(1, 100);
    int rand = dist(* QRandomGenerator::global());
    return planeta.paises[rand];
}

int Humano::generarCantidadE(){
    std::uniform_int_distribution<int> dist(0, 100);
    int rango;
    int rand = dist(* QRandomGenerator::global());
    if (rand<=30){
        std::uniform_int_distribution<int> dist2(0, 2);
        rango = dist(* QRandomGenerator::global());
    }
    else if(rand<=55){
        std::uniform_int_distribution<int> dist2(2, 10);
        rango = dist(* QRandomGenerator::global());
    }
    else if(rand<=75){
        std::uniform_int_distribution<int> dist2(10, 15);
        rango = dist(* QRandomGenerator::global());
    }
    else if(rand<=90){
        std::uniform_int_distribution<int> dist2(16, 25);
        rango = dist(* QRandomGenerator::global());
    }
    else{
        std::uniform_int_distribution<int> dist2(25, 100);
        rango = dist(* QRandomGenerator::global());
    }
    return rango;
}
void Humano::generarExperiencias(){
    int max = generarCantidadE();
    bool repetir;
    for(int i=0; i<max; i++){
        repetir = true;
        while(repetir){
            QString pais = generarPais();
            if(paisesVisitados.VerificarPais(pais)){
                 paisesVisitados.agregarPais(pais);
                 repetir = false;
            }
        }
    }
}

QString Humano::imprimirHumano(){
    QString humano = "\nindex" + QString::number(index) + "\n" + "ID: "+QString::number(ID) +" Nombre: " + nombre +" "+ apellido +
            " Genero: " + genero + "pais: " + paisOrigen  + "Grupo Etario: " + grupoEtario + "Anno: "+ QString::number(anno)+"\n";
    QString amigos = "Amigos: \n" + imprimirAmigos();
    QString deporte = "Deportes: \n" + deportes.imprimirDeporte();
    QString pecado = "Pecados: \n Lujuria: " + QString::number(pecados[0])  + " Gula: " + QString::number(pecados[1])  + " Avaricia: "+ QString::number(pecados[2])+" Pereza: " + QString::number(pecados[3])+" Ira: "+QString::number(pecados[4])+" Envidia: "+QString::number(pecados[5])+" Soberbia: "+QString::number(pecados[6])+"\n";
    QString acciones = "Buenas Acciones: \n Castidad: " + QString::number(buenasAcciones[0]) + " Ayuno: "+ QString::number(buenasAcciones[1])+" Donacion: "+ QString::number(buenasAcciones[2])+" Diligencia: "+QString::number(buenasAcciones[3])+" Calma: "+QString::number(buenasAcciones[4])+" Solidaridad: "+QString::number(buenasAcciones[5])+" Humildad: "+QString::number(buenasAcciones[6])+"\n";
    /*qDebug() <<"ID"<<ID<<" Nombre: "<<nombre <<apellido << "Genero: "<<genero<<"pais: "<<paisOrigen  << "Grupo Etario: "<<grupoEtario<< "Anno: "<<anno<<Qt::endl;
    qDebug() <<"Pecados: "<<"Lujuria: "<<pecados[0]<<"Gula: "<<pecados[1]<<"Avaricia: "<<pecados[2]<<"Pereza: "<<pecados[3]<<"Ira: "<<pecados[4]<<"Envidia: "<<pecados[5]<<"Soberbia: "<<pecados[6]<<Qt::endl;
    qDebug() <<"Buenas Acciones: "<<"Castidad: "<<buenasAcciones[0]<<"Ayuno: "<<buenasAcciones[1]<<"Donacion: "<<buenasAcciones[2]<<"Diligencia: "<<buenasAcciones[3]<<"Calma: "<<buenasAcciones[4]<<"Solidaridad: "<<buenasAcciones[5]<<"Humildad: "<<buenasAcciones[6]<<Qt::endl;
*/
    return humano + amigos + deporte + pecado + acciones;
}

void Humano::imprimirPruebas(){
    qDebug() <<"Index "<<index<<"  ID "<<ID<<Qt::endl;
}

void Humano::asignarPecados(){
    std::uniform_int_distribution<int> dist(0, 100);
    int lujuria = dist(* QRandomGenerator::global());
    pecados[0] = pecados[0]+lujuria;

    int gula = dist(* QRandomGenerator::global());
    pecados[1] = pecados[1]+gula;

    int avaricia = dist(* QRandomGenerator::global());
    pecados[2] = pecados[2]+avaricia;

    int pereza = dist(* QRandomGenerator::global());
    pecados[3] = pecados[3]+pereza;

    int ira = dist(* QRandomGenerator::global());
    pecados[4] = pecados[4]+ira;

    int envidia = dist(* QRandomGenerator::global());
    pecados[5] = pecados[5]+envidia;

    int soberbia = dist(* QRandomGenerator::global());
    pecados[6] = pecados[6]+soberbia;

}

void Humano::asignarBuenasAcciones(){
    std::uniform_int_distribution<int> dist(0, 100);
    int castidad = dist(* QRandomGenerator::global());
    buenasAcciones[0] = buenasAcciones[0]+castidad;

    int ayuno = dist(* QRandomGenerator::global());
    buenasAcciones[1] = buenasAcciones[1]+ayuno;

    int donacion = dist(* QRandomGenerator::global());
    buenasAcciones[2] = buenasAcciones[2]+donacion;

    int diligencia = dist(* QRandomGenerator::global());
    buenasAcciones[3] = buenasAcciones[3]+diligencia;

    int calma = dist(* QRandomGenerator::global());
    buenasAcciones[4] = buenasAcciones[4]+calma;

    int solidaridad = dist(* QRandomGenerator::global());
    buenasAcciones[5] = buenasAcciones[5]+solidaridad;

    int Humildad = dist(* QRandomGenerator::global());
    buenasAcciones[6] = buenasAcciones[6]+Humildad;

}

bool Humano::alreadyAmigo(NodoHumano * evaluar){
    if (amigos.primerNodo != NULL){
        NodoHumano * tmp = amigos.primerNodo;
        do{
            if (tmp->persona == evaluar->persona){
                return true;
            }
            tmp = tmp->siguiente;
        }while(tmp!=amigos.primerNodo);
    }
    return false;
}

bool Humano::encontrarAmigosComun(NodoHumano * nodoHumano,NodoHumano * tmpHumano){
    if (nodoHumano->persona->amigos.primerNodo != NULL && tmpHumano->persona->amigos.primerNodo != NULL ){
        NodoHumano * tmpBuscando = nodoHumano->persona->amigos.primerNodo;
        NodoHumano * tmpBuscar = tmpHumano->persona->amigos.primerNodo;
    do{
       do {
           if(tmpBuscando == tmpBuscar)
              return true;
            tmpBuscar = tmpBuscar->siguiente;
            }
       while(tmpBuscar != tmpHumano->persona->amigos.primerNodo);
       tmpBuscando = tmpBuscando->siguiente;
       tmpBuscar = tmpHumano->persona->amigos.primerNodo;
    }
    while(tmpBuscando != nodoHumano->persona->amigos.primerNodo);

    }
    return false;
}
void Humano::crearAmigos(NodoHumano * nodoHumano){
    int cantAmigos,prob1;

    std::uniform_int_distribution<int> dist(0, 50);
    cantAmigos = dist(* QRandomGenerator::global());

    std::uniform_int_distribution<int> dist2(0, 100);

    NodoHumano * tmp = nodoHumano->siguiente;
    for(int i=0; i<cantAmigos; i++){
        prob1 = dist2(* QRandomGenerator::global());

      if (!alreadyAmigo(nodoHumano)){
          if(tmp->persona->paisOrigen == nodoHumano->persona->paisOrigen)
              nodoHumano->persona->amigos.agregarHumano(tmp->persona);
          else if (prob1 < 40)
              nodoHumano->persona->amigos.agregarHumano(tmp->persona);
          else{
              if (encontrarAmigosComun(nodoHumano, tmp) && prob1 < 70)
                 nodoHumano->persona->amigos.agregarHumano(tmp->persona);
          }
         }

       tmp = tmp->siguiente;
       if (tmp->persona == this){
           i = cantAmigos;}
    }
}


QString Humano::imprimirAmigos(){
    QString info = "";

    if (amigos.primerNodo != NULL){
        NodoHumano * tmp = amigos.primerNodo;
        do{
            info += QString::number(tmp->persona->ID)+ " "+tmp->persona->nombre+ " "+" "+ tmp->persona->apellido+"\n";
            tmp = tmp->siguiente;
        }while(tmp!=amigos.primerNodo);
    }
    return info;
}
bool Humano::alreadyIn(NodoHumano * padre,NodoHumano * hijo){
    if(padre->persona->Madre != NULL && padre->persona->Padre != NULL){
        return(padre->persona->Madre != hijo->persona && padre->persona->Madre->Madre != hijo->persona &&
               padre->persona->Madre->Padre != hijo->persona && padre->persona->Padre != hijo->persona &&
               padre->persona->Padre->Madre != hijo->persona && padre->persona->Padre->Padre != hijo->persona);
        }
    else if(padre->persona->Padre != NULL){
        return (padre->persona->Padre != hijo->persona && padre->persona->Padre->Madre != hijo->persona &&
        padre->persona->Padre->Padre != hijo->persona);
    }
    else if(padre->persona->Madre != NULL){
        return (padre->persona->Madre != hijo->persona && padre->persona->Madre->Madre != hijo->persona &&
        padre->persona->Madre->Padre != hijo->persona);
    }
    return true;
}
bool Humano::encontrarParentesco(NodoHumano * padre,NodoHumano * hijo){
   QString generoPadre = hijo->persona->genero;
   QString generoHijo = hijo->persona->genero;
   if (generoPadre == "Mujer" && hijo->persona->Madre == NULL){
           if(alreadyIn(padre,hijo)){
                hijo->persona->Madre = padre->persona;
                return true;
           }
   }
   else if(generoPadre == "Hombre" && hijo->persona->Padre == NULL){
            if(alreadyIn(padre,hijo)){
                hijo->persona->Padre = padre->persona;
                return true;
            }
   }
   return false;
}
void Humano::crearHijosAux(NodoHumano * nodoHumano, NodoHumano * hijo){
    QString grupoEtarioPadre = nodoHumano->persona->grupoEtario;
    QString grupoEtarioHijo = hijo->persona->grupoEtario;
    if (grupoEtarioPadre == "Joven"){
        if(grupoEtarioHijo == "Infantil" || grupoEtarioHijo == "Pre-escolar")
            if(!encontrarParentesco(nodoHumano,hijo))
                nodoHumano->persona->hijos.agregarHumano(hijo->persona);
    }
    else if (grupoEtarioPadre == "Adulto Joven"){
        if(grupoEtarioHijo == "Infantil" || grupoEtarioHijo == "Pre-escolar" ||
           grupoEtarioHijo == "Escolar" || grupoEtarioHijo == "Pubertad")
            if(!encontrarParentesco(nodoHumano,hijo))
                nodoHumano->persona->hijos.agregarHumano(hijo->persona);
    }
    else if (grupoEtarioPadre == "Adulto Maduro"){
        if(grupoEtarioHijo == "Adolescencia" || grupoEtarioHijo == "Joven" ||
           grupoEtarioHijo == "Adulto Joven")
            if(!encontrarParentesco(nodoHumano,hijo))
                nodoHumano->persona->hijos.agregarHumano(hijo->persona);
    }
    else
        if(grupoEtarioHijo == "Adulto Joven" || grupoEtarioHijo == "Adulto Maduro")
            if(!encontrarParentesco(nodoHumano,hijo))
                nodoHumano->persona->hijos.agregarHumano(hijo->persona);
}
bool Humano::posiblePadre(NodoHumano * nodoHumano, NodoHumano * hijo){
    if (nodoHumano->persona->genero == "Hombre"){
        if (nodoHumano->persona->apellido == hijo->persona->apellido)
            return true;
        else if (hijo->persona->Madre != NULL)
            return true;
    }
    else{
        if (hijo->persona->Padre != NULL)
            return true;
        else if (nodoHumano->persona->apellido == hijo->persona->apellido)
            return true;
    }
    return false;
}
void Humano::crearHijos(NodoHumano * nodoHumano){
    if (nodoHumano->persona->edad >= 24)
        if (nodoHumano->persona->amigos.largo < nodoHumano->persona->cantHijos){
            NodoHumano * tmp = nodoHumano->siguiente;
            do{
                if(nodoHumano->persona->paisOrigen == tmp->persona->paisOrigen){
                    if (posiblePadre(nodoHumano, tmp))
                        crearHijosAux(nodoHumano, tmp);
                }
                tmp = tmp->siguiente;
              }while(tmp != nodoHumano && nodoHumano->persona->hijos.largo < cantHijos);
        }
}
void Humano::generarCantHijos(){
    if (edad >= 24){
        std::uniform_int_distribution<int> dist(0, 4);
        cantHijos= dist(* QRandomGenerator::global());
    }
    else cantHijos = 0;
}
void Humano::generarDeportes(){
    int cant;
    int  pos;
    std::uniform_int_distribution<int> dist(0, 6);
    cant = dist(* QRandomGenerator::global());
    std::uniform_int_distribution<int> dist2(0, 38);
    while(deportes.largo < cant){
        pos = dist2(* QRandomGenerator::global());
        if(deportes.VerificarDeporte(planeta.deportes[pos])){
                deportes.agregarDeportes(planeta.deportes[pos]);}
    }

}

void ListaHumano::mostrarLista(){
    if (primerNodo != NULL){
            NodoHumano * tmp = primerNodo;
            do{
                tmp->persona->imprimirPruebas();
                tmp = tmp->siguiente;
            }while(tmp!=primerNodo);
    }
}

