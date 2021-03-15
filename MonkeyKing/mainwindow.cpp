#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "CirrcularLinkedList.h"

#include <QMainWindow>
#include <QButtonGroup>
#include <QObjectUserData>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
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
    QString input1 = ui->textEdit->toPlainText();
    QString input2 = ui->plainTextEdit->toPlainText();
    int in1= input1.toInt();
    int in2= input2.toInt();
    QMessageBox *msgBox;
    if(in1<=0||in2<=0||in1<in2){
       msgBox = new QMessageBox("title",    ///--这里是设置消息框标题
               "Please input correct number ",            ///--这里是设置消息框显示的内容
               QMessageBox::Critical,              ///--这里是在消息框显示的图标
               QMessageBox::Ok | QMessageBox::Default,    ///---这里是显示消息框上的按钮情况
               QMessageBox::Cancel | QMessageBox::Escape,  ///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
               0);
       msgBox->show();
    }else{
       CirrcularLinkedList<int>* cl= new CirrcularLinkedList<int>();
       cl->create(in1);
       cl->Delete(in2);

       int length= cl->getValue();

       std::string len =std::to_string(length);
       QString q_str = QString::fromStdString(len);
       msgBox = new QMessageBox("title",    ///--这里是设置消息框标题
               q_str,            ///--这里是设置消息框显示的内容
               QMessageBox::Critical,              ///--这里是在消息框显示的图标
               QMessageBox::Ok | QMessageBox::Default,    ///---这里是显示消息框上的按钮情况
               QMessageBox::Cancel | QMessageBox::Escape,  ///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
               0);
       msgBox->show();

       QImage image(QString(":/../../Desktop/ddlkgkclpv.jpeg"));
           ui->label->setPixmap(QPixmap::fromImage(image));
           ui->label->resize(image.width(),image.height());
    }
}
