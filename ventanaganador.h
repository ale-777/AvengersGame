#ifndef VENTANAGANADOR_H
#define VENTANAGANADOR_H

#include <QDialog>

namespace Ui {
class ventanaGanador;
}

class ventanaGanador : public QDialog
{
    Q_OBJECT

public:
    explicit ventanaGanador(QWidget *parent = nullptr);
    ~ventanaGanador();

private:
    Ui::ventanaGanador *ui;
};

#endif // VENTANAGANADOR_H
