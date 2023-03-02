#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include "sqlunit.h"

namespace Ui {
class table;
}

class table : public QWidget
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = 0);
    ~table();
private slots:
    void on_hallbtn_clicked();
    void on_roombtn_clicked();
private:
    Ui::table *ui;
    SqlUnit sql;
    QString sqlstr;
};

#endif // TABLE_H
