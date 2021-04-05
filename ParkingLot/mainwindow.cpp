#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <parkinglot.h>
#include "worker.h"
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


}
