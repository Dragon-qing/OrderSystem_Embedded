#ifndef XIANG_H
#define XIANG_H

#include <QWidget>
#include <QPushButton>
#include "sqlunit.h"
#include <QMessageBox>

namespace Ui {
class xiang;
}

class xiang : public QWidget
{
    Q_OBJECT

public:
    explicit xiang(QWidget *parent = 0);
    ~xiang();

private slots:
    void handleClicked();

private:
    Ui::xiang *ui;
    SqlUnit sql;
    QString sqlstr;
    void addItemContent(int row, int column, QString content);
};

#endif // XIANG_H
