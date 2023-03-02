#include "history.h"
#include "ui_history.h"

history::history(QWidget *parent, int uid) :
    QWidget(parent),
    ui(new Ui::history)
{
    this->uid = uid;
    int i = 0;
    QString user="";
    ui->setupUi(this);
    QPushButton *btn = new QPushButton("结账");
    btn->setStyleSheet("QPushButton{margin:3px};");
    ui->tableWidget->setCellWidget(0,4,btn);
    connect(btn,SIGNAL(clicked()),this,SLOT(handleClicked()));
    sqlstr = QString("select user from account where userId = %1;").arg(uid);
    if(!sql.sql_query.exec(sqlstr)){
       QMessageBox::critical(this,"ERROR",sql.sql_query.lastError().text());
    }else{
        if(sql.sql_query.first()){

            user = sql.sql_query.value(0).toString();
        }
    }
    sqlstr = QString("select * from consume where uid=%1;").arg(uid);
    if(!sql.sql_query.exec(sqlstr)){
        QMessageBox::critical(this,"ERROR",sql.sql_query.lastError().text());
    }else{
        while(sql.sql_query.next()){
            QString tableId = sql.sql_query.value(1).toString();
            QString money = sql.sql_query.value(6).toString();
            QString state = sql.sql_query.value(5).toString();
            addItemContent(i,0,tableId);
            addItemContent(i,1,user);
            addItemContent(i,2,money);
            if(state == "0"){

                addItemContent(i,3,"need to pay");
            }else{
                addItemContent(i,3,"Done");
            }
            i++;
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        }
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()-1);
    }
}

history::~history()
{
    sql.close();
    delete ui;
}
void history::addItemContent(int row, int column, QString content)

{

      QTableWidgetItem *item = new QTableWidgetItem (content);

      ui->tableWidget->setItem(row, column, item);

}
void history::handleClicked()
{
    int sum = 0;
    sqlstr = QString("select consumeMoney from consume where uid=%1 and consumeState=0;").arg(this->uid);
    if(!sql.sql_query.exec(sqlstr)){
        QMessageBox::critical(this,"ERROR",sql.sql_query.lastError().text());
    }else{
        while(sql.sql_query.next()){
            sum+=sql.sql_query.value(0).toInt();
        }
        QMessageBox::information(this,"Tips",QString("You should pay %1￥").arg(sum));
    }
}
