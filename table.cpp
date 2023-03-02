#include "table.h"
#include "ui_table.h"

table::table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::table)
{
    ui->setupUi(this);
    sqlstr = "select count(*) from tables where tableState=1 and tableStyle=1;";
    if(!sql.sql_query.exec(sqlstr)){
        qDebug()<<sql.sql_query.lastError()<<endl;
    }else{
        if(sql.sql_query.first()){
            QString num = sql.sql_query.value(0).toString();
            ui->free1->setText(num);
        }
    }
    sqlstr = "select count(*) from tables where tableState=1 and tableStyle=2;";
    if(!sql.sql_query.exec(sqlstr)){
        qDebug()<<sql.sql_query.lastError()<<endl;
    }else{
        if(sql.sql_query.first()){
            QString num = sql.sql_query.value(0).toString();
            ui->free2->setText(num);
        }
    }
}

table::~table()
{
    delete ui;
    sql.close();
}
void table::on_hallbtn_clicked()
{
    sqlstr = "select * from tables where tableState=1 and tableStyle=1;";
    if(!sql.sql_query.exec(sqlstr)){
        qDebug()<<"error query"<<sql.sql_query.lastError()<<endl;
    }else{
        if(sql.sql_query.first()){
            int tableId = sql.sql_query.value(0).toInt();
            sqlstr = QString("update tables set tableState=2 where tableId=%1").arg(tableId);
            sql.sql_query.exec(sqlstr);
            if(sql.sql_query.numRowsAffected()){
                QMessageBox::information(this,"message","预定成功","OK");
                QString num = QString::number(ui->free1->text().toInt()-1);
                ui->free1->setText(num);
            }
        }else{
            QMessageBox::information(this,"message","已没有空余位置","OK");
        }
    }
}
void table::on_roombtn_clicked()
{
    sqlstr = "select * from tables where tableState=1 and tableStyle=2;";
    if(!sql.sql_query.exec(sqlstr)){
        qDebug()<<"error query"<<sql.sql_query.lastError()<<endl;
    }else{
        if(sql.sql_query.first()){
            int tableId = sql.sql_query.value(0).toInt();
            sqlstr = QString("update tables set tableState=2 where tableId=%1").arg(tableId);
            sql.sql_query.exec(sqlstr);
            if(sql.sql_query.numRowsAffected()){
                QMessageBox::information(this,"message","预定成功","OK");
                QString num = QString::number(ui->free2->text().toInt()-1);
                ui->free2->setText(num);
            }
        }else{
            QMessageBox::information(this,"message","已没有空余位置","OK");
        }
    }
}
