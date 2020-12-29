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

private:
    Ui::ventanaConsultas *ui;
};

#endif // VENTANACONSULTAS_H
