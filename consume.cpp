#include "consume.h"
#include "ui_consume.h"

consume::consume(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::consume)
{
    ui->setupUi(this);
    sqlstr = "select * from consume;";
    if (!sql.sql_query.exec(sqlstr)){
        QMessageBox::critical(this,"Error", sql.sql_query.lastError().text());

    }else{
        int i = 0;
        while(sql.sql_query.next()){
            for (int j =0;j<7 ;j++ ) {
                QString str = sql.sql_query.value(j).toString();
                if(j == 5){
                    if(str == "0"){
                        addItemContent(i,j,"Eating");
                    }else{

                        addItemContent(i,j,"Done");
                    }
                }else{

                    addItemContent(i,j,str);
                }
            }
            i++;
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        }
         ui->tableWidget->setRowCount(ui->tableWidget->rowCount()-1);
    }

}

consume::~consume()
{
    delete ui;
}
void consume::addItemContent(int row, int column, QString content)

{

      QTableWidgetItem *item = new QTableWidgetItem (content);

      ui->tableWidget->setItem(row, column, item);

}
