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
    QString deporte = "Deporte por semana: "+QString::number(cantDeporte)+"\n" + deportes.imprimirDeporte();
    QString pecado = "Pecados: \n Lujuria: " + QString::number(pecados[0])  + " Gula: " + QString::number(pecados[1])  + " Avaricia: "+ QString::number(pecados[2])+" Pereza: " + QString::number(pecados[3])+" Ira: "+QString::number(pecados[4])+" Envidia: "+QString::number(pecados[5])+" Soberbia: "+QString::number(pecados[6])+"\n";
    QString acciones = "Buenas Acciones: \n Castidad: " + QString::number(buenasAcciones[0]) + " Ayuno: "+ QString::number(buenasAcciones[1])+" Donacion: "+ QString::number(buenasAcciones[2])+" Diligencia: "+QString::number(buenasAcciones[3])+" Calma: "+QString::number(buenasAcciones[4])+" Solidaridad: "+QString::number(buenasAcciones[5])+" Humildad: "+QString::number(buenasAcciones[6])+"\n";
    QString vida = "Vivo: "+QString::number(vivo)+"\n";
    QString listaSucesos = sucesos.mostrarLista();
    /*qDebug() <<"ID"<<ID<<" Nombre: "<<nombre <<apellido << "Genero: "<<genero<<"pais: "<<paisOrigen  << "Grupo Etario: "<<grupoEtario<< "Anno: "<<anno<<Qt::endl;
    qDebug() <<"Pecados: "<<"Lujuria: "<<pecados[0]<<"Gula: "<<pecados[1]<<"Avaricia: "<<pecados[2]<<"Pereza: "<<pecados[3]<<"Ira: "<<pecados[4]<<"Envidia: "<<pecados[5]<<"Soberbia: "<<pecados[6]<<Qt::endl;
    qDebug() <<"Buenas Acciones: "<<"Castidad: "<<buenasAcciones[0]<<"Ayuno: "<<buenasAcciones[1]<<"Donacion: "<<buenasAcciones[2]<<"Diligencia: "<<buenasAcciones[3]<<"Calma: "<<buenasAcciones[4]<<"Solidaridad: "<<buenasAcciones[5]<<"Humildad: "<<buenasAcciones[6]<<Qt::endl;
*/
    return humano +vida + amigos + deporte + pecado + acciones + listaSucesos;
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
bool Humano::encontrarParentesco(NodoHumano * padre,NodoHumano * hijo){
   QString generoPadre = hijo->persona->genero;
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
    if (nodoHumano->persona->edad >= 24){
        if (nodoHumano->persona->hijos->largo < nodoHumano->persona->cantHijos){
            NodoHumano * tmp = nodoHumano->siguiente;
            do{
                if(nodoHumano->persona->paisOrigen == tmp->persona->paisOrigen){
                    if (posiblePadre(nodoHumano, tmp))
                        crearHijosAux(nodoHumano, tmp);
               }
                else if(tmp->persona->Padre != NULL && tmp->persona->paisOrigen == tmp->persona->Padre->paisOrigen ){
               //     if (posiblePadre(nodoHumano, tmp))
                        crearHijosAux(nodoHumano, tmp);
                }
                else if(tmp->persona->Madre != NULL && tmp->persona->paisOrigen == tmp->persona->Madre->paisOrigen ){
                //   if (posiblePadre(nodoHumano, tmp))
                        crearHijosAux(nodoHumano, tmp);
                }
                tmp = tmp->siguiente;
              }while(tmp != nodoHumano && nodoHumano->persona->hijos->largo < nodoHumano->persona->cantHijos);
        }
    }
}

void Humano::generarEstadoMarital(){
    std::uniform_int_distribution<int> dist(0, 100);
    int status = dist(* QRandomGenerator::global());
    if (edad >= 24){
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
    if (nodoHumano->persona->estadoMarital == "Casado"){
       NodoHumano * tmp = nodoHumano->siguiente;
       do{
           if(tmp->persona->estadoMarital == "Casado" && tmp->persona->Pareja == NULL){
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

QString Humano::imprimirAmigosOtro(){
    QString info = " Amigos [";

    if (amigos.primerNodo != NULL){
        NodoHumano * tmp = amigos.primerNodo;
        do{
            info += QString::number(tmp->persona->ID)+ " "+tmp->persona->nombre+ " "+" "+ tmp->persona->apellido+",";
            tmp = tmp->siguiente;
        }while(tmp!=amigos.primerNodo);
    }
    return info+"]";
}


void Humano::generarCantHijos(){
    if (edad >= 24){
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

QString ListaHumano::matarCincoHp(QString villano){
    int cant = largo*0.05;
    QString info = "La cantidad de humanos elminados son: "+QString::number(cant)+"\n";
    NodoHumano *tmp = primerNodo;
    for (int i=1; i<=cant; i++){
        tmp->persona->vivo = false;
        if (villano == "Corvus"){
            info += "Humano de ID "+QString::number(tmp->persona->ID) + " Por "+QString::number(tmp->persona->cantPecados())+ " pecados.\n";
            listaCorvus.agregarHumano(tmp->persona);
        }
        else if (villano == "Midnight"){
            info += "Humano de ID "+QString::number(tmp->persona->ID) + " Por "+QString::number(tmp->persona->cantBuenasAcciones())+ " buenas Acciones.\n";
            listaMidnight.agregarHumano(tmp->persona);
        }

        tmp->persona->sucesos.agregarSucesos("Eliminado por "+villano);
        aniquiladores.bitacora += tmp->persona->formato("Eliminado por "+villano);
        tmp = tmp->siguiente;

    }
    return info;
}

QString ListaHumano::killCincuentaPorciento(QString villano, QString deporte){
    int cant = largo*0.5;
    QString info = "La cantidad de humanos elminados son: "+QString::number(cant)+"\n";

    NodoHumano *tmp = primerNodo;
    for (int i=1; i<=cant; i++){
        qDebug ()<<"entra";
        tmp->persona->vivo = false;

        if (villano == "Black"){
            qDebug ()<<"llega";
            info += "Humano de ID "+QString::number(tmp->persona->ID) + " Practica el deporte: "+QString::number(tmp->persona->cantDeporte)+ " veces\n";
            listaCorvus.agregarHumano(tmp->persona);
        }
        qDebug ()<<"sale";

        if (villano == "Black"){
            tmp->persona->sucesos.agregarSucesos("Eliminado por "+villano+" Por practicar "+deporte +QString::number(tmp->persona->cantDeporte)+ " veces");
            aniquiladores.bitacora += tmp->persona->formato("Eliminado por "+villano+" Por practicar "+deporte +QString::number(tmp->persona->cantDeporte)+ " veces");
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
    QString info = "Humano "+QString::number(ID) + " "+nombre+" "+apellido+" "+paisOrigen+imprimirAmigosOtro()+informacion;
    return fecha + "  "+info+"\n";
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


void Humano::killAmigos(){
    qDebug()<<ID;
    if (amigos.primerNodo != NULL){

        NodoHumano * tmp = amigos.primerNodo;

        do{
            if (tmp->persona->vivo){
                aniquiladores.infoTemporalNebula += "Eliminado por Nebula " + QString::number(tmp->persona->ID) + " por ser amigo de " + QString::number(ID) + "\n";
                tmp->persona->sucesos.agregarSucesos("Eliminado por Nebula por ser amigo de " + QString::number(ID));
                aniquiladores.bitacora += tmp->persona->formato("Eliminado por Nebula por ser amigo de "+  QString::number(ID));
                tmp->persona->vivo = false;
                aniquiladores.contTemporalNebula ++;
                listaNebula.agregarHumano(tmp->persona);
                tmp->persona->killAmigos();
            }

            tmp = tmp->siguiente;

        }while(tmp!=amigos.primerNodo);
    }
 }

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
            info += "ID" + QString::number(tmp->persona->ID) + " Nombre: " + tmp->persona->nombre + " "+ tmp->persona->apellido + "\n" + tmp->persona->deportes.imprimirDeporte() + "\n";
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
                temporal.info += QString::number(tmp->persona->ID) + " amigo de: "+ QString::number(ID) +"\n";
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
                qDebug() << "entra"<<humano->ID;
                return true;
            }
            tmp = tmp->siguiente;

        }while(tmp!=primerNodo);
    }
    return false;
}


void Humano::imprimirFamilia(QString array[]){
    QString padre,madre,humano,hijo;
    int cont = 3;
    if (Padre != NULL){
        padre =Padre->nombre +" " + Padre->apellido+"-"+Padre->ID;
        array[0] = padre;
    }
    if (Madre != NULL){
        madre = Madre->nombre +" "+ Madre->apellido+"-"+Madre->ID;
        array[1] = madre;
    }
    humano = nombre + " "+ apellido;
    array[2] = humano;
    if(hijos->primerNodo != NULL){
        NodoHumano * tmp = hijos->primerNodo;
        do{
        hijo = tmp->persona->nombre +" "+ tmp->persona->apellido+"-"+QString::number(tmp->persona->ID);
        qDebug()<<"Hijo   : "+hijo;
        array[cont] = hijo;
        cont++;
        tmp = tmp->siguiente;
        }
        while (tmp != hijos->primerNodo);
    }


}
