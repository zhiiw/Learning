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

    if (s.ops.find("(")==-1){
        int mul= s.ops.find("*");
        int div =s.ops.find("÷");



    }
    else {
         msgBox = new QMessageBox("title",    ///--这里是设置消息框标题
               "Please input correctly ",            ///--这里是设置消息框显示的内容
               QMessageBox::Critical,              ///--这里是在消息框显示的图标
               QMessageBox::Ok | QMessageBox::Default,    ///---这里是显示消息框上的按钮情况
               QMessageBox::Cancel | QMessageBox::Escape,  ///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
               0);
       msgBox->show();
       return;
    }

    double x = s.vals.top();
    string str = "=";
    str=str+std::to_string(x);
    QString qstr = ui->textEdit->toPlainText();

    ui->textEdit->append(QString::fromStdString(str));
    ui->textEdit_2->append(qstr);
    ui->textEdit_2->append(QString::fromStdString(str));
    ui->textEdit->append("");
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
    s.vals.push(-1);
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
    ui->textEdit->setText(x);
    s.vals.push(-2);}


void MainWindow::on_leftButton_clicked()
{
    s.ops.push("(");
    s.vals.push(-5);
    QString x = ui->textEdit->toPlainText();
    x.append("(");
    ui->textEdit->setText(x);}

void MainWindow::on_rightButton_clicked()
{
    if (s.ops.size()==0){
        return;
    }
    //count the number of ops to operate.
    int count=s.ops.find("(");
    int num=s.ops.size()-count-1;

    for (int i=0;i<num ;i++ ) {
        if(s.ops.arratStack[count+i]=="*"||s.ops.arratStack[count+i]=="÷"){
            int countVal = s.vals.find(-5);
            s.vals.arratStack[countVal];
        }
    }

    string op =s.ops.top();
    s.ops.pop();
    int val=s.vals.top();
    string valStr = "";
    while (s.vals.top()!=-1&&s.vals.top()!=-2&&s.vals.top()!=-3&&s.vals.top()!=-4) {
        val=s.vals.pop();
        valStr=to_string((int)val)+valStr;
    }
    if(op=="+"){
        s.vals.pop();
        double value =stod(valStr);
        double temp = s.vals.pop();
        value +=temp;
        s.vals.push(value);

    }else if(op=="sqrt"){
        s.vals.pop();
        double value =stod(valStr);
        double temp = s.vals.pop();
        value =temp;
        s.vals.push(value);

    }else if(op=="-"){
        s.vals.pop();
        double value =stod(valStr);
        double temp = s.vals.pop();
        value =temp-value;
        s.vals.push(value);
    }else if(op=="*"){
        s.vals.pop();
        double value =stod(valStr);
        double temp = s.vals.pop();
        value *=temp;
        s.vals.push(value);
    }else if(op=="÷"){
        s.vals.pop();
        double value =stod(valStr);
        double temp = s.vals.pop();
        value =temp/value;
        s.vals.push(value);
    }
    s.ops.pop();
    QString x = ui->textEdit->toPlainText();
    x.append(")");
    ui->textEdit->setText(x);
}

void MainWindow::on_mulButton_clicked()
{
    s.ops.push("*");
    QString x = ui->textEdit->toPlainText();
    x.append("*");
    s.vals.push(-3);

    ui->textEdit->setText(x);
}

void MainWindow::on_divButton_clicked()
{
    s.ops.push("÷");
    QString x = ui->textEdit->toPlainText();
    x.append("÷");
    ui->textEdit->setText(x);
    s.vals.push(-4);


}

void MainWindow::on_dotButton_clicked()
{

}

void MainWindow::on_rootButton_clicked()
{
    s.ops.push("sqrt");
    QString x = ui->textEdit->toPlainText();
    x.append("√");
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
