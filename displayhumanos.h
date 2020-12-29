#ifndef DISPLAYHUMANOS_H
#define DISPLAYHUMANOS_H

#include <QDialog>

namespace Ui {
class displayHumanos;
}

class displayHumanos : public QDialog
{
    Q_OBJECT

public:
    explicit displayHumanos(QWidget *parent = nullptr);
    ~displayHumanos();

private:
    Ui::displayHumanos *ui;
};

#endif // DISPLAYHUMANOS_H
