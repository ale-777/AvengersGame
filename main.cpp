#include "mainwindow.h"
#include "Globals.h"
#include <iomanip>
#include <cmath>

#include <QApplication>


int main(int argc, char *argv[])
{
    planeta.iniciarMundo();
    planeta.agregarPoblacion(10000);
   // avengers.algoritmoAntMan(100);


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

