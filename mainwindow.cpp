#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Globals.h"
#include "displayhumanos.h"
#include "ventanaconsultas.h"
#include "verarbol.h"
#include "ventanaaniquilacion.h"
#include "ventanasalvacion.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_generarHumanos_clicked()
{
    planeta.agregarPoblacion(ui->numeroHumanos->value());
}

void MainWindow::on_pushButton_clicked()
{
    displayHumanos *ventana = new displayHumanos();
    ventana->show();
}

void MainWindow::on_btn_consultas_clicked()
{
    ventanaConsultas *ventana = new ventanaConsultas();
    ventana->show();
}

void MainWindow::on_imprimirArbol_clicked()
{
    verArbol *ventana = new verArbol;
    ventana->show();

}

void MainWindow::on_corvusGlaive_clicked()
{
    //Corvus();
}

void MainWindow::on_sumarPecados_clicked()
{
    planeta.sumarPecados();
}

void MainWindow::on_btn_aniquilacion_clicked()
{
    ventanaAniquilacion *ventana = new ventanaAniquilacion();
    ventana->show();
}

void MainWindow::on_sumarBuenasAcciones_clicked()
{
    planeta.sumarBuenasAcciones();
}

void MainWindow::on_btn_salvacion_clicked()
{
    ventanaSalvacion *ventana = new ventanaSalvacion();
    ventana->show();
}

void MainWindow::on_btn_consultaThanos_clicked()
{
    aniquiladores.consultaThanos();
}

void MainWindow::on_btn_consultaAvengers_clicked()
{
    avengers.consultaAvengers();
}
