#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <parkinglot.h>
#include "worker.h"
#include <QString>
#include <QtDebug>
#include <QInputDialog>
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
    worker *x=new worker();
    x->setValue(n.toInt(),m.toInt());
    x->start();

}


void MainWindow::on_pushButton_2_clicked()
{
    QSqlDatabase database;

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("parkinglot.db");
    if (!database.open()) {
           QMessageBox::warning(0, QObject::tr("Database Error"),
                                database.lastError().text());
    }

    QSqlQuery qry(database);
    qry.prepare("select Avg(charge) from parkinglots");
    if(!qry.exec()){
        ui->textEdit_3->append("amle");
    }

    QString x= "the average count is ";
    while(qry.next()){
        x.append(qry.value(0).toString());

    }
    ui->textEdit_3->append(x);
    msgBox = new QMessageBox("title",    ///--这里是设置消息框标题
                  x,            ///--这里是设置消息框显示的内容
                  QMessageBox::Critical,              ///--这里是在消息框显示的图标
                  QMessageBox::Ok | QMessageBox::Default,    ///---这里是显示消息框上的按钮情况
                  QMessageBox::Cancel | QMessageBox::Escape,  ///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
                  0);
    msgBox->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlDatabase database;

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("parkinglot.db");
    if (!database.open()) {
           QMessageBox::warning(0, QObject::tr("Database Error"),
                                database.lastError().text());
    }

    QSqlQuery qry(database);
    qry.prepare("");
    if(!qry.exec()){
        ui->textEdit_3->append("amle");
    }

    QString x= "the average count is ";
    while(qry.next()){
        x.append(qry.value(0).toString());

    }
}
