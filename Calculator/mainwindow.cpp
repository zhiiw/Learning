#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stack.h"
#include <iostream>
#include "calculate.h"
using namespace std;
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


void MainWindow::on_equalButton_clicked()
{

    std::cout<<1<<endl;
    ui->textEdit->insertPlainText("wsngg");
}

void MainWindow::on_oneButton_clicked()
{
    s.vals.push(1.0);
    QString x = ui->textEdit->toPlainText();
    x.append("1");
    ui->textEdit->setText(x);
}

void MainWindow::on_twoButton_clicked()
{
    s.vals.push(2.0);
    QString x = ui->textEdit->toPlainText();
    x.append("2");
    ui->textEdit->setText(x);
}

void MainWindow::on_threeButton_clicked()
{
    s.vals.push(3.0);
    QString x = ui->textEdit->toPlainText();
    x.append("3");
    ui->textEdit->setText(x);
}

void MainWindow::on_fourButton_2_clicked()
{
    s.vals.push(4.0);
    QString x = ui->textEdit->toPlainText();
    x.append("4");
    ui->textEdit->setText(x);
}

void MainWindow::on_fourButton_clicked()
{
    s.vals.push(5.0);
    QString x = ui->textEdit->toPlainText();
    x.append("5");
    ui->textEdit->setText(x);
}

void MainWindow::on_sixButton_clicked()
{
    s.vals.push(6.0);

    QString x = ui->textEdit->toPlainText();
    x.append("6");
    ui->textEdit->setText(x);
}

void MainWindow::on_sevenButton_clicked()
{
    s.vals.push(7.0);
    QString x = ui->textEdit->toPlainText();
    x.append("7");
    ui->textEdit->setText(x);
}

void MainWindow::on_eightButton_clicked()
{
    s.vals.push(8.0);
    QString x = ui->textEdit->toPlainText();
    x.append("8");
    ui->textEdit->setText(x);}

void MainWindow::on_nineButton_clicked()
{
    s.vals.push(9.0);
    QString x = ui->textEdit->toPlainText();
    x.append("9");
    ui->textEdit->setText(x);
}

void MainWindow::on_plusButton_clicked()
{
    s.ops.push("+");
    std::cout<<s.ops.top()<<endl;

    QString x = ui->textEdit->toPlainText();
    x.append("+");
    ui->textEdit->setText(x);}

void MainWindow::on_acButton_clicked()
{
    s.ops.deleteAll();
    s.vals.deleteAll();
    ui->textEdit->clear();
}

void MainWindow::on_subButton_clicked()
{
    s.ops.push("-");
    QString x = ui->textEdit->toPlainText();
    x.append("-");
    ui->textEdit->setText(x);}

void MainWindow::on_leftButton_clicked()
{
    s.ops.push("(");
    std::cout<<s.ops.top()<<endl;

    QString x = ui->textEdit->toPlainText();
    x.append("(");
    ui->textEdit->setText(x);}

void MainWindow::on_rightButton_clicked()
{

    string op =s.ops.top();

    s.ops.pop();

    double val  =s.vals.top();
    s.vals.pop();
    std::cout<<val<<endl;

    if(op=="+"){
        std::cout<<"male"<<endl;
        double temp = s.vals.pop();
        val +=temp;        std::cout<<val<<endl;

    }else if(op=="sqrt"){
        val -=s.vals.pop();
    }else if(op=="-"){
        val -=s.vals.pop();
    }else if(op=="*"){
        val *=s.vals.pop();
    }else if(op=="÷"){
        val = val/s.vals.pop();
    }
    s.vals.push(val);

    ui->textEdit->append(QString::number(val, 10, 4));
    QString x = ui->textEdit->toPlainText();
    x.append(")");
    ui->textEdit->setText(x);}

void MainWindow::on_mulButton_clicked()
{
    s.ops.push("*");
    QString x = ui->textEdit->toPlainText();
    x.append("*");
    ui->textEdit->setText(x);
}

void MainWindow::on_divButton_clicked()
{
    s.ops.push("÷");
    QString x = ui->textEdit->toPlainText();
    x.append("÷");
    ui->textEdit->setText(x);
}

void MainWindow::on_dotButton_clicked()
{

}

void MainWindow::on_rootButton_clicked()
{
    s.ops.push("sqrt");
    QString x = ui->textEdit->toPlainText();
    x.append("sqrt");
    ui->textEdit->setText(x);
}

void MainWindow::on_lnButton_clicked()
{
    s.vals.push(0.0);
    QString x = ui->textEdit->toPlainText();
    x.append("0");
    ui->textEdit->setText(x);
}

void MainWindow::on_powerButton_clicked()
{

}

void MainWindow::on_eButton_clicked()
{
    QString qstr =ui->textEdit->toPlainText();
    int x = qstr.length();
    QString str = qstr.mid(0,x-1);
    ui->textEdit->setText(str);
}

void MainWindow::on_paiButton_clicked()
{
    s.vals.push(3.14159);
    QString x = ui->textEdit->toPlainText();
    x.append("π");
    ui->textEdit->setText(x);
}

void MainWindow::on_powerTButton_clicked()
{

}

void MainWindow::on_pushButton_8_clicked()
{
    ui->textEdit->insertPlainText("wdsnbjkfhuiafgadfg");

}
