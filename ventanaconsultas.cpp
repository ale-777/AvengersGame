#include "ventanaconsultas.h"
#include "ui_ventanaconsultas.h"
#include "Globals.h"

ventanaConsultas::ventanaConsultas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanaConsultas)
{
    ui->setupUi(this);
    ui->frameFam->setVisible(false);
}

ventanaConsultas::~ventanaConsultas()
{
    delete ui;
}

void ventanaConsultas::on_btn_consultaID_clicked()
{
    ui->frameFam->setVisible(false);
    ui->tect_info->setVisible(true);
    if (planeta.consultaID(ui->spin_id->value()) != NULL){
        ui->tect_info->setText(planeta.consultaID(ui->spin_id->value())->imprimirHumano());
    }
    else{
        ui->tect_info->setText("No existe el humano");
    }

}

void ventanaConsultas::on_pushButton_clicked()
{
    ui->frameFam->setVisible(false);
    ui->tect_info->setVisible(true);
    QString deporte = ui->comboBox_deporte->currentText();
    ui->tect_info->setText(poblacionMundial.listaPorDeporte(deporte)->imprimirLista());
}

void ventanaConsultas::on_btn_consultaAmigos_clicked()
{
    ui->frameFam->setVisible(false);
    ui->tect_info->setVisible(true);
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
        ui->tect_info->setVisible(false);
        ui->frameFam->setVisible(true);
        QString familia[] = {"N/A","N/A","N/A","N/A","N/A","N/A","N/A"};
        planeta.consultaID(ui->spin_id->value())->imprimirFamilia(familia);
        ui->lblCantHijos->setText(QString::number(planeta.consultaID(ui->spin_id->value())->hijos->largo));
        ui->lblPadre->setText(familia[0]);
        ui->lblMadre->setText(familia[1]);
        ui->lblActual->setText(familia[2]);
        ui->lblHijo1->setText(familia[3]);
        ui->lblHijo2->setText(familia[4]);
        ui->lblHijo3->setText(familia[5]);
        ui->lblHijo4->setText(familia[6]);

    }
    else{
        ui->frameFam->setVisible(false);
        ui->tect_info->setVisible(true);
        ui->tect_info->setText("No existe el humano");
    }

}
