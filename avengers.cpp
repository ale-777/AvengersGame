#include "Globals.h"

void Avengers::generarArchivo (){

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
    QString ruta = "archivosSalvacion/"+nombre+".txt";
    std::string nombreArchivo = ruta.toStdString();

    ofstream file;
    file.open(nombreArchivo);
    file << bitacora.toStdString();
    file.close();
}

//THOR
QString Avengers::Thor(int nivel){
    QString info = "Algoritmo Thor\n";
    nivelXArbol.init();
    arbolMundial.returnNivel(arbolMundial.raiz, nivel);
    info += nivelXArbol.salvarAmigosDeFamilia(nivel);
    generarArchivo();
    return info;
}

//IRON MAN
QString Avengers::IronMan (){
    contTemporalIronMan = 0;
    infoTemporalIronMan = "";
    QString info = "Algoritmo Ironman\n";
    arbolPreOrden.init(); //reinicia la lista
    arbolMundial.preOrden(arbolMundial.raiz); //llena de nuevo la lista preorden
    info += arbolPreOrden.detonarBombas();
    info += "Cant de salvados: "+QString::number(avengers.contTemporalIronMan)+"\n";
    generarArchivo();
    return info;
}


//SPIDERMAN****************************************************************
QString Avengers::Spiderman(){
    arbolAListaParaSpiderman.init();
    QString info = "Algoritmo Spiderman\n";

    arbolMundial.preOrdenSpiderman(arbolMundial.raiz);

    ListaHumano * telarana = arbolAListaParaSpiderman.colocarTelarana();
    info += telarana->recorrerTelarana();
    info += "Salvados: "+QString::number(avengers.contTemporalSpiderman);
    generarArchivo();
    return info;
}

void Avengers::consultaAvengers(){
    QString info = "Consulta-Resumen Avengers\n";
    info += "Total de Salvados acumulados: "+QString::number(listaIronMan.largo+listaThor.largo+listaSpiderman.largo)+"\n\n";
    info += "1- AntMan\n";
    /*
    info += "Total de salvados: "+QString::number(listaIronMan.largo)+"\n";
    info += "Descripcion de los humanos salvados:\n";
    info += listaIronMan.formatoParaConsultasTxt()+"\n\n";*/

    info += "2- Ironman\n";
    info += "Total de salvados: "+QString::number(listaIronMan.largo)+"\n";
    info += "Descripcion de los humanos salvados:\n";
    info += listaIronMan.formatoParaConsultasTxt()+"\n\n";

    info += "3- Thor\n";
    info += "Total de aniquilados: "+QString::number(listaThor.largo)+"\n";
    info += "Descripcion de los humanos salvados:\n";
    info += listaThor.formatoParaConsultasTxt()+"\n\n";

    info += "4- Spiderman\n";
    info += "Total de salvados: "+QString::number(listaSpiderman.largo)+"\n";
    info += "Descripcion de los humanos salvados:\n";
    info += listaSpiderman.formatoParaConsultasTxt()+"\n\n";



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
    QString ruta = "consultaAvengers/"+nombre+".txt";
    std::string nombreArchivo = ruta.toStdString();

    ofstream file;
    file.open(nombreArchivo);
    file << info.toStdString();
    file.close();
}
void Avengers::generarArchivoHormigas (){

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
    QString ruta = "archivosHormigas/"+nombre+".txt";
    std::string nombreArchivo = ruta.toStdString();

    ofstream file;
    file.open(nombreArchivo);
    file << avengers.rutaHormiga.toStdString();
    file.close();
}
void salvarPorRango(NodoArbol * inicio, NodoArbol * final){
    NodoHumano * tmp = inicio->humano;
    while(tmp != final->humano){
        if (!tmp->persona->vivo){
            avengers.bitacora += tmp->persona->formato("Salvado por Ant-Man por estar en el rango entre: "+QString::number(inicio->humano->persona->index)+" y "+QString::number(final->humano->persona->index));
            tmp->persona->sucesos.agregarSucesos("Salvado por Ant-Man por estar en el rango entre: "+QString::number(inicio->humano->persona->index)+" y "+QString::number(final->humano->persona->index));
            tmp->persona->vivo = true;
            avengers.bitacoraAntMan += tmp->persona->formato("Salvado por Ant-Man por estar en el rango entre: "+QString::number(inicio->humano->persona->index)+" y "+QString::number(final->humano->persona->index));
        }
        tmp = tmp->siguiente;
    }
}
void Avengers::algoritmoAntMan(int cantidad){
    avengers.rutaHormiga = "";
    arbolMundial.limpiarHormigas(arbolMundial.raiz);
    for (int i = 0; i<cantidad;i++){
        avengers.rutaHormiga += "Hormiga #"+QString::number(i)+":\n";
        arbolMundial.recorrerArbol(arbolMundial.raiz);
    }
    qDebug()<<"Hormigas ponidas";
    NodoArbol * primerMayor = arbolMundial.obtenerMayor(arbolMundial.raiz,0,0);
    NodoArbol * segundoMayor = arbolMundial.obtenerMayor(arbolMundial.raiz,0,primerMayor->FeroRama);
    qDebug()<<"Primera Persona: "<<primerMayor->FeroRama<<primerMayor->humano->persona->ID;
    qDebug()<<"Segundo Persona: "<<segundoMayor->FeroRama<<segundoMayor->humano->persona->ID;
    generarArchivoHormigas();
    salvarPorRango(primerMayor,segundoMayor);
}
