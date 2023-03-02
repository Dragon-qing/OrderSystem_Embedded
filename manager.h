#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>
#include <QMessageBox>
#include "sqlunit.h"

namespace Ui {
class manager;
}

class manager : public QWidget
{
    Q_OBJECT

public:
    explicit manager(QWidget *parent = 0);
    ~manager();

private:
    Ui::manager *ui;
    SqlUnit sql;
    QString sqlstr;
    void addItemContent(int row, int column, QString content);
};

#endif // MANAGER_H
