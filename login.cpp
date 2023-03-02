#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
    sql.close();
}

void login::on_cancel_clicked()
{
    MainWindow *home = new MainWindow();
    this->close();
    home->show();
}
void login::on_login_2_clicked()
{

    QString account = ui->account->text();
    QString password = ui->password->text();
    QString sqlstr = QString("select password, authority,userId from account where user='%1';").arg(account);

    sql.sql_query.exec(sqlstr);
    if(sql.sql_query.first())
    {
        QString pw = sql.sql_query.value(0).toString();
        int auth = sql.sql_query.value(1).toInt();
        int uid = sql.sql_query.value(2).toInt();
        if(pw == password){
            qDebug()<<"密码正确"<<endl;
            if (auth==1){
                cus = new customermenu(NULL,uid);
                cus->show();
            }else if(auth==0){
                adm = new adminmenu();
                adm->show();
            }
             this->close();
        }else{
            QMessageBox::critical(this, "error", "password error!!!", "ok");
        }
    }else{
        qDebug()<<"查询失败"<<endl;
        QMessageBox::critical(this, "error", "password error!!!", "ok");
    }
}
void login::on_adminbtn_clicked()
{
    ui->account->setText("admin");
    ui->password->setText("admin");
}
void login::on_normalbtn_clicked()
{
    ui->account->setText("test");
    ui->password->setText("test");
}
