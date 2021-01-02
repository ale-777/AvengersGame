#ifndef VERARBOL_H
#define VERARBOL_H

#include <QDialog>

namespace Ui {
class verArbol;
}

class verArbol : public QDialog
{
    Q_OBJECT

public:
    explicit verArbol(QWidget *parent = nullptr);
    ~verArbol();

private:
    Ui::verArbol *ui;
};

#endif // VERARBOL_H
