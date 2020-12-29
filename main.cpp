#include "mainwindow.h"
#include "Globals.h"

#include <QApplication>
//hi :)
//commit prueba
int main(int argc, char *argv[])
{

    planeta.iniciarMundo();
   // planeta.agregarPoblacion(10000);
    qDebug()<<poblacionMundial.largo;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    /*
    planeta.iniciarMundo();
    planeta.agregarPoblacion(10000);
    qDebug()<<poblacionMundial.largo;
    planeta.imprimirPoblacion();

    planeta.sumarPecados();
    planeta.sumarBuenasAcciones();
    planeta.imprimirPoblacion();

    return 0;*/
}
