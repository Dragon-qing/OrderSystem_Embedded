#include "drink.h"
#include "ui_drink.h"

drink::drink(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::drink)
{
    int i = 0;
    ui->setupUi(this);
    QPushButton *btn = new QPushButton("添加");
    btn->setStyleSheet("QPushButton{margin:3px};");
    ui->tableWidget->setCellWidget(0,3,btn);
    connect(btn,&QPushButton::clicked,this,&drink::handleClicked);
    sqlstr = "select * from menu where foodstyle in (5,6,7,8);";
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

drink::~drink()
{
    delete ui;
}
void drink::handleClicked()
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
void drink::addItemContent(int row, int column, QString content)

{

      QTableWidgetItem *item = new QTableWidgetItem (content);

      ui->tableWidget->setItem(row, column, item);

}
