#ifndef CONSUME_H
#define CONSUME_H

#include <QWidget>
#include <QMessageBox>
#include "sqlunit.h"

namespace Ui {
class consume;
}

class consume : public QWidget
{
    Q_OBJECT

public:
    explicit consume(QWidget *parent = 0);
    ~consume();

private:
    Ui::consume *ui;
    SqlUnit sql;
    QString sqlstr;
    void addItemContent(int row, int column, QString content);

};

#endif // CONSUME_H
