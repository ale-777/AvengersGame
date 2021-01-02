#include "verarbol.h"
#include "ui_verarbol.h"
#include "Globals.h"

verArbol::verArbol(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verArbol)
{
    ui->setupUi(this);
    ui->textBrowser->setText(arbolMundial.print2D(arbolMundial.raiz));
}

verArbol::~verArbol()
{
    delete ui;
}

