#include "e.h"
#include "ui_e.h"

e::e(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::e)
{
    int i = 0;
    ui->setupUi(this);
    QPushButton *btn = new QPushButton("添加");
    btn->setStyleSheet("QPushButton{margin:3px};");
    ui->tableWidget->setCellWidget(0,3,btn);
    connect(btn,&QPushButton::clicked,this,&e::handleClicked);
    sqlstr = "select * from menu where foodstyle = 4";
    if(!sql.sql_query.exec(sqlstr)){
        QMessageBox::critical(this,"Error",sql.sql_query.lastError().text());
    }else{
        while (sql.sql_query.next()) {

            if(sql.sql_query.value(4).toString() == "1"){
                QString foodName = sql.sql_query.value(1).toString();
                QString foodPrice = sql.sql_query.value(3).toString();
                addItemContent(i,0,foodName);
                addItemContent(i,1,foodPrice);
                addItemContent(i,2,"0");
                i++;
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            }
        }
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()-1);
    }
}

e::~e()
{
    sql.close();
    delete ui;
}
void e::handleClicked()
{
    int rows = ui->tableWidget->rowCount();
    int priceIndx = 1;
    int countIndx = 2;
    int sum = 0;
    for (int i = 0;i<rows ;i++ ) {
        int p = ui->tableWidget->item(i,priceIndx)->text().toInt();
        int c = ui->tableWidget->item(i,countIndx)->text().toInt();
        sum+=p*c;
    }
    QMessageBox::information(this,"Tips",QString("Total: %1￥").arg(sum));
}
void e::addItemContent(int row, int column, QString content)

{

      QTableWidgetItem *item = new QTableWidgetItem (content);

      ui->tableWidget->setItem(row, column, item);

}
