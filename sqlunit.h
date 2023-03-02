#ifndef SQLUNIT_H
#define SQLUNIT_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
class SqlUnit
{
public:
    SqlUnit();
    ~SqlUnit();
    void close();
    QSqlQuery sql_query;
private:
    QSqlDatabase db;
};

#endif // SQLUNIT_H
