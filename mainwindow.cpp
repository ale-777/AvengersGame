#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Globals.h"
#include "displayhumanos.h"

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
