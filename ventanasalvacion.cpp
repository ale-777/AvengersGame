#include "ventanasalvacion.h"
#include "ui_ventanasalvacion.h"
#include "Globals.h"

ventanaSalvacion::ventanaSalvacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanaSalvacion)
{
    ui->setupUi(this);
}

ventanaSalvacion::~ventanaSalvacion()
{
    delete ui;
}

void ventanaSalvacion::on_btn_thor_clicked()
{
    int nivel = ui->nivelArbol->value();
    ui->textBrowser->setText(avengers.Thor(nivel));
}