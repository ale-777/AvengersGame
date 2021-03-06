#include "ventanaconsultas.h"
#include "ui_ventanaconsultas.h"
#include "Globals.h"

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

void ventanaConsultas::on_btn_consultaID_clicked()
{
    if (planeta.consultaID(ui->spin_id->value()) != NULL){
        ui->tect_info->setText(planeta.consultaID(ui->spin_id->value())->imprimirHumano());
    }
    else{
        ui->tect_info->setText("No existe el humano");
    }

}

void ventanaConsultas::on_pushButton_clicked()
{
    QString deporte = ui->comboBox_deporte->currentText();
    ui->tect_info->setText(poblacionMundial.listaPorDeporte(deporte)->imprimirLista());
}

void ventanaConsultas::on_btn_consultaAmigos_clicked()
{
    if (planeta.consultaID(ui->spin_id->value()) != NULL){
        planeta.consultaID(ui->spin_id->value())->cadenaAmigosAux();
        ui->tect_info->setText(temporal.info);
    }
    else{
        ui->tect_info->setText("No existe el humano");
    }
}

void ventanaConsultas::on_btnConsultaFam_clicked()
{
    if (planeta.consultaID(ui->spin_id->value()) != NULL){

        ui->tect_info->setText(planeta.consultaID(ui->spin_id->value())->imprimirFamilia());


    }
    else{

        ui->tect_info->setText("No existe el humano");
    }

}

void ventanaConsultas::on_btn_cantHumanos_clicked()
{
    ui->tect_info->setText(poblacionMundial.consultaCantidades());
}
