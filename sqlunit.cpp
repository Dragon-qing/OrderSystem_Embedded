#include "sqlunit.h"

SqlUnit::SqlUnit()
{
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("./OrderSystem.db");
    }

    if(db.open()){
//        qDebug()<<"success connect to database."<<endl;
        sql_query = QSqlQuery(db);

    }else{
        qDebug()<<"fail to connect!!!"<<db.lastError()<<endl;
    }
}
SqlUnit::~SqlUnit()
{

}
void SqlUnit::close()
{
    db.close();
}
