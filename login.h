#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <mainwindow.h>
#include <QDebug>
#include <QMessageBox>
#include "sqlunit.h"
#include "customermenu.h"
#include "adminmenu.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_cancel_clicked();
    void on_login_2_clicked();
    void on_adminbtn_clicked();
    void on_normalbtn_clicked();


private:
    Ui::login *ui;
    SqlUnit sql;
    customermenu * cus;
    adminmenu* adm;
};

#endif // LOGIN_H
