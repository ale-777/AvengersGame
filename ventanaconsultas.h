#ifndef VENTANACONSULTAS_H
#define VENTANACONSULTAS_H

#include <QDialog>

namespace Ui {
class ventanaConsultas;
}

class ventanaConsultas : public QDialog
{
    Q_OBJECT

public:
    explicit ventanaConsultas(QWidget *parent = nullptr);
    ~ventanaConsultas();

private slots:
    void on_btn_consultaID_clicked();

private:
    Ui::ventanaConsultas *ui;
};

#endif // VENTANACONSULTAS_H
