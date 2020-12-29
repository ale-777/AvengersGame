#include "ventanaconsultas.h"
#include "ui_ventanaconsultas.h"

ventanaConsultas::ventanaConsultas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanaConsultas)
{
    ui->setupUi(this);
}

ventanaConsultas::~ventanaConsultas()
{
    delete ui;
}
