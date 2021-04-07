#ifndef SQL_H
#define SQL_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <iostream>
#include <QString>
using namespace std;
class sql{
public:
    QSqlDatabase db;

    sql();
    ~sql();
    bool execSql(QString str){
        QSqlQuery qry;
        qry.prepare(str);
        if(!qry.exec()){
            cout<<"the query have mistakes."<<endl;
            return false;
        }
        return true;
    }
};

#endif // SQL_H
