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
    //qDebug()<<"antes:";
    //heapPecados->mostrarLista();
    //qDebug()<<heapPecados->largo;

    info += heapPecados->matarCincoHp("Corvus");

    //qDebug()<<"despues:";
    //qDebug()<<heapPecados->largo;
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
    //qDebug()<<"antes:";
    //heapBuenasAcciones->mostrarLista();
    //qDebug()<<heapBuenasAcciones->largo;

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
    //personas->mostrarLista();
    //qDebug()<<personas->largo;

    info += personas->killCincuentaPorciento("Black", deporte);

    generarArchivo();

    return info;
}
QString TeamAniquileishon::Nebula(int id){
    infoTemporalNebula = " ";
    contTemporalNebula = 0;
    if (planeta.consultaID(id) != NULL){

        if (arbolMundial.buscar(planeta.consultaID(id)->index, arbolMundial.raiz) != NULL){
            if (planeta.consultaID(id)->vivo){
                QString info = "Aniquilando a los amigos recursivamente de :"+QString::number(planeta.consultaID(id)->ID)+" "+planeta.consultaID(id)->nombre+" "+planeta.consultaID(id)->apellido+"\n";
                arbolMundial.buscar(planeta.consultaID(id)->index, arbolMundial.raiz)->humano->persona->killAmigos();
                generarArchivo();
                return "Algoritmo Nebula!\n"+info+"\nEl total de elminados fue: " +QString::number(contTemporalNebula) +"\n"+ infoTemporalNebula;

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
QString matarPorAmbos(int nivel,int anno){
    QString info = "";
    info += HashmapGlobal[2020-anno].nivel[nivel-1].matarThanos(nivel,"ambos");
    return info;
}
QString matarPorAnno(int anno){
    QString info = "";
    for(int i = 0; i<=9;i++){
         info += HashmapGlobal[2020-anno].nivel[i].matarThanos(anno,"año");

    }
    return info;
}
QString matarPorNivel(int pNivel){
    QString info = "";
    for(int i = 0; i<=100;i++){
         info += HashmapGlobal[i].nivel[pNivel-1].matarThanos(pNivel,"nivel");
    }
    return info;
}
QString TeamAniquileishon::Thanos(int opcion,int nivel, int anno){
  aniquiladores.contThanos = 0;
  QString info = "Algoritmo Thanos!\n";
  NodoHumano * tmp = poblacionMundial.primerNodo;
  for (int i = 0; i<=100;i++){
      HashmapGlobal[i] = Hashmap();
  }
  do{
      //qDebug()<<2020-tmp->persona->anno;
      if(tmp->persona->vivo)
        HashmapGlobal[2020-tmp->persona->anno].agregarANivel(tmp->persona);
      //qDebug()<<2020-tmp->persona->anno;
      tmp = tmp->siguiente;
  }while(tmp!=poblacionMundial.primerNodo);

  if(opcion == 0)
      info += matarPorNivel(nivel);
  else if (opcion == 1)
      info += matarPorAnno(anno);
  else
      info += matarPorAmbos(nivel,anno);
  generarArchivo();
  info += "Total de eliminados: "+QString::number(aniquiladores.contThanos);

  info += "\n\nResumen del Hashmap:\n\n";
  for (int i=0; i<=100; i++){
        info += "Año: " + QString::number(2020-i)+":\n";
        for (int j=0; j<10; j++){
            info += "\tNivel: "+QString::number(j+1)+": "+QString::number(HashmapGlobal[i].nivel[j].largo)+"\n";
        }
  }
  return info;
}

QString TeamAniquileishon::consultaThanos(){
    QString info = "Consulta-Resumen Aniquiladores\n";
    info += "Total de Aniquilados acumulados: "+QString::number(listaCorvus.largo+listaMidnight.largo+listaNebula.largo+listaBlack.largo+listaThanos.largo)+"\n\n";
    info += "1- Corvus Glaive\n";
    info += "Total de aniquilados: "+QString::number(listaCorvus.largo)+"\n";
    info += "Descripcion de los humanos aniquilados:\n";
    info += listaCorvus.formatoParaConsultasTxt()+"\n\n";

    info += "2- Midnight\n";
    info += "Total de aniquilados: "+QString::number(listaMidnight.largo)+"\n";
    info += "Descripcion de los humanos aniquilados:\n";
    info += listaMidnight.formatoParaConsultasTxt()+"\n\n";

    info += "3- Nebula\n";
    info += "Total de aniquilados: "+QString::number(listaNebula.largo)+"\n";
    info += "Descripcion de los humanos aniquilados:\n";
    info += listaNebula.formatoParaConsultasTxt()+"\n\n";

    info += "4- Ebony\n";
    info += "Total de aniquilados: "+QString::number(listaEbonyMaw.largo)+"\n";
    info += "Descripcion de los humanos aniquilados:\n";
    info += listaEbonyMaw.formatoParaConsultasTxt()+"\n\n";

    info += "5- Black Dwarf\n";
    info += "Total de aniquilados: "+QString::number(listaBlack.largo)+"\n";
    info += "Descripcion de los humanos aniquilados:\n";
    info += listaBlack.formatoParaConsultasTxt()+"\n\n";

    info += "6- Thanos\n";
    info += "Total de aniquilados: "+QString::number(listaThanos.largo)+"\n";
    info += "Descripcion de los humanos aniquilados:\n";
    info += listaThanos.formatoParaConsultasTxt()+"\n\n";


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
    QString ruta = "consultaThanos/"+nombre+".txt";
    std::string nombreArchivo = ruta.toStdString();

    ofstream file;
    file.open(nombreArchivo);
    file << info.toStdString();
    file.close();

    return "listo";
}

QString TeamAniquileishon::EbonyMaw(int id){
    infoTemporalEbonyMaw = "";
     contTemporalEbonyMaw = 0;
    if (planeta.consultaID(id) != NULL){
            if (planeta.consultaID(id)->vivo){
                QString info = " Aniquilando a la familia de :"+QString::number(planeta.consultaID(id)->ID)+" "+planeta.consultaID(id)->nombre+" "+planeta.consultaID(id)->apellido+"\n";
               planeta.consultaID(id)->matarFamilia();
                generarArchivo();
                return "Algoritmo Ebony Maw!\nEl total de elminados fue: " +QString::number(contTemporalEbonyMaw)+ info + infoTemporalEbonyMaw;
            }

            else{
                return "El humano seleccionado esta muerto";
            }

        }


    return "El ID no existe";


}
