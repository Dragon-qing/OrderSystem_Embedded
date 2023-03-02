#ifndef ORDER_H
#define ORDER_H

#include <QWidget>
#include <QMessageBox>
#include "sqlunit.h"

namespace Ui {
class order;
}

class order : public QWidget
{
    Q_OBJECT

public:
    explicit order(QWidget *parent = 0);
    ~order();

private:
    Ui::order *ui;
    SqlUnit sql;
    QString sqlstr;
    void addItemContent(int row, int column, QString content);
};

#endif // ORDER_H
