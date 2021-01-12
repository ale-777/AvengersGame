#include "ventanaganador.h"
#include "ui_ventanaganador.h"
#include "Globals.h"

ventanaGanador::ventanaGanador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanaGanador)
{
    ui->setupUi(this);
    ui->lbl_ebony->setText(QString::number(listaEbonyMaw.largo));
    ui->lbl_corvus->setText(QString::number(listaCorvus.largo));
    ui->lbl_midnight->setText(QString::number(listaMidnight.largo));
    ui->lbl_nebula->setText(QString::number(listaNebula.largo));
    ui->lbl_black->setText(QString::number(listaBlack.largo));
    ui->lbl_thanos->setText(QString::number(listaThanos.largo));;
    int totalAniquiladores = listaCorvus.largo+listaMidnight.largo+listaNebula.largo+listaBlack.largo+listaThanos.largo+listaEbonyMaw.largo;
    ui->lbl_totalAniquiladores->setText(QString::number(totalAniquiladores));

    ui->lbl_antman->setText(QString::number(listaAntMan.largo));
    ui->lbl_ironman->setText(QString::number(listaIronMan.largo));
    ui->lbl_thor->setText(QString::number(listaThor.largo));
    ui->lbl_spiderman->setText(QString::number(listaSpiderman.largo));
    int totalAvengers = listaIronMan.largo+listaThor.largo+listaSpiderman.largo+listaAntMan.largo;
    ui->lbl_totalAvengers->setText(QString::number(totalAvengers));

    ui->bandoGanador->setText(planeta.ganador(totalAniquiladores,totalAvengers));
}

ventanaGanador::~ventanaGanador()
{
    delete ui;
}
