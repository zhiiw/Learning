#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <parkinglot.h>
#include "worker.h"
#include "sql.h"
#include <QString>
#include <QtDebug>
#include <QInputDialog>
#include "producerThread.h"
#include "consumerThread.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = new sql();
    if(db->db.open()){
        cout<<"open successfully"<<endl;
    }
    db->execSql("delete from parkinglots");
    db->execSql("UPDATE judgeExist SET existence=0");


    pro1 = new produceThread();
    connect(pro1,&produceThread::addLabel,this,&MainWindow::addImage);
    connect(pro1,&produceThread::addSql,this,&MainWindow::runSql);
    connect(pro1,&produceThread::appendText,this,&MainWindow::appendTextEdit);
    connect(pro1,&produceThread::showQueueNumber,this,&MainWindow::showNumberInLabel);
    pro2 = new produceThread();
    connect(pro2,&produceThread::addLabel,this,&MainWindow::addImage);
    connect(pro2,&produceThread::addSql,this,&MainWindow::runSql);
    connect(pro2,&produceThread::appendText,this,&MainWindow::appendTextEdit);
    connect(pro2,&produceThread::showQueueNumber,this,&MainWindow::showNumberInLabel);
    con = new consumerThread();
    connect(con,&consumerThread::deleteLabel,this,&MainWindow::deleteImage);
    connect(con,&consumerThread::addSql,this,&MainWindow::runSql);
    connect(con,&consumerThread::appendText,this,&MainWindow::appendTextEdit);
}


MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::showNumberInLabel(int i ){
    ui->label_24->clear();
    QString x = "the carqueue have ";
    x.append(QString::fromStdString(to_string(i)));
    ui->label_24->setText(x);
}
void MainWindow::addImage(int i){
    int c=i+4;
    string x="label_";
    x+=to_string(c);
    QLabel* bl = this->findChild<QLabel*>(QString::fromStdString(x));
    QPixmap myPix(":/new/images/car.jpg");
    myPix.scaled(bl->size(),Qt::KeepAspectRatio);
    bl->setScaledContents(true);
    bl->setPixmap(myPix);

}
void MainWindow::deleteImage(int i){
    int c=i+4;
    string x="label_";
    x+=to_string(c);
    QLabel* bl = this->findChild<QLabel*>(QString::fromStdString(x));
    bl->clear();
}
void MainWindow::runSql(QString str){
    db->execSql(str);
}
void MainWindow::appendTextEdit(QString str){
    ui->textEdit_3->append(str);
}
void MainWindow::on_pushButton_clicked()
{
    QString n = ui->textEdit->toPlainText();
    QString m = ui->textEdit_2->toPlainText();
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
    pl =new parkinglot<int> (n.toInt(),m.toInt());
    pro1->setParkinglot(pl);
    pro2->setParkinglot(pl);
    pro1->setName(" 1");
    pro2->setName(" 2");

    con->setParkinglot(pl);
    pro1->start();

    con->start();
    sleep(2);
    pro2->start();

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
    QPixmap myPix(":/new/images/car.jpg");
    myPix.scaled(ui->label_4->size(),Qt::KeepAspectRatio);
    ui->label_9->setScaledContents(true);
    ui->label_9->setPixmap(myPix);
}
