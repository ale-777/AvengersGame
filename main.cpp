#include "mainwindow.h"
#include "Globals.h"

#include <QApplication>
//hi :)
//commit prueba
int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/

    planeta.iniciarMundo();

    /*
    for (int i=0; i<100; i++){
        qDebug() << planeta.paises[i];
    }
    Humano primer = Humano();
    primer.imprimirHumano();*/
    planeta.agregarPoblacion(20);
    planeta.imprimirPoblacion();
    planeta.sumarPecados();
    planeta.sumarBuenasAcciones();
    planeta.imprimirPoblacion();






    return 0;
}
