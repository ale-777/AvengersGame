#include "Globals.h"
#include <iomanip>
#include <cmath>
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
    edad = 2021-anno;
}
QString Humano::generarContinente(){
    std::uniform_int_distribution<int> dist(0, 4);
    int rand = dist(* QRandomGenerator::global());
    return planeta.continentes[rand];
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

QString Humano::imprimirPareja(){
    if (Pareja != NULL){
        return "Pareja: "+QString::number(Pareja->ID)+" "+Pareja->nombre+"\n";}
    return "Pareja: NT";
}

QString Humano::imprimirHumano(){
    QString humano = "\nindex" + QString::number(index) + "\n" + "ID: "+QString::number(ID) +"\nNombre: " + nombre +" "+ apellido +
            "\nGenero: " + genero + "\nEstado Marital: "+estadoMarital+"\nPais de Origen: " + paisOrigen +"\nContinente "+continente +"\nProfesion: "+profesion+"\nCreencia: "+creencia+ "\nGrupo Etario: " + grupoEtario + "\nAnno de Nacimiento: "+ QString::number(anno)+"\n";
    //QString pareja= "\n"+imprimirPareja();
    //**********************************FAMILIA*****************************************************************************
    QString familia = "\n"+imprimirFamiliaConsultaID();

    QString amigos = "\nAmigos: \n" + imprimirAmigos();
    QString deporte = "\nDeporte por semana: "+QString::number(cantDeporte)+"\n" + deportes.imprimirDeporte();
    QString pecado = "\nPecados: \n\tLujuria: " + QString::number(pecados[0])  + "\n\tGula: " + QString::number(pecados[1])  + "\n\tAvaricia: "+ QString::number(pecados[2])+"\n\tPereza: " + QString::number(pecados[3])+"\n\tIra: "+QString::number(pecados[4])+"\n\tEnvidia: "+QString::number(pecados[5])+"\n\tSoberbia: "+QString::number(pecados[6])+"\n";
    QString acciones = "\nBuenas Acciones: \n\tCastidad: " + QString::number(buenasAcciones[0]) + "\n\tAyuno: "+ QString::number(buenasAcciones[1])+"\n\tDonacion: "+ QString::number(buenasAcciones[2])+"\n\tDiligencia: "+QString::number(buenasAcciones[3])+"\n\tCalma: "+QString::number(buenasAcciones[4])+"\n\tSolidaridad: "+QString::number(buenasAcciones[5])+"\n\tHumildad: "+QString::number(buenasAcciones[6])+"\n";
    QString vida = "\nVivo: "+QString::number(vivo)+"\n";
    QString listaSucesos = "\n"+sucesos.mostrarLista();
    /*qDebug() <<"ID"<<ID<<" Nombre: "<<nombre <<apellido << "Genero: "<<genero<<"pais: "<<paisOrigen  << "Grupo Etario: "<<grupoEtario<< "Anno: "<<anno<<Qt::endl;
    qDebug() <<"Pecados: "<<"Lujuria: "<<pecados[0]<<"Gula: "<<pecados[1]<<"Avaricia: "<<pecados[2]<<"Pereza: "<<pecados[3]<<"Ira: "<<pecados[4]<<"Envidia: "<<pecados[5]<<"Soberbia: "<<pecados[6]<<Qt::endl;
    qDebug() <<"Buenas Acciones: "<<"Castidad: "<<buenasAcciones[0]<<"Ayuno: "<<buenasAcciones[1]<<"Donacion: "<<buenasAcciones[2]<<"Diligencia: "<<buenasAcciones[3]<<"Calma: "<<buenasAcciones[4]<<"Solidaridad: "<<buenasAcciones[5]<<"Humildad: "<<buenasAcciones[6]<<Qt::endl;
*/
    QString exp = imprimirExperienciasConsultaID()+"\n";
    return humano +vida +familia + amigos + deporte + exp + pecado + acciones + listaSucesos;
}

void Humano::imprimirPruebas(){
    qDebug() <<"Index "<<index<<"  ID "<<ID<<"Vivo: "<<vivo<<" Cant Pecados: "<<cantPecados()<<" CantBuenas: "<<cantBuenasAcciones()<<Qt::endl;
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




void Humano::generarEstadoMarital(){
    std::uniform_int_distribution<int> dist(0, 100);
    int status = dist(* QRandomGenerator::global());
    if (edad >= 20){
        if (status<10){
            estadoMarital = "Soltero";
        }
        else if (status<80){
            estadoMarital = "Casado";
        }
        else{
            estadoMarital = "Divorciado";
        }
    }
    else{
        estadoMarital = "Soltero";
    }
}


void Humano::generarPareja(NodoHumano * nodoHumano){

    if ((nodoHumano->persona->estadoMarital == "Casado" || nodoHumano->persona->estadoMarital == "Divorciado") && nodoHumano->persona->Pareja == NULL){
       QString estado = nodoHumano->persona->estadoMarital;

       NodoHumano * tmp = nodoHumano->siguiente;
       do{
           if(tmp->persona->estadoMarital == estado && tmp->persona->Pareja == NULL){
                if(alreadyIn(nodoHumano,tmp) && tmp->persona->Madre != nodoHumano->persona
                        && tmp->persona->Padre != nodoHumano->persona){
                    nodoHumano->persona->Pareja = tmp->persona;
                    tmp->persona->Pareja = nodoHumano->persona;

                    return;
                }
            }
            tmp = tmp->siguiente;
             }while(tmp != nodoHumano);
       }
}
/*
void Humano::generarPareja(NodoHumano * nodoHumano){
    QString EMActual = nodoHumano->persona->estadoMarital;
    QString EMTmp;
    if (EMActual == "Casado" || EMActual == "Divorciado"){
       NodoHumano * tmp = nodoHumano->siguiente;
       do{
           EMTmp = tmp->persona->estadoMarital;
           if(((EMActual == "Casado" && EMActual == "Casado") || (EMActual == "Divorciado" && EMActual == "Divorciado"))
                   && tmp->persona->Pareja == NULL){
                if(alreadyIn(nodoHumano,tmp) && tmp->persona->Madre != nodoHumano->persona
                        && tmp->persona->Padre != nodoHumano->persona){
                    nodoHumano->persona->Pareja = tmp->persona;
                    tmp->persona->Pareja = nodoHumano->persona;
                    return;
                }
            }
            tmp = tmp->siguiente;
             }while(tmp != nodoHumano);
       }
}*/
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

bool Humano::encontrarParentesco(NodoHumano * padre,NodoHumano * hijo){
   QString generoPadre = padre->persona->genero;
   QString generoHijo = hijo->persona->genero;
   if (generoPadre == "Mujer" && hijo->persona->Madre == NULL){
           if(alreadyIn(padre,hijo)){
                hijo->persona->Madre = padre->persona;
                return false;
           }
   }
   else if(generoPadre == "Hombre" && hijo->persona->Padre == NULL){
            if(alreadyIn(padre,hijo)){
                hijo->persona->Padre = padre->persona;
                return false;
            }
   }
   return true;
}
void Humano::crearHijosAux(NodoHumano * nodoHumano, NodoHumano * hijo){
    QString grupoEtarioPadre = nodoHumano->persona->grupoEtario;
    QString grupoEtarioHijo = hijo->persona->grupoEtario;
    if (grupoEtarioPadre == "Joven"){
        if(grupoEtarioHijo == "Infantil" || grupoEtarioHijo == "Pre-escolar")
            if(!encontrarParentesco(nodoHumano,hijo))
                nodoHumano->persona->hijos->agregarHumano(hijo->persona);
    }
    else if (grupoEtarioPadre == "Adulto Joven"){
        if(grupoEtarioHijo == "Infantil" || grupoEtarioHijo == "Pre-escolar" ||
           grupoEtarioHijo == "Escolar" || grupoEtarioHijo == "Pubertad")
            if(!encontrarParentesco(nodoHumano,hijo))
                nodoHumano->persona->hijos->agregarHumano(hijo->persona);
    }
    else if (grupoEtarioPadre == "Adulto Maduro"){
        if(grupoEtarioHijo == "Adolescencia" || grupoEtarioHijo == "Joven" ||
           grupoEtarioHijo == "Adulto Joven")
            if(!encontrarParentesco(nodoHumano,hijo))
                nodoHumano->persona->hijos->agregarHumano(hijo->persona);
    }
    else
        if(grupoEtarioHijo == "Adulto Joven" || grupoEtarioHijo == "Adulto Maduro")
            if(!encontrarParentesco(nodoHumano,hijo))
                nodoHumano->persona->hijos->agregarHumano(hijo->persona);
}
bool Humano::posiblePadre(NodoHumano * nodoHumano, NodoHumano * hijo){
    if (nodoHumano->persona->genero == "Hombre"){
        if (nodoHumano->persona->apellido == hijo->persona->apellido || hijo->persona->Madre != NULL)
            return true;
    }
    else{
        if (nodoHumano->persona->apellido == hijo->persona->apellido || hijo->persona->Padre != NULL)
            return true;
    }
    return false;
}
void Humano::crearHijos(NodoHumano * nodoHumano){
    if (nodoHumano->persona->edad >= 20){
        if (nodoHumano->persona->hijos->largo < nodoHumano->persona->cantHijos){
            NodoHumano * tmp = nodoHumano->siguiente;
            do{
                if(nodoHumano->persona->paisOrigen == tmp->persona->paisOrigen){
                    if (posiblePadre(nodoHumano, tmp))
                        crearHijosAux(nodoHumano, tmp);
               }
                else if(tmp->persona->Padre != NULL && tmp->persona->paisOrigen == tmp->persona->Padre->paisOrigen ){
                    if (posiblePadre(nodoHumano, tmp))
                        crearHijosAux(nodoHumano, tmp);
                }
                else if(tmp->persona->Madre != NULL && tmp->persona->paisOrigen == tmp->persona->Madre->paisOrigen ){
                     if (posiblePadre(nodoHumano, tmp))
                        crearHijosAux(nodoHumano, tmp);
                }
                tmp = tmp->siguiente;
              }while(tmp != nodoHumano && nodoHumano->persona->hijos->largo < nodoHumano->persona->cantHijos);
        }
    }
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
            info += QString::number(tmp->persona->ID)+ "\t"+tmp->persona->nombre+ " "+ tmp->persona->apellido+"\tVivo: "+QString::number(tmp->persona->vivo)+"\n";
            tmp = tmp->siguiente;
        }while(tmp!=amigos.primerNodo);
    }
    return info;
}

QString Humano::imprimirAmigosOtro(){
    QString info = "Amigos [";

    if (amigos.primerNodo != NULL){
        NodoHumano * tmp = amigos.primerNodo;
        do{
            info += QString::number(tmp->persona->ID)+ " "+tmp->persona->nombre+ " "+" "+ tmp->persona->apellido;
            if (tmp->siguiente != amigos.primerNodo){
                info +=",";
            }
            tmp = tmp->siguiente;
        }while(tmp!=amigos.primerNodo);
    }
    return info+"]";
}

QString Humano::imprimirFamiliaParaArchivo(){
    QString info = "Pareja: ";
    if (Pareja != NULL){
        info += QString::number(Pareja->ID)+" "+Pareja->nombre+" "+Pareja->apellido;
    }
    else{
        info += "NT";
    }
    info += "\tFamilia [";
    if (Padre != NULL){
        info += "Padre: "+QString::number(Padre->ID)+" "+Padre->nombre+" "+Padre->apellido+",";
    }
    else{
        info += "Padre: NT,";
    }
    if (Madre != NULL){
        info += " Madre: "+QString::number(Madre->ID)+" "+Madre->nombre+" "+Madre->apellido+",";
    }
    else{
        info += " Madre: NT,";
    }
    info += " Hijos: [";
    if (hijos->primerNodo != NULL){
        NodoHumano * tmp = hijos->primerNodo;
        do{
            info += QString::number(tmp->persona->ID)+ " "+tmp->persona->nombre+ " "+" "+ tmp->persona->apellido;
            if (tmp->siguiente != hijos->primerNodo){
                info +=",";
            }
            tmp = tmp->siguiente;

        }while(tmp != hijos->primerNodo);
    }
    return info +"]]";
}

QString Humano::imprimirFamiliaConsultaID(){
    QString info = "Pareja: ";
    if (Pareja != NULL){
        info += QString::number(Pareja->ID)+" "+Pareja->nombre+" "+Pareja->apellido;
    }
    else{
        info += "NT";
    }
    info += "\nFamilia \n";
    if (Padre != NULL){
        info += "Padre: "+QString::number(Padre->ID)+" "+Padre->nombre+" "+Padre->apellido+"\n";
    }
    else{
        info += "Padre: NT\n";
    }
    if (Madre != NULL){
        info += "Madre: "+QString::number(Madre->ID)+" "+Madre->nombre+" "+Madre->apellido+"\n";
    }
    else{
        info += "Madre: NT\n";
    }
    info += "Hijos: ";
    if (hijos->primerNodo != NULL){
        NodoHumano * tmp = hijos->primerNodo;
        do{
            info += QString::number(tmp->persona->ID)+ " "+tmp->persona->nombre+ " "+" "+ tmp->persona->apellido;
            if (tmp->siguiente != hijos->primerNodo){
                info +="\n";
            }
            tmp = tmp->siguiente;

        }while(tmp != hijos->primerNodo);
    }
    else{
        info += "NT";
    }
    return info +"\n";
}

void Humano::generarCantHijos(){
    if (edad >= 20){
        std::uniform_int_distribution<int> dist(0, 4);
        cantHijos= dist(* QRandomGenerator::global());
    }
    else cantHijos = 0;
}
void Humano::generarDeportes(){
    int cant = 0;
    int  pos = 0;
    int cantXSemana = 0;


    //posicion en el archivo
    std::uniform_int_distribution<int> dist2(0, 14);

    //veces por semana
    std::uniform_int_distribution<int> dist3(0, 7);
    cantXSemana = dist3(* QRandomGenerator::global());
    cantDeporte = cantXSemana;

    if (cantDeporte != 0){
        std::uniform_int_distribution<int> dist(1, cantDeporte);
        cant = dist(* QRandomGenerator::global());
        while(deportes.largo < cant){
            pos = dist2(* QRandomGenerator::global());
            if(deportes.VerificarDeporte(planeta.deportes[pos])){
                    deportes.agregarDeportes(planeta.deportes[pos]);}
        }
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

void ListaHumano::agregarPorPecados(Humano * humano){
    int cantPecados = humano->cantPecados();
    NodoHumano * nuevo = new NodoHumano(humano);
    if (primerNodo != NULL){
            largo ++;
            NodoHumano * tmp = primerNodo;
            do{
                if (tmp->persona->cantPecados() <= cantPecados){
                    if (tmp == primerNodo){
                        primerNodo = nuevo;
                    }
                    tmp->anterior->siguiente = nuevo;
                    nuevo->anterior = tmp->anterior;
                    tmp->anterior = nuevo;
                    nuevo->siguiente = tmp;

                    break;
                }
                tmp = tmp->siguiente;
                if (tmp == primerNodo){
                    tmp->anterior->siguiente = nuevo;
                    nuevo->anterior = tmp->anterior;
                    tmp->anterior = nuevo;
                    nuevo->siguiente = primerNodo;
                }
            }while(tmp!=primerNodo);


    }
    else{
        primerNodo = nuevo;
        primerNodo->siguiente= primerNodo;
        primerNodo->anterior = primerNodo;
        largo ++;
    }


}

void ListaHumano::agregarPorBuenasAcciones(Humano * humano){
    int cantAcciones = humano->cantBuenasAcciones();
    NodoHumano * nuevo = new NodoHumano(humano);

    if (primerNodo != NULL){
            largo ++;
            NodoHumano * tmp = primerNodo;
            do{
                if (tmp->persona->cantBuenasAcciones() >= cantAcciones){
                    if (tmp == primerNodo){
                        primerNodo = nuevo;
                    }
                    tmp->anterior->siguiente = nuevo;
                    nuevo->anterior = tmp->anterior;
                    tmp->anterior = nuevo;
                    nuevo->siguiente = tmp;

                    break;
                }
                tmp = tmp->siguiente;

                if (tmp == primerNodo){
                    tmp->anterior->siguiente = nuevo;
                    nuevo->anterior = tmp->anterior;
                    tmp->anterior = nuevo;
                    nuevo->siguiente = primerNodo;
                }
            }while(tmp!=primerNodo);


    }
    else{
        primerNodo = nuevo;
        primerNodo->siguiente= primerNodo;
        primerNodo->anterior = primerNodo;
        largo ++;
    }

}

int Humano::cantPecados(){
    int cant = 0;
    for (int i = 0; i<7; i++){
        cant += pecados[i];
    }
    return cant;
}

int Humano::cantBuenasAcciones(){
    int cant = 0;
    for (int i = 0; i<7; i++){
        cant += buenasAcciones[i];
    }
    return cant;
}


//PARA MIDNIGHT Y CORVUS******************************************************************************************************
QString ListaHumano::matarCincoHp(QString villano){
    int cant = largo*0.05;
    QString info = "La cantidad de humanos elminados son: "+QString::number(cant)+"\n\n";
    NodoHumano *tmp = primerNodo;
    for (int i=1; i<=cant; i++){
        tmp->persona->vivo = false;
        tmp->persona->salvado = false;
        tmp->persona->aniquilado = true;
        if (villano == "Corvus"){
            info += "Humano de ID "+QString::number(tmp->persona->ID) +" "+ tmp->persona->nombre +  " " + tmp->persona->apellido + " Por "+QString::number(tmp->persona->cantPecados())+ " pecados.\n";
            info += "Pecados: [Lujuria: " + QString::number(tmp->persona->pecados[0])  + ",Gula: " + QString::number(tmp->persona->pecados[1])  + ",Avaricia: "+ QString::number(tmp->persona->pecados[2])+",Pereza: " + QString::number(tmp->persona->pecados[3])+",Ira: "+QString::number(tmp->persona->pecados[4])+",Envidia: "+QString::number(tmp->persona->pecados[5])+",Soberbia: "+QString::number(tmp->persona->pecados[6])+"]\n\n";
            listaCorvus.agregarHumano(tmp->persona);
            tmp->persona->sucesos.agregarSucesos("Eliminado por Corvus por "+QString::number(tmp->persona->cantPecados())+ " pecados.");
            aniquiladores.bitacora += tmp->persona->formato("Eliminado por Corvus por "+QString::number(tmp->persona->cantPecados())+ " pecados.");
        }
        else if (villano == "Midnight"){
            info += "Humano de ID "+QString::number(tmp->persona->ID) +" "+ tmp->persona->nombre +  " " + tmp->persona->apellido + " Por "+QString::number(tmp->persona->cantBuenasAcciones())+ " buenas Acciones.\n";
            info += "Buenas Acciones: [Castidad: " + QString::number(tmp->persona->buenasAcciones[0]) + ",Ayuno: "+ QString::number(tmp->persona->buenasAcciones[1])+",Donacion: "+ QString::number(tmp->persona->buenasAcciones[2])+",Diligencia: "+QString::number(tmp->persona->buenasAcciones[3])+",Calma: "+QString::number(tmp->persona->buenasAcciones[4])+",Solidaridad: "+QString::number(tmp->persona->buenasAcciones[5])+",Humildad: "+QString::number(tmp->persona->buenasAcciones[6])+"]\n\n";
            listaMidnight.agregarHumano(tmp->persona);
            tmp->persona->sucesos.agregarSucesos("Eliminado por Midnight Por "+QString::number(tmp->persona->cantBuenasAcciones())+ " buenas Acciones.");
            aniquiladores.bitacora += tmp->persona->formato("Eliminado por Midnight Por "+QString::number(tmp->persona->cantBuenasAcciones())+ " buenas Acciones.");
        }


        tmp = tmp->siguiente;

    }
    return info;
}

//********************************************************************************************************
QString ListaHumano::killCincuentaPorciento(QString villano, QString deporte){
    int cant = largo*0.5;
    QString info = "La cantidad de humanos elminados son: "+QString::number(cant)+"\n";

    NodoHumano *tmp = primerNodo;
    for (int i=1; i<=cant; i++){
        tmp->persona->vivo = false;
        tmp->persona->salvado = false;
        tmp->persona->aniquilado = true;

        if (villano == "Black"){
            info += "Humano de ID "+QString::number(tmp->persona->ID) +" ["+tmp->persona->nombre+" "+tmp->persona->apellido+ "] Practica el deporte: "+QString::number(tmp->persona->cantDeporte)+ " veces\n";
            listaBlack.agregarHumano(tmp->persona);
            tmp->persona->sucesos.agregarSucesos("Eliminado por Black por practicar "+deporte +" "+QString::number(tmp->persona->cantDeporte)+ " veces");
            aniquiladores.bitacora += tmp->persona->formato("Eliminado por Black por practicar "+deporte +" "+QString::number(tmp->persona->cantDeporte)+ " veces");
        }



        else{
            tmp->persona->sucesos.agregarSucesos("Eliminado por "+villano);
            aniquiladores.bitacora += tmp->persona->formato("Eliminado por "+villano);
        }


        tmp = tmp->siguiente;

    }
    return info;
}

QString Humano::formato (QString informacion){
    QString fecha = planeta.horaFecha();
    QString info = "Humano "+QString::number(ID) + "\t" +nombre+" "+apellido+"\t"+paisOrigen+"\t"+imprimirAmigosOtro()+"\t"+imprimirFamiliaParaArchivo()+imprimirExperienciasParaArchivo()+"\t"+"El dia "+fecha+" "+informacion;
    return fecha + "\t" +info+"\n";
}

QString Humano::imprimirExperienciasParaArchivo(){
    QString info = "\tExperiencias [";
    NodoPais * tmp = paisesVisitados.primerNodo;
    while(tmp != NULL){
       info += tmp->pais;
       if (tmp->siguiente != NULL){
           info+= ",";
       }
       tmp = tmp->siguiente;
    }
    return info+"]";
}

QString Humano::imprimirExperienciasConsultaID(){
    QString info = "\nExperiencias\n\t";
    NodoPais * tmp = paisesVisitados.primerNodo;
    while(tmp != NULL){
       info += tmp->pais;
       if (tmp->siguiente != NULL){
           info+= "\n\t";
       }
       tmp = tmp->siguiente;
    }
    return info;
}

//todos los amigos de una persona estan muertos
bool Humano::allFriendsDead(){
    if (amigos.primerNodo != NULL){
        NodoHumano * tmp = amigos.primerNodo;
        do{
            if (tmp->persona->vivo){
                return false;
            }
            tmp = tmp->siguiente;
        }while(tmp!=amigos.primerNodo);
    }
    return true;
}


//MATA A LOS AMIGOS DE LOS AMIGOS RECURSIVAMENTE (NEBULA)-------------------------------------------------------------------------------
void Humano::killAmigos(){
    //qDebug()<<ID;
    if (amigos.primerNodo != NULL){

        NodoHumano * tmp = amigos.primerNodo;

        do{
            if (tmp->persona->vivo){
                aniquiladores.infoTemporalNebula +=  QString::number(tmp->persona->ID) +" ["+tmp->persona->nombre+" "+tmp->persona->apellido+ "] Eliminado por Nebula por ser amigo de " + QString::number(ID) +" [" +nombre + " "+apellido+"]\n";
                tmp->persona->sucesos.agregarSucesos("Eliminado por Nebula por ser amigo de " + QString::number(ID));
                aniquiladores.bitacora += tmp->persona->formato("Eliminado por Nebula por ser amigo de "+  QString::number(ID)+" [" +nombre + " "+apellido+"]");
                tmp->persona->vivo = false;
                tmp->persona->salvado = false;
                tmp->persona->aniquilado = true;
                aniquiladores.contTemporalNebula ++;
                listaNebula.agregarHumano(tmp->persona);
                tmp->persona->killAmigos();
            }

            tmp = tmp->siguiente;

        }while(tmp!=amigos.primerNodo);
    }
 }
//----------------------------------------------------------------------------------------------------------------------------------------------
ListaHumano * ListaHumano::listaPorDeporte(QString deporte){
    ListaHumano * personas = new ListaHumano();
    if (primerNodo != NULL){
            NodoHumano * tmp = primerNodo;
            do{
                if (tmp->persona->deportes.largo != 0){
                    if (!tmp->persona->deportes.VerificarDeporte(deporte)){
                        personas->agregarHumano(tmp->persona);
                    }
                }

                tmp = tmp->siguiente;
            }while(tmp!=primerNodo);
    }
    return personas;
}


QString ListaHumano::imprimirLista(){
    QString info = "";
    if (primerNodo != NULL){
        NodoHumano * tmp = primerNodo;
        do{
            info += "ID" + QString::number(tmp->persona->ID) + " Nombre: " + tmp->persona->nombre + " "+ tmp->persona->apellido + "\n" +"Deporte por semana: "+QString::number(tmp->persona->cantDeporte)+"\n"+ tmp->persona->deportes.imprimirDeporte() + "\n";
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);
    }
    return info;
}

QString ListaHumano::imprimirNodos(){
    QString info = "";
    if (primerNodo != NULL){
        NodoHumano * tmp = primerNodo;
        do{
            info += "ID" + QString::number(tmp->persona->ID) + " Nombre: " + tmp->persona->nombre + " "+ tmp->persona->apellido + "\n"+tmp->persona->imprimirFamiliaConsultaID()+"\n";
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);
    }
    return info;
}

void Humano::cadenaAmigos(ListaHumano * evaluados){
    evaluados->agregarHumano(this);
    if (amigos.primerNodo != NULL){

        NodoHumano * tmp = amigos.primerNodo;

        do{

            if (!evaluados->esta(tmp->persona)){
                temporal.info += QString::number(tmp->persona->ID) +"\t"+tmp->persona->nombre +" "+tmp->persona->apellido+ "\tamigo de:\t"+ QString::number(ID) +"\t"+nombre+" "+apellido+"\n";
                tmp->persona->cadenaAmigos(evaluados);
            }

            tmp = tmp->siguiente;

        }while(tmp!=amigos.primerNodo);
    }

}
void Humano::cadenaAmigosAux(){
    ListaHumano * lista = new ListaHumano();
    temporal.info = "Amigos directos: \n";
    temporal.info += imprimirAmigos();
    temporal.info += "\nCadena de amigos completa: \n";
    cadenaAmigos(lista);
}

bool ListaHumano::esta(Humano * humano){
    if (primerNodo != NULL){

        NodoHumano * tmp = primerNodo;

        do{
            if (tmp->persona == humano){
                //qDebug() << "entra"<<humano->ID;
                return true;
            }
            tmp = tmp->siguiente;

        }while(tmp!=primerNodo);
    }
    return false;
}


QString Humano::imprimirFamilia(){
    QString informacion = "";
    informacion += "ACTUAL :\n"+ nombre + " "+ apellido+"\n"+imprimirFamiliaConsultaID()+"\n";
    if (Pareja != NULL){
        informacion += "PAREJA :\n"+Pareja->nombre +" " + Pareja->apellido+"-"+QString::number(Pareja->ID)+"\n"+Pareja->imprimirFamiliaConsultaID()+"\n";
    }
    if (Padre != NULL){
        informacion += "PADRE :\n"+Padre->nombre +" " + Padre->apellido+"-"+QString::number(Padre->ID)+"\n"+Padre->imprimirFamiliaConsultaID()+"\n";
    }
    if (Madre != NULL){
        informacion += "MADRE :\n"+Madre->nombre +" "+ Madre->apellido+"-"+QString::number(Madre->ID)+"\n"+Madre->imprimirFamiliaConsultaID()+"\n";
    }
    if(hijos->primerNodo != NULL){
        NodoHumano * tmp = hijos->primerNodo;
        do{
        informacion += "HIJO :\n"+tmp->persona->nombre +" "+ tmp->persona->apellido+"-"+QString::number(tmp->persona->ID)+"\n"+tmp->persona->imprimirFamiliaConsultaID()+"\n";
        tmp = tmp->siguiente;
        }
        while (tmp != hijos->primerNodo);
    }
    return informacion;


}
QString Humano::formatoThanos(int nivel,QString param){
    QString paraSuceso;
    QString paraBitacora;
    QString paraInfo;
    if (param == "nivel"){
        paraSuceso = "Aniquilado por Thanos por ser de nivel: "+QString::number(nivel);
        paraBitacora = formato("Eliminado por Thanos por ser de nivel: "+QString::number(nivel));
        paraInfo = QString::number(ID)+"\t"+nombre+" "+apellido+"\tNacido en: "+QString::number(anno)+"\nEliminado por Thanos por ser de nivel:"+QString::number(nivel)+"\n\n";
    }
    else if (param == "año"){
        paraSuceso = "Aniquilado por Thanos por ser del año: "+QString::number(anno);
        paraBitacora = formato("Eliminado por Thanos por ser del año: "+QString::number(anno));
        paraInfo = QString::number(ID)+"\t"+nombre+" "+apellido+"\tNacido en: "+QString::number(anno)+"\nEliminado por Thanos por ser del año:"+QString::number(anno)+"\n\n";
    }
    else if (param == "ambos"){
        paraSuceso = "Aniquilado por Thanos por ser del año: "+QString::number(anno)+" y del nivel: "+QString::number(nivel);
        paraBitacora = formato("Eliminado por Thanos por ser del año: "+QString::number(anno))+" y del nivel: "+QString::number(nivel);
        paraInfo = QString::number(ID)+"\t"+nombre+" "+apellido+"\tNacido en: "+QString::number(anno)+"\nEliminado por Thanos por ser del año:"+QString::number(anno)+" y del nivel: "+QString::number(nivel)+"\n\n";
    }

    sucesos.agregarSucesos(paraSuceso);
    aniquiladores.bitacora += paraBitacora;
    return paraInfo;
}
QString ListaHumano::matarThanos(int nivel,QString param){
    QString info = "";
    QString suceso;
    if (primerNodo != NULL){
        NodoHumano * tmp =primerNodo;
        do{
            info+= tmp->persona->formatoThanos(nivel,param);
            tmp->persona->vivo = false;
            tmp->persona->salvado = false;
            tmp->persona->aniquilado = true;
            listaThanos.agregarHumano(tmp->persona);
            aniquiladores.contThanos ++;
            tmp = tmp->siguiente;
        }while (tmp !=primerNodo);
    }
    return info;
}


//ALGORITMOS PARA THOR--------------------------
QString Humano::salvarAmigosDirectos(Humano *familiar, int nivel){
    QString info = "";
    if (amigos.primerNodo != NULL){
        NodoHumano * tmp = amigos.primerNodo;
        do{
            if (!tmp->persona->vivo){
                avengers.contTemporalThor ++;
                tmp->persona->vivo = true;
                tmp->persona->salvado = true;
                tmp->persona->aniquilado = false;
                tmp->persona->sucesos.agregarSucesos("Salvado por Thor ser amigo de: "+QString::number(ID)+" ["+nombre+ " "+apellido +"] que es familiar de "
                                                     +QString::number(familiar->ID)+ " ["+familiar->nombre+ " "+familiar->apellido+"] al seleccionar el nivel: "+QString::number(nivel));
                avengers.bitacora += tmp->persona->formato("Salvado por Thor ser amigo de: "+QString::number(ID)+" ["+nombre+ " "+apellido +"] que es familiar de "
                                                           +QString::number(familiar->ID)+ " ["+familiar->nombre+ " "+familiar->apellido+"] al seleccionar el nivel: "+QString::number(nivel));
                avengers.bitacoraThor += tmp->persona->formato("Salvado por Thor ser amigo de: "+QString::number(ID)+" ["+nombre+ " "+apellido +"] que es familiar de "
                                                               +QString::number(familiar->ID)+ " ["+familiar->nombre+ " "+familiar->apellido+"] al seleccionar el nivel: "+QString::number(nivel));
                info += "ID: "+ QString::number(tmp->persona->ID)+" ["+tmp->persona->nombre+ " "+tmp->persona->apellido +"] Salvado por por ser amigo de: "+QString::number(ID)+" ["+nombre+ " "+apellido +"] que es familiar de "
                        +QString::number(familiar->ID)+ " ["+familiar->nombre+ " "+familiar->apellido +"]\n";
                listaThor.agregarHumano(tmp->persona);
            }
            tmp = tmp->siguiente;
        }while(tmp!=amigos.primerNodo);
    }
    return info;
}

QString Humano::salvarAmigosDeFamiliaresDirectos (int nivel){
    QString info = " ";
    if (Padre != NULL){
        qDebug()<<ID<< "Entra a padre";
        info += Padre->salvarAmigosDirectos(this, nivel);
    }
    if (Madre != NULL){
        qDebug()<<ID<< "Entra a madre";
        info += Madre->salvarAmigosDirectos(this, nivel);
    }
    if (Pareja != NULL){
        qDebug()<<ID<< "Entra a pareja";
        info += Pareja->salvarAmigosDirectos(this, nivel);
    }
    //a los hijos
    if (hijos->primerNodo != NULL){
        NodoHumano * tmp = hijos->primerNodo;
        do{
            qDebug()<<ID<< "Entra a hijos";
            info += tmp->persona->salvarAmigosDirectos(this, nivel);
            tmp = tmp->siguiente;

        }while(tmp!=hijos->primerNodo);
    }
    return info;
}
QString ListaHumano::salvarAmigosDeFamilia(int nivel){
    QString info = " ";
    if (primerNodo != NULL){
        NodoHumano * tmp = primerNodo;
        do{
            info += tmp->persona->salvarAmigosDeFamiliaresDirectos(nivel);
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);
    }
    return info;
}
//----------------------------------------------------------------------------------------------------

//IRON MAN
ListaHumano * ListaHumano::seleccionarAleatoriamente(int cant){
    ListaHumano *seleccionados = new ListaHumano();
    std::uniform_int_distribution<int> dist(0, 1);

    if (primerNodo != NULL){
        NodoHumano * tmp = primerNodo;
        do{
            double rand = dist(* QRandomGenerator::global());
            if (rand == 1 && !seleccionados->esta(tmp->persona)){
                seleccionados->agregarHumano(tmp->persona);
            }

            tmp = tmp->siguiente;
        }while(seleccionados->largo < cant);
    }
    return seleccionados;
}
QString Humano::informacionParaIronMan(){
    QString info = "ID "+QString::number(ID)+" Nombre: "+ nombre + " " + apellido+"\n";
    if (Padre != NULL){
        info += "\tPadre: "+QString::number(Padre->ID) +" " + Padre->nombre + " " + Padre->apellido+"\n";
    }
    if (Madre != NULL){
        info += "\tMadre: "+QString::number(Madre->ID) + " " +Madre->nombre + " " + Madre->apellido+"\n";
    }
    if (Pareja != NULL){
        info += "\tPareja: "+QString::number(Pareja->ID) + " " +Pareja->nombre + " " + Pareja->apellido+"\n";
    }
    if(hijos->primerNodo != NULL){
        info += "\tHijos: \n";
        NodoHumano * tmp = hijos->primerNodo;
        do{
            info += "\t"+QString::number(tmp->persona->ID) +" " + tmp->persona->nombre +" "+ tmp->persona->apellido+"\n";
            tmp = tmp->siguiente;
        }
        while (tmp != hijos->primerNodo);
    }
    return info;
}

QString ListaHumano::detonarBombas(){
    //genera random entre 40-60%
    std::uniform_int_distribution<int> dist(40, 60);
    double rand = dist(* QRandomGenerator::global());
    //cantidad de nodos que van a explotar
    int cantExplosiones = round(largo*(rand/100));

    QString info = "Explotan el "+QString::number(rand)+"% de las bombas\nLa cantidad de nodos son: "+QString::number(cantExplosiones)+"\n";

    ListaHumano *seleccionados = seleccionarAleatoriamente(cantExplosiones);
    info += "---------------------------------------------------------------------------------------------\n";
    info += "Los nodos seleccionados son:\n\n";


    if (seleccionados->primerNodo != NULL){
        NodoHumano * tmp = seleccionados->primerNodo;
        do{
            info += tmp->persona->informacionParaIronMan()+"\n";
            tmp = tmp->siguiente;
        }while(tmp!=seleccionados->primerNodo);
    }
    info += "---------------------------------------------------------------------------------------------\n";

    if (seleccionados->primerNodo != NULL){
        NodoHumano * tmp = seleccionados->primerNodo;
        do{
            tmp->persona->salvarFamilia(tmp->persona,tmp->persona);
            tmp = tmp->siguiente;
        }while(tmp!=seleccionados->primerNodo);
    }
    info += avengers.infoTemporalIronMan;
    return info;

}

void Humano::salvarFamilia(Humano * inicial, Humano * relacion){

    if (Padre != NULL){
        if (!Padre->vivo){
            avengers.contTemporalIronMan ++;
            Padre->vivo = true;
            Padre->salvado = true;
            Padre->aniquilado = false;
            Padre->salvarFamilia(inicial, Padre);
            Padre->sucesos.agregarSucesos("Salvado por IronMan al ser padre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
            avengers.infoTemporalIronMan += QString::number(Padre->ID)+" ["+Padre->nombre+" "+Padre->apellido + "]"+" Salvado por IronMan al ser padre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "]"+ " en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]\n";
            listaIronMan.agregarHumano(Padre);
            avengers.bitacora += Padre->formato("Salvado por IronMan al ser padre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
            avengers.bitacoraIronman += Padre->formato("Salvado por IronMan al ser padre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
        }
    }
    if (Madre != NULL){
        if (!Madre->vivo){
            avengers.contTemporalIronMan ++;
            Madre->vivo = true;
            Madre->salvado = true;
            Madre->aniquilado = false;
            Madre->salvarFamilia(inicial, Madre);
            Madre->sucesos.agregarSucesos("Salvado por IronMan al ser madre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
            avengers.infoTemporalIronMan += QString::number(Madre->ID)+" ["+Madre->nombre+" "+Madre->apellido + "]"+"Salvado por IronMan al ser madre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]\n";
            listaIronMan.agregarHumano(Madre);
            avengers.bitacora += Madre->formato("Salvado por IronMan al ser madre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
            avengers.bitacoraIronman += Madre->formato("Salvado por IronMan al ser madre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
        }
    }
    if (Pareja != NULL){
        if (!Pareja->vivo){
            avengers.contTemporalIronMan ++;
            Pareja->vivo = true;
            Pareja->salvado = true;
            Pareja->aniquilado = false;
            Pareja->salvarFamiliaAux(inicial, Pareja);
            Pareja->sucesos.agregarSucesos("Salvado por IronMan al ser pareja de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
            avengers.infoTemporalIronMan += QString::number(Pareja->ID)+" ["+Pareja->nombre+" "+Pareja->apellido + "]"+" Salvado por IronMan al ser pareja de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]\n";
            listaIronMan.agregarHumano(Pareja);
            avengers.bitacora += Pareja->formato("Salvado por IronMan al ser Pareja de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
            avengers.bitacoraIronman += Pareja->formato("Salvado por IronMan al ser pareja de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");

        }
    }
    if (hijos->primerNodo != NULL){
        NodoHumano * tmp = hijos->primerNodo;

        do{
            if (!tmp->persona->vivo){
                avengers.contTemporalIronMan ++;
                tmp->persona->vivo = true;
                tmp->persona->salvado = true;
                tmp->persona->aniquilado = false;
                tmp->persona->salvarFamilia(inicial, tmp->persona);
                tmp->persona->sucesos.agregarSucesos("Salvado por IronMan al ser hijo de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
                avengers.infoTemporalIronMan += QString::number(tmp->persona->ID)+" ["+tmp->persona->nombre+" "+tmp->persona->apellido + "]"+" Salvado por IronMan al ser hijo de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]\n";
                listaIronMan.agregarHumano(tmp->persona);
                avengers.bitacora += tmp->persona->formato("Salvado por IronMan al ser hijo de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
                avengers.bitacoraIronman += tmp->persona->formato("Salvado por IronMan al ser hijo de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");

            }

            tmp = tmp->siguiente;

        }while(tmp!=hijos->primerNodo);
    }
 }

void Humano::salvarFamiliaAux(Humano * inicial, Humano * relacion){
    qDebug()<<ID;
    if (Padre != NULL){
        if (!Padre->vivo){
            avengers.contTemporalIronMan ++;
            Padre->vivo = true;
            Padre->salvado = true;
            Padre->aniquilado = false;
            Padre->salvarFamilia(inicial, Padre);
            Padre->sucesos.agregarSucesos("Salvado por IronMan al ser padre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
            avengers.infoTemporalIronMan += QString::number(Padre->ID)+" ["+Padre->nombre+" "+Padre->apellido + "]"+" Salvado por IronMan al ser padre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "]"+ " en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]\n";
            listaIronMan.agregarHumano(Padre);
            avengers.bitacora += Padre->formato("Salvado por IronMan al ser padre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
            avengers.bitacoraIronman += Padre->formato("Salvado por IronMan al ser padre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
        }
    }
    if (Madre != NULL){
        if (!Madre->vivo){
            avengers.contTemporalIronMan ++;
            Madre->vivo = true;
            Madre->salvado = true;
            Madre->aniquilado = false;
            Madre->salvarFamilia(inicial, Madre);
            Madre->sucesos.agregarSucesos("Salvado por IronMan al ser madre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
            avengers.infoTemporalIronMan += QString::number(Madre->ID)+" ["+Madre->nombre+" "+Madre->apellido + "]"+"Salvado por IronMan al ser madre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]\n";
            listaIronMan.agregarHumano(Madre);
            avengers.bitacora += Madre->formato("Salvado por IronMan al ser madre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
            avengers.bitacoraIronman += Madre->formato("Salvado por IronMan al ser madre de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
        }
    }

    if (hijos->primerNodo != NULL){
        NodoHumano * tmp = hijos->primerNodo;

        do{
            if (!tmp->persona->vivo){
                avengers.contTemporalIronMan ++;
                tmp->persona->vivo = true;
                tmp->persona->salvado = true;
                tmp->persona->aniquilado = false;
                tmp->persona->salvarFamilia(inicial, tmp->persona);
                tmp->persona->sucesos.agregarSucesos("Salvado por IronMan al ser hijo de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
                avengers.infoTemporalIronMan += QString::number(tmp->persona->ID)+" Salvado por IronMan al ser hijo de: "+QString::number(relacion->ID)+" en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+"\n";
                listaIronMan.agregarHumano(tmp->persona);
                avengers.bitacora += tmp->persona->formato("Salvado por IronMan al ser hijo de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");
                avengers.bitacoraIronman += tmp->persona->formato("Salvado por IronMan al ser hijo de: "+QString::number(relacion->ID)+" ["+relacion->nombre+" "+relacion->apellido + "] en cadena al explotar la bomba del nodo: "+QString::number(inicial->ID)+" ["+inicial->nombre+" "+inicial->apellido + "]");

            }

            tmp = tmp->siguiente;

        }while(tmp!=hijos->primerNodo);
    }
}
//*********************SPIDERMAN*************************************************************************
ListaHumano * ListaHumano::colocarTelarana(){
    qDebug()<<"largo de preorden "<<largo;
    ListaHumano *telarana = new ListaHumano();
    std::uniform_int_distribution<int> dist(0, 1);

    if (primerNodo != NULL){
        NodoHumano * tmp = primerNodo;
        do{
            int rand = dist(* QRandomGenerator::global());
            if (rand != 0){ //coloca telarana
                telarana->agregarHumano(tmp->persona);
            }
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);
    }
    qDebug()<<"largo de telarana "<<telarana->largo;
    return telarana;
}

QString ListaHumano::recorrerTelarana(){
    QString info = "Spiderman coloca telarana en "+QString::number(largo)+" nodos\n";
    info += "Nodos:\n";

    ///////////////////////////////////////////////////
    if (primerNodo != NULL){
        NodoHumano * tmp = primerNodo;
        do{
            info += "Nodo que contiene al humano: "+QString::number(tmp->persona->ID)+" ["+tmp->persona->nombre+" "+tmp->persona->apellido+"]\tIndex: "+QString::number(tmp->persona->index)+"\n";
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);
    }
    ////////////////////////////////////////////////////
    if (primerNodo != NULL){
        NodoHumano * tmp = primerNodo;
        do{
            if (arbolMundial.esHoja(tmp->persona->index)){
                info += "\nLa primer hoja encontrada al recorrer la telerana es "+QString::number(tmp->persona->ID)+"\n";
                info += "Se evaluaran  "+QString::number(largo)+" humanos para ver si hay que salvarlos\n";
                //
                info += poblacionMundial.salvarNodos(planeta.buscarID(tmp->persona->ID), largo);
                break;
            }
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);
    }
    return info;
}


QString ListaHumano::salvarNodos(NodoHumano *inicio, int cant){
    QString info = "Humanos candidatos\n\n";
    int cont = 0;
    NodoHumano * tmp2 = inicio;
        do{
            info += "Humano: "+QString::number(tmp2->persona->ID)+"[ "+tmp2->persona->nombre+" "+tmp2->persona->nombre+"] Index: "+QString::number(tmp2->persona->index)+" Vivo: "+QString::number(tmp2->persona->vivo)+"\n";
            tmp2 = tmp2->siguiente;
            cont ++;
        }while(tmp2!=inicio && cont < cant);
    info += "\n\nHumanos Salvados: \n";
    cont = 0;
    NodoHumano * tmp = inicio;
        do{
            if (!tmp->persona->vivo){

                info += tmp->persona->informacionParaSpiderman(cont, inicio->persona);
                avengers.contTemporalSpiderman ++;
                tmp->persona->vivo = true;
                tmp->persona->salvado = true;
                tmp->persona->aniquilado = false;

                tmp->persona->sucesos.agregarSucesos("Salvado por Spiderman por estar "+QString::number(cont)+" posiciones depues de la hoja de la telarana: "+QString::number(inicio->persona->ID)+" index "+QString::number(inicio->persona->index));
                //avengers.infoTemporalSpiderman += QString::number(tmp->persona->ID)+" Salvado por Spiderman\n";
                listaSpiderman.agregarHumano(tmp->persona);
                avengers.bitacora += tmp->persona->formato("Salvado por Spiderman por estar "+QString::number(cont)+" posiciones depues de la hoja de la telarana: "+QString::number(inicio->persona->ID)+" index "+QString::number(inicio->persona->index));
                avengers.bitacoraSpiderman += tmp->persona->formato("Salvado por Spiderman por estar "+QString::number(cont)+" posiciones depues de la hoja de la telarana: "+QString::number(inicio->persona->ID)+" index "+QString::number(inicio->persona->index));
            }
            tmp = tmp->siguiente;
            cont ++;
        }while(tmp!=inicio && cont < cant);
    return info;
}

QString Humano::informacionParaSpiderman(int num, Humano * hoja){
    QString info = "ID "+QString::number(ID)+" Nombre: "+ nombre + " " + apellido+" Index "+QString::number(index)+" Por estar "+QString::number(num)+" posiciones depues de la hoja de la telarana: "+QString::number(hoja->ID)+" index "+QString::number(hoja->index)+"\n";
    return info;
}

int Humano::cantFamiliares(){
    int cant = 0;
    if (Padre != NULL){
        cant ++;
    }
    if (Madre != NULL){
        cant ++;
    }
    if (Pareja != NULL){
        cant ++;
    }
    cant += hijos->largo;
    return cant;
}
//********************************************************************************
int ListaHumano::cantVivos(){
    int cant = 0;
    if (primerNodo != NULL){
        NodoHumano * tmp = primerNodo;
        do{
            if (tmp->persona->vivo){
                cant ++;
            }
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);
    }
    return cant;
}

int ListaHumano::cantMuertos(){
    int cant = 0;
    if (primerNodo != NULL){
        NodoHumano * tmp = primerNodo;
        do{
            if (!tmp->persona->vivo){
                cant ++;
            }
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);
    }
    return cant;
}
int ListaHumano::cantSalvados(){
    int cant = 0;
    if (primerNodo != NULL){
        NodoHumano * tmp = primerNodo;
        do{
            if (tmp->persona->salvado){
                cant ++;
            }
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);
    }
    return cant;
}
int ListaHumano::cantSinSucesos(){
    int cant = 0;
    if (primerNodo != NULL){
        NodoHumano * tmp = primerNodo;
        do{
            if (tmp->persona->sucesos.largo == 0){
                cant ++;
            }
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);
    }
    return cant;
}

QString ListaHumano::consultaCantidades(){
    QString info = "ESTADISTICAS!\n\n";
    info += "Cant de Humanos:\t"+QString::number(largo)+"\n";
    info += "Humanos vivos:\t"+QString::number(cantVivos())+"\n";
    info += "Humanos muertos/aniquilados:\t"+QString::number(cantMuertos())+"\n";
    info += "Humanos salvados:\t"+QString::number(cantSalvados())+"\n";
    info += "Humanos sin afectaciones:\t"+QString::number(cantSinSucesos())+"\n";
    return info;
}

QString Humano::formatoAuxiliar(){
    QString infoSucesos = "[";
    if (sucesos.primerNodo != NULL){
        NodoSuceso * tmp = sucesos.primerNodo;
        do{
            infoSucesos += tmp->suceso;
            if (tmp->siguiente != NULL){
                infoSucesos += ";";
            }
            tmp = tmp->siguiente;
        }while(tmp!=NULL);

    }
    infoSucesos += "]";
    QString pecado = "Pecados: [Lujuria: " + QString::number(pecados[0])  + ",Gula: " + QString::number(pecados[1])  + ",Avaricia: "+ QString::number(pecados[2])+",Pereza: " + QString::number(pecados[3])+",Ira: "+QString::number(pecados[4])+",Envidia: "+QString::number(pecados[5])+",Soberbia: "+QString::number(pecados[6])+"]";
    QString acciones = "Buenas Acciones: [Castidad: " + QString::number(buenasAcciones[0]) + "Ayuno: "+ QString::number(buenasAcciones[1])+"Donacion: "+ QString::number(buenasAcciones[2])+"Diligencia: "+QString::number(buenasAcciones[3])+"Calma: "+QString::number(buenasAcciones[4])+"Solidaridad: "+QString::number(buenasAcciones[5])+"Humildad: "+QString::number(buenasAcciones[6])+"]";
    QString info = "Humano "+QString::number(ID) + "\t" +nombre+" "+apellido+"\t"+paisOrigen+"\tVivo: "+QString::number(vivo)+"\tAnno Nacimiento: "+QString::number(anno)+"\tEstado: "+estadoMarital+"\tGrupo Etario: "+grupoEtario+"\t"+imprimirListaDeportes()+"\t"+imprimirAmigosOtro()+"\t"+imprimirFamiliaParaArchivo()+imprimirExperienciasParaArchivo()+"\t"+pecado+"\t"+acciones+"\t"+infoSucesos;
    return  info;
}

QString ListaHumano::formatoParaConsultasTxt(){
    QString info = "";
    if (primerNodo != NULL){
        NodoHumano * tmp = primerNodo;
        do{
            info += tmp->persona->formatoAuxiliar()+"\n";
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);
    }
    return info;
}

QString Humano::imprimirListaDeportes(){
    QString info = "Deporte por semana: "+QString::number(cantDeporte)+" [";
    NodoDeporte * tmp = deportes.primerNodo;
    while(tmp != NULL){
        info += tmp->deporte;
        if (tmp->siguiente != NULL){
            info += ",";
        }
        tmp = tmp->siguiente;
    }
    return info+"]";
}
void Humano::matarEbonyMaw(Humano * tmp){
    aniquiladores.infoTemporalEbonyMaw += "Eliminado por Ebony Maw "+tmp->nombre+tmp->apellido+"-"+ QString::number(tmp->ID) +
                                          " por ser familia de " +nombre+apellido+"-"+  QString::number(ID) + "\n";
    tmp->sucesos.agregarSucesos("Eliminado por Ebony Maw  por ser familia de " +nombre+apellido+"-"+ QString::number(ID));
    aniquiladores.bitacora += tmp->formato("Eliminado por Ebony Maw por ser familia de "+nombre+apellido+"-"+ QString::number(ID));
    tmp->vivo = false;
    tmp->salvado = false;
    tmp->aniquilado = true;
    aniquiladores.contTemporalEbonyMaw ++;
    listaEbonyMaw.agregarHumano(tmp);
}
void Humano::matarHijosAux(){
    if (hijos->primerNodo != NULL){
        NodoHumano * tmp = hijos->primerNodo;
        do{
            if (tmp->persona->vivo){
                matarEbonyMaw(tmp->persona);
                if (tmp->persona->Pareja != NULL && tmp->persona->Pareja->vivo)
                    matarEbonyMaw(tmp->persona->Pareja);
            }

            tmp = tmp->siguiente;

        }while(tmp!=hijos->primerNodo);
    }
}
void Humano::matarGeneracionAnterior(){
    if (Madre != NULL || Padre != NULL){
        if (Madre != NULL && Madre->vivo){
            matarEbonyMaw(Madre);
            Madre->matarSiguienteGeneracion();
            Madre->matarGeneracionAnterior();
        }
        if (Padre != NULL && Padre->vivo){
            matarEbonyMaw(Padre);
            Padre->matarSiguienteGeneracion();
            Padre->matarGeneracionAnterior();
        }
    }
    if (Pareja != NULL && Pareja->vivo){
        matarEbonyMaw(Pareja);
        Pareja->matarGeneracionAnterior();
        Pareja->matarSiguienteGeneracion();}
 }
void Humano::matarSiguienteGeneracion(){
    if (hijos->primerNodo != NULL){
        NodoHumano * tmp = hijos->primerNodo;
        do{
            if (tmp->persona->vivo){
                matarEbonyMaw(tmp->persona);
                /*
                if (tmp->persona->Pareja != NULL && tmp->persona->Pareja->vivo)
                    matarEbonyMaw(tmp->persona->Pareja);*/
                tmp->persona->matarSiguienteGeneracion();
                tmp->persona->matarGeneracionAnterior();
            }

            tmp = tmp->siguiente;

        }while(tmp!=hijos->primerNodo);
    }
 }
void Humano::matarFamilia(){
    matarSiguienteGeneracion();
    matarGeneracionAnterior();
}
