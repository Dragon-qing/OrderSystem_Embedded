#include "manager.h"
#include "ui_manager.h"

manager::manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manager)
{
    ui->setupUi(this);
    sqlstr = "select * from manager;";
    if(!sql.sql_query.exec(sqlstr)){
        QMessageBox::critical(this,"error",sql.sql_query.lastError().text());
    }else{
        int i = 0;
        while(sql.sql_query.next()){
            for(int j=0;j<5;j++){
                QString str = sql.sql_query.value(j).toString();
                if (j!=2){
                    addItemContent(i,j,str);
                }else{
                    if(str=="0"){
                        addItemContent(i,j,"Female");
                    }else{
                        addItemContent(i,j,"Male");
                    }
                }

            }
            i=i+1;
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);

        }
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()-1);
    }
}

manager::~manager()
{
    sql.close();
    delete ui;
}
void manager::addItemContent(int row, int column, QString content)

{

      QTableWidgetItem *item = new QTableWidgetItem (content);

      ui->tableWidget->setItem(row, column, item);

}
