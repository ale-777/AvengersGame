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

void ventanaAniquilacion::on_btn_midnight_clicked()
{
    ui->textBrowser->setText(aniquiladores.Midnight());
}

void ventanaAniquilacion::on_btn_black_clicked()
{
    int cantidad = ui->cantDeporteXSemana->value();


    QString deporte = ui->comboBox->currentText();

    ui->textBrowser->setText(aniquiladores.Black(cantidad, deporte));
}

void ventanaAniquilacion::on_btn_nebula_clicked()
{
    int id = ui->spinBox->value();
    ui->textBrowser->setText(aniquiladores.Nebula(id));


}
