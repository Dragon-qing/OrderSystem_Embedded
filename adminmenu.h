#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QWidget>
#include <QButtonGroup>
#include "table.h"
#include "order.h"
#include "menu.h"
#include "manager.h"
#include "clientlist.h"
#include "consume.h"

namespace Ui {
class adminmenu;
}

class adminmenu : public QWidget
{
    Q_OBJECT

public:
    explicit adminmenu(QWidget *parent = 0);
    ~adminmenu();

private:
    Ui::adminmenu *ui;

    QButtonGroup btnGroup;
    table tableWnd;
    order orderWnd;
    menu menuWnd;
    manager managerWnd;
    clientlist clientlistWnd;
    consume consumeWnd;
};

#endif // MENU_H
