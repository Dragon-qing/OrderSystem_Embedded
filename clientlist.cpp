#include "clientlist.h"
#include "ui_clientlist.h"

clientlist::clientlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientlist)
{
    ui->setupUi(this);
    sqlstr = "select * from clientList;";
    if(!sql.sql_query.exec(sqlstr)){
        QMessageBox::critical(this,"error",sql.sql_query.lastError().text());

    }else{
        int i =0;
        while(sql.sql_query.next()){
            for(int j=0;j<4;j++){
                QString res = sql.sql_query.value(j).toString();
                addItemContent(i,j,res);
            }
            i++;
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);

        }
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()-1);

        for (int r=0;r<i;r++ ) {
            QString foodId = ui->tableWidget->item(r,1)->text();
            sqlstr = QString("select foodName from menu where foodId=%1;").arg(foodId);
            if(!sql.sql_query.exec(sqlstr)){
                QMessageBox::critical(this,"Error",sql.sql_query.lastError().text());
            }else{
                sql.sql_query.first();
                ui->tableWidget->setItem(r,1,new QTableWidgetItem(sql.sql_query.value(0).toString()));
            }
        }

    }

}

clientlist::~clientlist()
{
    delete ui;
    sql.close();
}
void clientlist::addItemContent(int row, int column, QString content)

{

      QTableWidgetItem *item = new QTableWidgetItem (content);

      ui->tableWidget->setItem(row, column, item);

}
