#include "mainwindow.h"
#include "Globals.h"
#include <iomanip>
#include <cmath>
#include <windows.h>
#include <string>
#include <iostream>

#include <QApplication>



int main(int argc, char *argv[])
{
    planeta.iniciarMundo();
    planeta.agregarPoblacion(10000);
   // avengers.algoritmoAntMan(100);
    /*
    QString algo = QDir::currentPath()+"/deportes.txt";
    string algo2 = algo.toStdString();
    string comando = "java -jar sendMail.jar thanosed02@gmail.com Se_ejecuta_Midnigth!_Adjunto_bitcora C:/Users/valer/Documents/build-AvengersGame-Desktop_Qt_5_15_1_MinGW_64_bit-Debug/archivosAniquilacion/2021114_202957.txt";
    const char *c = comando.c_str();

    qDebug()<<c;

    system(c);*/

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


    /*

    qDebug()<<poblacionMundial.largo;
    qDebug()<<planeta.redondearArbol(100);
    poblacionMundial.nodosArbol(79);


    //qDebug() << arbolMundial.print2D(arbolMundial.raiz);
    qDebug() <<"aqui";
    //arbolMundial.print_tree_structure(arbolMundial.raiz,0);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    planeta.iniciarMundo();
    planeta.agregarPoblacion(10000);
    qDebug()<<poblacionMundial.largo;
    planeta.imprimirPoblacion();

    planeta.sumarPecados();
    planeta.sumarBuenasAcciones();
    planeta.imprimirPoblacion();

    return 0;*/
}

