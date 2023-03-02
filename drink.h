#ifndef DRINK_H
#define DRINK_H

#include <QWidget>
#include <QPushButton>
#include "sqlunit.h"
#include <QMessageBox>

namespace Ui {
class drink;
}

class drink : public QWidget
{
    Q_OBJECT

public:
    explicit drink(QWidget *parent = 0);
    ~drink();

private slots:
    void handleClicked();

private:
    Ui::drink *ui;
    SqlUnit sql;
    QString sqlstr;
    void addItemContent(int row, int column, QString content);
};

#endif // DRINK_H
