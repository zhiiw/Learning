#include "sql.h"

sql::sql()
{
    QSqlDatabase database;

    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("parkinglot.db");
    }
}
sql::~sql(){
    db.close();
}
