#include "displayhumanos.h"
#include "ui_displayhumanos.h"
#include "globals.h"

displayHumanos::displayHumanos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayHumanos)
{
    ui->setupUi(this);
    ui->textBrowser->setText(planeta.imprimirPoblacion());
}

displayHumanos::~displayHumanos()
{
    delete ui;
}

