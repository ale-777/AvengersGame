#include "aniquilacion.h"
#include "Globals.h"
void TeamAniquileishon::generarArchivo (){

    QDate algo = QDate::currentDate();
    int dias = algo.day();
    int mes = algo.month();
    int anno = algo.year();
    QString fecha = QString::number(anno)+"_"+QString::number(mes)+"_"+QString::number(dias);
    QStringList date= fecha.split(QLatin1Char('_'), Qt::SkipEmptyParts);
    QString fechaBuena = date[0]+date[1]+date[2];

    QDateTime tiempo = QDateTime::currentDateTime();
    QTime hora = tiempo.time();
    QString hora2 = hora.toString();

    QStringList time= hora2.split(QLatin1Char(':'), Qt::SkipEmptyParts);
    QString horaBuena =  time[0]+time[1]+time[2];

    QString nombre = fechaBuena+"_"+horaBuena;
    QString ruta = "archivosAniquilacion/"+nombre+".txt";
    std::string nombreArchivo = ruta.toStdString();

    ofstream file;
    file.open(nombreArchivo);
    file << bitacora.toStdString();
    file.close();
}



QString TeamAniquileishon::Corvus (){
    QString info = "Algoritmo Corvus!\n";
    ListaHumano *heapPecados = new ListaHumano();

    if (poblacionMundial.primerNodo != NULL){
        NodoHumano * tmp = poblacionMundial.primerNodo;
        do{
            if (tmp->persona->vivo)
                heapPecados->agregarPorPecados(tmp->persona);

            tmp = tmp->siguiente;

        }while(tmp!=poblacionMundial.primerNodo);
    }
    info += "Se esta evaluando la cantidad de pecados de: "+QString::number(heapPecados->largo) + " personas (Todos los humanos vivos)\n";
    qDebug()<<"antes:";
    heapPecados->mostrarLista();
    qDebug()<<heapPecados->largo;

    info += heapPecados->matarCincoHp("Corvus");

    qDebug()<<"despues:";
    qDebug()<<heapPecados->largo;
    generarArchivo();

    return info;
}

QString TeamAniquileishon::Midnight(){
    QString info = "Algoritmo Midnight!\n";
    ListaHumano *heapBuenasAcciones = new ListaHumano();

    if (poblacionMundial.primerNodo != NULL){
        NodoHumano * tmp = poblacionMundial.primerNodo;
        do{
            if (tmp->persona->vivo)
                heapBuenasAcciones->agregarPorBuenasAcciones(tmp->persona);

            tmp = tmp->siguiente;

        }while(tmp!=poblacionMundial.primerNodo);
    }
    info += "Se esta evaluando la cantidad de buenas Acciones de: "+QString::number(heapBuenasAcciones->largo) + " personas (Todos los humanos vivos)\n";
    qDebug()<<"antes:";
    heapBuenasAcciones->mostrarLista();
    qDebug()<<heapBuenasAcciones->largo;

    info += heapBuenasAcciones->matarCincoHp("Midnight");
    generarArchivo();

    return info;
}
QString TeamAniquileishon::Black(int rutina, QString deporte){
    QString info = "Algoritmo Black Dwarf!\n";
    ListaHumano *personas = new ListaHumano();

    if (poblacionMundial.primerNodo != NULL){
            NodoHumano * tmp = poblacionMundial.primerNodo;
            do{
                if (tmp->persona->vivo && tmp->persona->cantDeporte>rutina){
                    if (tmp->persona->deportes.largo != 0){
                        if (!tmp->persona->deportes.VerificarDeporte(deporte)){
                            personas->agregarHumano(tmp->persona);
                        }
                    }


                }

                tmp = tmp->siguiente;

            }while(tmp!=poblacionMundial.primerNodo);
        }

    info += "Se estan evaluando: "+QString::number(personas->largo) + " personas (Todos los humanos vivos que practican "+deporte+ " mas de "+QString::number(rutina) +" veces)\n";
    personas->mostrarLista();
    qDebug()<<personas->largo;

    info += personas->killCincuentaPorciento("Black", deporte);

    generarArchivo();

    return info;
}
struct Hashmap{
    int largo = 0;
    ListaHumano nivel[10];
    int calcularValor(Humano *persona){
        int total = 0;
        int promP = 0;
        int promB = 0;
        total += 100-persona->edad*2;
        for (int i = 0; i<7; i++){
            promP += persona->pecados[i];
            promB += persona->buenasAcciones[i];
        }
        total += ((promB/7)-(promP/7));
        total += persona->cantDeporte*10;
        total += persona->amigos.largo*5;
        total += persona->hijos->largo*10;
        total += persona->paisesVisitados.largo;
        return total;
    }
    void agregarANivel(Humano *agregado){
        int valor = calcularValor(agregado);
        if (valor < 0){
           nivel[0].agregarHumano(agregado);
        }
        else if(valor < 50){
            nivel[1].agregarHumano(agregado);
        }
        else if(valor < 75){
            nivel[2].agregarHumano(agregado);
        }
        else if(valor < 100){
            nivel[3].agregarHumano(agregado);
        }
        else if(valor < 125){
            nivel[4].agregarHumano(agregado);
        }
        else if(valor < 150){
            nivel[5].agregarHumano(agregado);
        }
        else if(valor < 175){
            nivel[6].agregarHumano(agregado);
        }
        else if(valor < 200){
            nivel[7].agregarHumano(agregado);
        }
        else if(valor < 225){
            nivel[8].agregarHumano(agregado);
        }
        else{
            nivel[9].agregarHumano(agregado);
        }
        largo++;
    }
};
QString TeamAniquileishon::generarHashMap(){
  QString info = "Algoritmo Thanos!\n";
  Hashmap hashYear[101];
  int largototal = 0;
  NodoHumano * tmp = poblacionMundial.primerNodo;
  qDebug()<<"Llega";
  do{
      //qDebug()<<2020-tmp->persona->anno;
      if(tmp->persona->vivo)
        hashYear[2020-tmp->persona->anno].agregarANivel(tmp->persona);
      //qDebug()<<2020-tmp->persona->anno;
      tmp = tmp->siguiente;
  }while(tmp!=poblacionMundial.primerNodo);
  qDebug()<<"Imprimir";
  for(int i = 0; i<=100; i++){
     qDebug()<<"Año: "<<i+1920;
     for(int j = 0; j<10; j++){
         qDebug()<<"Nivel #"<<j<<" Largo: "<<hashYear[i].nivel[j].largo;
        }
  }
  return info;
}
QString TeamAniquileishon::Nebula(int id){
    infoTemporalNebula = " ";
    contTemporalNebula = 0;
    if (planeta.consultaID(id) != NULL){

        if (arbolMundial.buscar(planeta.consultaID(id)->index, arbolMundial.raiz) != NULL){
            if (planeta.consultaID(id)->vivo){
                QString info = " Aniquilando a los amigos recursivamente de :"+QString::number(planeta.consultaID(id)->ID)+" "+planeta.consultaID(id)->nombre+" "+planeta.consultaID(id)->apellido+"\n";
                arbolMundial.buscar(planeta.consultaID(id)->index, arbolMundial.raiz)->humano->persona->killAmigos();
                generarArchivo();
                return "Algoritmo Nebula!\nEl total de elminados fue: " +QString::number(contTemporalNebula)+ info + infoTemporalNebula;

            }
            else{
                return "El humano seleccionado esta muerto";
            }

        }
        else {
            return "El ID seleccionado no pertenece al arbol";
        }
    }
    return "El ID no existe";


}
