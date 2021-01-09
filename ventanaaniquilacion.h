#ifndef VENTANAANIQUILACION_H
#define VENTANAANIQUILACION_H

#include <QDialog>

namespace Ui {
class ventanaAniquilacion;
}

class ventanaAniquilacion : public QDialog
{
    Q_OBJECT

public:
    explicit ventanaAniquilacion(QWidget *parent = nullptr);
    ~ventanaAniquilacion();

private slots:
    void on_btn_corvus_clicked();

    void on_btn_midnight_clicked();

    void on_btn_black_clicked();

    void on_btn_nebula_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ventanaAniquilacion *ui;
};

#endif // VENTANAANIQUILACION_H
