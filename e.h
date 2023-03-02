#ifndef E_H
#define E_H

#include <QWidget>
#include <QPushButton>
#include "sqlunit.h"
#include <QMessageBox>
namespace Ui {
class e;
}

class e : public QWidget
{
    Q_OBJECT

public:
    explicit e(QWidget *parent = 0);
    ~e();

private slots:
    void handleClicked();
private:
    Ui::e *ui;
    SqlUnit sql;
    QString sqlstr;
    void addItemContent(int row, int column, QString content);
};

#endif // E_H
