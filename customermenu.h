#ifndef CUSTOMERMENU_H
#define CUSTOMERMENU_H

#include <QWidget>
#include <QButtonGroup>
#include "table.h"
#include "history.h"
#include "xiang.h"
#include "e.h"
#include "drink.h"

namespace Ui {
class customermenu;
}

class customermenu : public QWidget
{
    Q_OBJECT

public:
    explicit customermenu(QWidget *parent = 0, int uid = 1);
    ~customermenu();

private:
    int uid;
    Ui::customermenu *ui;
    QButtonGroup btnGroup;
    table tableWnd;
    history* historyWnd;
    xiang xiangWnd;
    e eWnd;
    drink drinkWnd;
};

#endif // CUSTOMERMENU_H
