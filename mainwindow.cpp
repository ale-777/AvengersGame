#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Globals.h"

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
    planeta.imprimirPoblacion();
}
