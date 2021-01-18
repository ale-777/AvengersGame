#include "Globals.h"
QString Avengers::generarArchivoPJ (QString info){
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
    file << info.toStdString();
    file.close();

    return "/"+ruta;
}


void generarArchivoAntman (QString info){
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
    QString ruta = "posiblesSalvadosAntman/"+nombre+".txt";
    std::string nombreArchivo = ruta.toStdString();

    ofstream file;
    file.open(nombreArchivo);
    file << info.toStdString();
    file.close();
}

QString Avengers::generarArchivo (){

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

    return "/"+ruta;
}

//THOR
QString Avengers::Thor(int nivel){
    avengers.bitacoraThor = "";
    contTemporalThor = 0;
    QString info = "Algoritmo Thor\n";
    info += "Se selecciona el nivel "+QString::number(nivel)+"\n";
    nivelXArbol.init();
    arbolMundial.returnNivel(arbolMundial.raiz, nivel);
    if (nivelXArbol.largo > 0){
        info += "----------------------------------------------------------------------------------------\nLos humanos en este nivel son: \n\n";
        info += nivelXArbol.imprimirNodos();
        info += "----------------------------------------------------------------------------------------\n";
        info += nivelXArbol.salvarAmigosDeFamilia(nivel);


    }
    else{
        info += "El nivel no existe\n";

    }
    info+="El total de Salvados fue: "+QString::number(contTemporalThor);
    QString archivo = generarArchivoPJ(avengers.bitacoraThor);
    enviarCorreoAvengers("Thor_envia_su_reporte ",  archivo);

    return info;

}

//IRON MAN
QString Avengers::IronMan (){
    avengers.bitacoraIronman = "";
    contTemporalIronMan = 0;
    infoTemporalIronMan = "";
    QString info = "Algoritmo Ironman\n";
    arbolPreOrden.init(); //reinicia la lista
    arbolMundial.preOrden(arbolMundial.raiz); //llena de nuevo la lista preorden
    info += arbolPreOrden.detonarBombas();
    info += "Cant de salvados: "+QString::number(avengers.contTemporalIronMan)+"\n";
    QString archivo = generarArchivoPJ(avengers.bitacoraIronman);
    enviarCorreoAvengers("Ironman_envia_su_reporte ",  archivo);

    return info;
}


//SPIDERMAN****************************************************************
QString Avengers::Spiderman(){
    avengers.bitacoraSpiderman = "";
    contTemporalSpiderman = 0;
    arbolAListaParaSpiderman.init();
    QString info = "Algoritmo Spiderman\n";

    arbolMundial.preOrdenSpiderman(arbolMundial.raiz);

    ListaHumano * telarana = arbolAListaParaSpiderman.colocarTelarana();
    info += telarana->recorrerTelarana();
    info += "Salvados: "+QString::number(avengers.contTemporalSpiderman);
    QString archivo = generarArchivoPJ(avengers.bitacoraSpiderman);
    enviarCorreoAvengers("Spiderman_envia_su_reporte ",  archivo);

    return info;
}

void Avengers::consultaAvengers(){
    QString info = "Consulta-Resumen Avengers\n";
    info += "Total de Salvados acumulados: "+QString::number(listaIronMan.largo+listaThor.largo+listaSpiderman.largo)+"\n\n";
    info += "1- AntMan\n";
    info += "Total de salvados: "+QString::number(listaAntMan.largo)+"\n";
    info += "Descripcion de los humanos salvados:\n";
    info += listaAntMan.formatoParaConsultasTxt()+"\n\n";

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
QString infoAuxAntman (NodoArbol * inicio, NodoArbol * final){
    QString info = "\nPersonas en el rango:\n";
    NodoHumano * tmp = inicio->humano;
    while(tmp != final->humano){
        info += tmp->persona->nombre +"\t"+tmp->persona->apellido+"\t"+"ID"+QString::number(tmp->persona->ID)+"\tIndex "+QString::number(tmp->persona->index)+"\tVivo: "+QString::number(tmp->persona->vivo)+"\n";
        tmp = tmp->siguiente;
    }
    return info+"\n";
}

QString salvarPorRango(NodoArbol * inicio, NodoArbol * final){
    QString info;
    generarArchivoAntman(infoAuxAntman (inicio, final));
    NodoHumano * tmp = inicio->humano;
    while(tmp != final->humano){
        if (!tmp->persona->vivo){
            avengers.bitacora += tmp->persona->formato("Salvado por Ant-Man por estar en el rango entre: "+QString::number(inicio->humano->persona->index)+" y "+QString::number(final->humano->persona->index));
            tmp->persona->sucesos.agregarSucesos("Salvado por Ant-Man por estar en el rango entre: "+QString::number(inicio->humano->persona->index)+" y "+QString::number(final->humano->persona->index));
            tmp->persona->vivo = true;
            tmp->persona->aniquilado = false;
            tmp->persona->salvado = true;
            avengers.contTemporalAntman++;
            listaAntMan.agregarHumano(tmp->persona);
            avengers.bitacoraAntMan += tmp->persona->formato("Salvado por Ant-Man por estar en el rango entre: "+QString::number(inicio->humano->persona->index)+" y "+QString::number(final->humano->persona->index));
            info += tmp->persona->nombre +" "+tmp->persona->apellido+"\t"+QString::number(tmp->persona->ID)+"\nSalvado por Ant-Man por tener indice: "+QString::number(tmp->persona->index)+"\n\n";
        }
        tmp = tmp->siguiente;
    }
    return info;
}



QString Avengers::algoritmoAntMan(int cantidad){
    avengers.bitacoraAntMan = "";
    contTemporalAntman = 0;
    QString info = "Algoritmo Ant-Man: \n";
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
    info += "Salvados desde: "+QString::number(primerMayor->humano->persona->index)+" Por feromonas: "+QString::number(primerMayor->FeroRama)+"\thasta "+QString::number(segundoMayor->humano->persona->index)+" Por feromonas: "+QString::number(segundoMayor->FeroRama)+"\n";
    generarArchivoHormigas();
    info += salvarPorRango(primerMayor,segundoMayor);
    info += "\n\nCantidad de Salvados: "+QString::number(contTemporalAntman);
    QString archivo = generarArchivoPJ(avengers.bitacoraAntMan);
    enviarCorreoAvengers("Antman_envia_su_reporte ",  archivo);

    return info;
}

void Avengers::enviarCorreoAvengers(string asunto, QString archivo){
    QString algo = QDir::currentPath()+archivo;
    string algo2 = algo.toStdString();
    string comando = "java -jar sendMail.jar thanosed02@gmail.com "+asunto+algo2;
    const char *c = comando.c_str();

    qDebug()<<c;

    system(c);
}
