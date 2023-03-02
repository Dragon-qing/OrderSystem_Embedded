#include "menu.h"
#include "ui_menu.h"



menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    sqlstr = "select * from menu;";
    if(!sql.sql_query.exec(sqlstr)){
        QMessageBox::critical(this,"error",sql.sql_query.lastError().text());

    }else{
        int i =0;
        while(sql.sql_query.next()){
            for(int j=0;j<7;j++){
                if (j!=5){
                    addItemContent(i,j,sql.sql_query.value(j).toString());
                }else{
                    if(sql.sql_query.value(j).toString()=="0"){
                         addItemContent(i,j,"Y");
                    }else{
                        addItemContent(i,j,"N");
                    }

                }
            }
            i++;
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->setRowCount(row+1);
        }
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()-1);
    }
}

menu::~menu()
{
    delete ui;
    sql.close();
}
void menu::addItemContent(int row, int column, QString content)

{

      QTableWidgetItem *item = new QTableWidgetItem (content);

      ui->tableWidget->setItem(row, column, item);

}
