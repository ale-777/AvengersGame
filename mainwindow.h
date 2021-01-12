#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_generarHumanos_clicked();

    void on_pushButton_clicked();

    void on_btn_consultas_clicked();

    void on_imprimirArbol_clicked();

    void on_corvusGlaive_clicked();

    void on_sumarPecados_clicked();

    void on_btn_aniquilacion_clicked();

    void on_sumarBuenasAcciones_clicked();

    void on_btn_salvacion_clicked();

    void on_btn_consultaThanos_clicked();

    void on_btn_consultaAvengers_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
