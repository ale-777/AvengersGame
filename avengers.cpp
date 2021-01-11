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
    QString info = "Algoritmo Ironman\n";
    arbolPreOrden.init(); //reinicia la lista
    arbolMundial.preOrden(arbolMundial.raiz); //llena de nuevo la lista preorden
    info += arbolPreOrden.detonarBombas();
    generarArchivo();
    return info;
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
    ofstream file;
    file.open("archivosHormigas/hormigasNoPutas.txt");
    file << avengers.rutaHormiga.toStdString();
    file.close();
}
