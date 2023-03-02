#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "sqlunit.h"
#include <QMessageBox>

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

private:
    Ui::menu *ui;
    SqlUnit sql;
    QString sqlstr;
    void addItemContent(int row, int column, QString content);
};

#endif // MENU_H
