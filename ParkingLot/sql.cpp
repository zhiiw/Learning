#include "sql.h"

sql::sql()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("parkinglot.db");

}
sql::~sql(){
    db.close();
}
