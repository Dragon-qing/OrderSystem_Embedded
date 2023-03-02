#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "sqlunit.h"
#include <QDebug>

namespace Ui {
class history;
}

class history : public QWidget
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = 0, int uid=1);
    ~history();

private slots:
    void handleClicked();
private:
    int uid;
    Ui::history *ui;
    SqlUnit sql;
    QString sqlstr;
    void addItemContent(int row, int column, QString content);
};

#endif // HISTORY_H
