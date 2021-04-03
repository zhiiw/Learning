#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <parkinglot.h>
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    QString n = ui->textEdit->toPlainText();
    QString m = ui->textEdit->toPlainText();
    if(n.toInt()<=0||m.toInt()<=0){
    msgBox = new QMessageBox("title",    ///--这里是设置消息框标题
                  "ERROR INPUT",            ///--这里是设置消息框显示的内容
                  QMessageBox::Critical,              ///--这里是在消息框显示的图标
                  QMessageBox::Ok | QMessageBox::Default,    ///---这里是显示消息框上的按钮情况
                  QMessageBox::Cancel | QMessageBox::Escape,  ///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
                  0);
          msgBox->show();
          return;
    }
    parkinglot<int> pl(n.toInt(),m.toInt());
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("parkinglot.db");
    if( !db.open() )
    {
      qFatal( "Failed to connect." );
      cout<<"connected failure."<<endl;
    }
    QSqlQuery qry;
    qry.prepare( "CREATE TABLE IF NOT EXISTS names (id INTEGER UNIQUE PRIMARY KEY ,enterTime DOUBLE, leaveTime DOUBLE,plate TEXT,charge DOUBLE) " );
    if( !qry.exec() ){
       qDebug() << qry.lastError();
       cout<<"connected failure."<<endl;
    }
     else{
       qDebug() << "Table created!";
       cout<<"Table created"<<endl;

    }
    qry.prepare( "INSERT INTO names (id, enterTime, leaveTime,plate) VALUES (2, 2, 3,'rer')" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Inserted!" );
    qry.prepare( "SELECT * FROM names" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
    {
        qDebug( "Selected!" );
    }

    pl.startThreading();


}
void MainWindow::on_pushButton_2_clicked()
{

}
