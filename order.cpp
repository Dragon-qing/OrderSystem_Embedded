#include "order.h"
#include "ui_order.h"

order::order(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::order)
{
    ui->setupUi(this);
    int num=0;
    sqlstr = "select * from 'order';";
    if(!sql.sql_query.exec(sqlstr)){
        QMessageBox::critical(this,"error",sql.sql_query.lastError().text());
    }else{
        if(sql.sql_query.last()){
            num = sql.sql_query.at()+1;
        }
        sql.sql_query.first();
        sql.sql_query.previous();
        ui->tableWidget->setRowCount(num);
    }
    int i =0;
    while(sql.sql_query.next()){
        for(int j=0;j<=5;j++){
            addItemContent(i,j,sql.sql_query.value(j).toString());
        }
        i = i+1;
    }


}

order::~order()
{
    delete ui;
    sql.close();
}
void order::addItemContent(int row, int column, QString content)

{

      QTableWidgetItem *item = new QTableWidgetItem (content);

      ui->tableWidget->setItem(row, column, item);

}
