#include "ventanaaniquilacion.h"
#include "ui_ventanaaniquilacion.h"
#include "Globals.h"

ventanaAniquilacion::ventanaAniquilacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanaAniquilacion)
{
    ui->setupUi(this);
}

ventanaAniquilacion::~ventanaAniquilacion()
{
    delete ui;
}

void ventanaAniquilacion::on_btn_corvus_clicked()
{

    ui->textBrowser->setText(aniquiladores.Corvus());
}
