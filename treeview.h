#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QDialog>

namespace Ui {
class TreeView;
}

class TreeView : public QDialog
{
    Q_OBJECT

public:
    explicit TreeView(QWidget *parent = nullptr);
    ~TreeView();

private:
    Ui::TreeView *ui;
};

#endif // TREEVIEW_H
