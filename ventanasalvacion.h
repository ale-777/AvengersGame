#ifndef VENTANASALVACION_H
#define VENTANASALVACION_H

#include <QDialog>

namespace Ui {
class ventanaSalvacion;
}

class ventanaSalvacion : public QDialog
{
    Q_OBJECT

public:
    explicit ventanaSalvacion(QWidget *parent = nullptr);
    ~ventanaSalvacion();

private slots:
    void on_btn_thor_clicked();

    void on_btn_ironMan_clicked();

private:
    Ui::ventanaSalvacion *ui;
};

#endif // VENTANASALVACION_H
