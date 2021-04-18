#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <decompress.h>
#include "compress.h"
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


void MainWindow::on_pushButton_2_clicked()
{
    QString sourceFileName = QFileDialog::getOpenFileName(this, "open source File");
    ui->souceFileEdit->setText(sourceFileName);
}

void MainWindow::on_pushButton_clicked()
{
    QString targetFileName = QFileDialog::getOpenFileName(this, "open Target File");
    ui->targetFileEdit->setText(targetFileName);
}


void MainWindow::on_pushButton_3_clicked()
{
    if(ui->souceFileEdit->text()!=""&&ui->targetFileEdit->text()!=""&&ui->souceFileEdit_2->text()!=""&&ui->targetFileEdit_2->text()!=""&&ui->targetFileEdit_2->text()!=ui->targetFileEdit->text()&&ui->souceFileEdit->text()!=ui->souceFileEdit_2->text()){
        compress *c1 = new compress(ui->souceFileEdit->text().toStdString(),ui->targetFileEdit->text().toStdString());
        compress *c2 = new compress(ui->souceFileEdit_2->text().toStdString(),ui->targetFileEdit_2->text().toStdString());
        c1->huffmanForEnglish();
        c2->huffmanForEnglish();

    }else if(ui->souceFileEdit->text()!=""&&ui->targetFileEdit->text()!="") {
        compress *c1 = new compress(ui->souceFileEdit->text().toStdString(),ui->targetFileEdit->text().toStdString());
        c1->huffmanForEnglish();

    }
    else {
        QMessageBox *msgBox = new QMessageBox("title",    ///--这里是设置消息框标题
              "Error Input",            ///--这里是设置消息框显示的内容
              QMessageBox::Critical,              ///--这里是在消息框显示的图标
              QMessageBox::Ok | QMessageBox::Default,    ///---这里是显示消息框上的按钮情况
              QMessageBox::Cancel | QMessageBox::Escape,  ///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
              0);
        msgBox->show();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->souceFileEdit->text()!="") {
           decompress *c1 = new decompress(ui->souceFileEdit->text().toStdString());
           c1->unCompressHuffmanForEnglish();

    }
    else {
        QMessageBox *msgBox = new QMessageBox("title",    ///--这里是设置消息框标题
              "Error Input",            ///--这里是设置消息框显示的内容
              QMessageBox::Critical,              ///--这里是在消息框显示的图标
              QMessageBox::Ok | QMessageBox::Default,    ///---这里是显示消息框上的按钮情况
              QMessageBox::Cancel | QMessageBox::Escape,  ///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
              0);
        msgBox->show();
    }
}
