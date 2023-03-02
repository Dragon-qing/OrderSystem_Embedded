#ifndef CLIENTLIST_H
#define CLIENTLIST_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlResult>
#include "sqlunit.h"
namespace Ui {
class clientlist;
}

class clientlist : public QWidget
{
    Q_OBJECT

public:
    explicit clientlist(QWidget *parent = 0);
    ~clientlist();

private:
    Ui::clientlist *ui;
    SqlUnit sql;
    QString sqlstr;
    void addItemContent(int row, int column, QString content);
};

#endif // CLIENTLIST_H
