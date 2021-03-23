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
    cout<<s.ops.find("(");
    s.ops.show();
    if (s.ops.find("(")==-1){

        int num=s.ops.size();//total operator number
        double tempFor[100];
        string tempForString[100];
        for (int i=0;i<=num ;i++ ) {
            cout<<"num is "<<num<<" i is   "<<i<<endl;

            if(s.ops.arratStack[i]=="*"){
                //if get the * , i from val 的
                int countVal = s.vals.find(-5);
                int multiNumber=0;
                for(int j=countVal;j<s.vals.size();j++){
                    if(s.vals.arratStack[j]==-3){
                        multiNumber=j;//remember the multi sign number
                        cout<<"the multi is "<<multiNumber<<endl;
                        break;
                    }
                }
                int tempBack=multiNumber+1;
                string back="";
                string front="";
                s.ops.show();
                s.vals.show();
                int tempFront=multiNumber-1;
                while(s.vals.arratStack[tempBack]>0){
                    if(tempBack>s.vals.stackTop){
                        break;
                    }
                    back=back+to_string((int)s.vals.arratStack[tempBack]);
                    tempBack++;
                }
                while(s.vals.arratStack[tempFront]>0){
                    front=to_string((int)s.vals.arratStack[tempFront])+front ;
                    tempFront--;
                }
                //get the front number and back number
                cout<<front<<back<<endl;
                double result  = stod(back)*stod(front);
                cout<<result<<endl;

                //获取前后然后得到结果 然后加到 array 后面 再把前移
                s.vals.arratStack[tempFront+1]=result;
                s.vals.show();

                int tempLen;
                for (tempLen=tempBack;tempLen<=s.vals.stackTop;tempLen++ ) {
                    tempFor[tempLen]=s.vals.arratStack[tempLen];
                }
                s.vals.show();
                s.vals.stackTop=s.vals.stackTop-(tempBack-tempFront-2);
                tempLen=tempBack;
                for (int j= tempFront+2 ;j<= s.vals.stackTop;j++,tempLen++ ) {
                    s.vals.arratStack[j]=tempFor[tempLen];
                }
                s.vals.show();

                for (int j= i+1;j<=s.ops.stackTop ;j++ ) {
                    tempForString[j]=s.ops.arratStack[j];
                    cout<<s.ops.arratStack[j]<<endl;
                }
                s.vals.show();

                s.ops.stackTop--;
                for (int h= i; h<=s.ops.stackTop;h++ ) {
                    s.ops.arratStack[h]=tempForString[h+1];
                    cout<<s.ops.arratStack[h+1]<<endl;

                }
                s.ops.show();
                s.vals.show();
                num--;
                i--;
            }else if(s.ops.arratStack[i]=="÷"){
                int countVal = s.vals.find(-5);
                int multiNumber=0;
                for(int j=countVal;j<s.vals.size();j++){
                    if(s.vals.arratStack[j]==-4){
                        multiNumber=j;//remember the multi sign number
                        break;
                    }
                }
                int tempBack=multiNumber+1;
                string back="";
                string front="";
                s.ops.show();
                s.vals.show();
                int tempFront=multiNumber-1;
                while(s.vals.arratStack[tempBack]>0){
                    if(tempBack>s.vals.stackTop){
                        break;
                    }
                    back=back+to_string((int)s.vals.arratStack[tempBack]);
                    tempBack++;
                }
                while(s.vals.arratStack[tempFront]>0){
                    front=to_string((int)s.vals.arratStack[tempFront])+front ;
                    tempFront--;
                }
                cout<<front<<back<<endl;
                double result  = stod(back)/stod(front);
                cout<<result<<endl;

                //获取前后然后得到结果 然后加到 array 后面 再把前移
                s.vals.arratStack[tempFront+1]=result;
                s.vals.show();

                int tempLen;
                for (tempLen=tempBack;tempLen<=s.vals.stackTop;tempLen++ ) {
                    tempFor[tempLen]=s.vals.arratStack[tempLen];
                }
                s.vals.show();
                s.vals.stackTop=s.vals.stackTop-(tempBack-tempFront-2);
                tempLen=tempBack;
                for (int j= tempFront+2 ;j<= s.vals.stackTop;j++,tempLen++ ) {
                    s.vals.arratStack[j]=tempFor[tempLen];
                }
                s.vals.show();

                for (int j= i+1;j<=s.ops.stackTop ;j++ ) {
                    tempForString[j]=s.ops.arratStack[j];
                    cout<<s.ops.arratStack[j]<<endl;
                }
                s.vals.show();

                s.ops.stackTop--;
                for (int h= i; h<=s.ops.stackTop;h++ ) {
                    s.ops.arratStack[h]=tempForString[h+1];
                    cout<<s.ops.arratStack[h+1]<<endl;

                }
                i--;
                num--;
                s.ops.show();
                s.vals.show();
            }
            cout<<"wsngg"<<endl;

        }
        cout<<"hello world"<<endl;

        string valStr = "";
        int num2=s.ops.size()-1;
        for (int i=0; i<=num2; i++) {
            if(s.ops.find("+")>0){
                int countVal = s.vals.find(-5);
                int addNumber=0;
                for(int j=countVal;j<s.vals.size();j++){
                    if(s.vals.arratStack[j]==-1){
                        addNumber=j;//remember the multi sign number
                        break;
                    }
                }
                int tempBack=addNumber+1;
                string back="";
                string front="";
                s.ops.show();
                s.vals.show();
                int tempFront=addNumber-1;
                while(s.vals.arratStack[tempBack]>0){
                    if(tempBack>s.vals.stackTop){
                        break;
                    }
                    back=back+to_string((int)s.vals.arratStack[tempBack]);
                    tempBack++;
                }
                while(s.vals.arratStack[tempFront]>0){
                    front=to_string((int)s.vals.arratStack[tempFront])+front ;
                    tempFront--;
                }
                cout<<front<<"   "<<back<<endl;
                double result  = stod(back)+stod(front);
                cout<<result<<endl;

                //获取前后然后得到结果 然后加到 array 后面 再把前移
                s.vals.arratStack[tempFront+1]=result;
                s.vals.show();

                int tempLen;
                for (tempLen=tempBack;tempLen<=s.vals.stackTop;tempLen++ ) {
                    tempFor[tempLen]=s.vals.arratStack[tempLen];
                }
                s.vals.show();
                s.vals.stackTop=s.vals.stackTop-(tempBack-tempFront-2);
                tempLen=tempBack;
                for (int j= tempFront+2 ;j<= s.vals.stackTop;j++,tempLen++ ) {
                    s.vals.arratStack[j]=tempFor[tempLen];
                }
                s.vals.show();

                cout<<i+1<< "  "<<s.ops.stackTop<<endl;
                for (int j= i+1;j<=s.ops.stackTop ;j++ ) {
                    tempForString[j]=s.ops.arratStack[j];
                }
                s.vals.show();

                s.ops.stackTop--;
                for (int h= i; h<=s.ops.stackTop;h++ ) {
                    s.ops.arratStack[h]=tempForString[h+1];

                }
                i--;
                num--;
                s.ops.show();
                s.vals.show();
            }else if(s.ops.find("-")>0){
                cout<<"wsngg chufa"<<endl;
                int countVal = s.vals.find(-5);
                int addNumber=0;
                for(int j=countVal;j<s.vals.size();j++){
                    if(s.vals.arratStack[j]==-2){
                        addNumber=j;//remember the multi sign number
                        break;
                    }
                }
                int tempBack=addNumber+1;
                string back="";
                string front="";
                s.ops.show();
                s.vals.show();
                int tempFront=addNumber-1;
                while(s.vals.arratStack[tempBack]>0){
                    if(tempBack>s.vals.stackTop){
                        break;
                    }
                    back=back+to_string((int)s.vals.arratStack[tempBack]);
                    tempBack++;
                }
                while(s.vals.arratStack[tempFront]>0){
                    front=to_string((int)s.vals.arratStack[tempFront])+front ;
                    tempFront--;
                }
                cout<<front<<" "<<back<<endl;
                double result  = stod(front)-stod(back);
                cout<<result<<endl;

                //获取前后然后得到结果 然后加到 array 后面 再把前移
                s.vals.arratStack[tempFront+1]=result;
                s.vals.show();

                int tempLen;
                for (tempLen=tempBack;tempLen<=s.vals.stackTop;tempLen++ ) {
                    tempFor[tempLen]=s.vals.arratStack[tempLen];
                }
                s.vals.show();
                s.vals.stackTop=s.vals.stackTop-(tempBack-tempFront-2);
                tempLen=tempBack;
                for (int j= tempFront+2 ;j<= s.vals.stackTop;j++,tempLen++ ) {
                    s.vals.arratStack[j]=tempFor[tempLen];
                }
                s.vals.show();

                cout<<i+1<< "  "<<s.ops.stackTop<<endl;
                for (int j= i+1;j<=s.ops.stackTop ;j++ ) {
                    tempForString[j]=s.ops.arratStack[j];
                    cout<<s.ops.arratStack[j]<<endl;
                }
                s.vals.show();

                s.ops.stackTop--;
                for (int h= i; h<=s.ops.stackTop;h++ ) {
                    s.ops.arratStack[h]=tempForString[h+1];
                    cout<<s.ops.arratStack[h+1]<<endl;

                }
                i--;
                num--;
                s.ops.show();
                s.vals.show();
            }
        }


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
    s.ops.show();
    //count the number of ops to operate.
    int count=s.ops.find("(");
    int num=s.ops.size()-count-1;//total operator number
    double tempFor[100];// store the temp array
    string tempForString[100];
    //
    cout<<"hi"<<endl;
    for (int i=0;i<=num ;i++ ) {
        cout<<"num is "<<num<<" i is   "<<i<<endl;

        if(s.ops.arratStack[count+i]=="*"){
            //if get the * , i from val 的
            int countVal = s.vals.find(-5);
            int multiNumber=0;
            for(int j=countVal;j<s.vals.size();j++){
                if(s.vals.arratStack[j]==-3){
                    multiNumber=j;//remember the multi sign number
                    cout<<"the multi is "<<multiNumber<<endl;
                    break;
                }
            }
            int tempBack=multiNumber+1;
            string back="";
            string front="";
            s.ops.show();
            s.vals.show();
            int tempFront=multiNumber-1;
            while(s.vals.arratStack[tempBack]>0){
                if(tempBack>s.vals.stackTop){
                    break;
                }
                back=back+to_string((int)s.vals.arratStack[tempBack]);
                tempBack++;
            }
            while(s.vals.arratStack[tempFront]>0){
                front=to_string((int)s.vals.arratStack[tempFront])+front ;
                tempFront--;
            }
            //get the front number and back number
            cout<<front<<back<<endl;
            double result  = stod(back)*stod(front);
            cout<<result<<endl;

            //获取前后然后得到结果 然后加到 array 后面 再把前移
            s.vals.arratStack[tempFront+1]=result;
            s.vals.show();

            int tempLen;
            for (tempLen=tempBack;tempLen<=s.vals.stackTop;tempLen++ ) {
                tempFor[tempLen]=s.vals.arratStack[tempLen];
            }
            s.vals.show();
            s.vals.stackTop=s.vals.stackTop-(tempBack-tempFront-2);
            tempLen=tempBack;
            for (int j= tempFront+2 ;j<= s.vals.stackTop;j++,tempLen++ ) {
                s.vals.arratStack[j]=tempFor[tempLen];
            }
            s.vals.show();

            cout<<count+i+1<< "  "<<s.ops.stackTop<<endl;
            for (int j= count+i+1;j<=s.ops.stackTop ;j++ ) {
                tempForString[j]=s.ops.arratStack[j];
                cout<<s.ops.arratStack[j]<<endl;
            }
            s.vals.show();

            s.ops.stackTop--;
            for (int h= count+i; h<=s.ops.stackTop;h++ ) {
                s.ops.arratStack[h]=tempForString[h+1];
                cout<<s.ops.arratStack[h+1]<<endl;

            }
            s.ops.show();
            s.vals.show();
            num--;
            i--;
        }else if(s.ops.arratStack[count+i]=="÷"){
            int countVal = s.vals.find(-5);
            int multiNumber=0;
            for(int j=countVal;j<s.vals.size();j++){
                if(s.vals.arratStack[j]==-4){
                    multiNumber=j;//remember the multi sign number
                    break;
                }
            }
            int tempBack=multiNumber+1;
            string back="";
            string front="";
            s.ops.show();
            s.vals.show();
            int tempFront=multiNumber-1;
            while(s.vals.arratStack[tempBack]>0){
                if(tempBack>s.vals.stackTop){
                    break;
                }
                back=back+to_string((int)s.vals.arratStack[tempBack]);
                tempBack++;
            }
            while(s.vals.arratStack[tempFront]>0){
                front=to_string((int)s.vals.arratStack[tempFront])+front ;
                tempFront--;
            }
            cout<<front<<back<<endl;
            double result  = stod(front)/stod(back);
            cout<<result<<endl;

            //获取前后然后得到结果 然后加到 array 后面 再把前移
            s.vals.arratStack[tempFront+1]=result;
            s.vals.show();

            int tempLen;
            for (tempLen=tempBack;tempLen<=s.vals.stackTop;tempLen++ ) {
                tempFor[tempLen]=s.vals.arratStack[tempLen];
            }
            s.vals.show();
            s.vals.stackTop=s.vals.stackTop-(tempBack-tempFront-2);
            tempLen=tempBack;
            for (int j= tempFront+2 ;j<= s.vals.stackTop;j++,tempLen++ ) {
                s.vals.arratStack[j]=tempFor[tempLen];
            }
            s.vals.show();

            cout<<count+i+1<< "  "<<s.ops.stackTop<<endl;
            for (int j= count+i+1;j<=s.ops.stackTop ;j++ ) {
                tempForString[j]=s.ops.arratStack[j];
                cout<<s.ops.arratStack[j]<<endl;
            }
            s.vals.show();

            s.ops.stackTop--;
            for (int h= count+i; h<=s.ops.stackTop;h++ ) {
                s.ops.arratStack[h]=tempForString[h+1];
                cout<<s.ops.arratStack[h+1]<<endl;

            }
            i--;
            num--;
            s.ops.show();
            s.vals.show();
        }
        cout<<"wsngg"<<endl;

    }
    cout<<"hello world"<<endl;

    string valStr = "";
    int num2=s.ops.size()-count-1;
    for (int i=0; i<=num2; i++) {
        if(s.ops.find("+")>0){
            int countVal = s.vals.find(-5);
            int addNumber=0;
            for(int j=countVal;j<s.vals.size();j++){
                if(s.vals.arratStack[j]==-1){
                    addNumber=j;//remember the multi sign number
                    break;
                }
            }
            int tempBack=addNumber+1;
            string back="";
            string front="";
            s.ops.show();
            s.vals.show();
            int tempFront=addNumber-1;
            while(s.vals.arratStack[tempBack]>0){
                if(tempBack>s.vals.stackTop){
                    break;
                }
                back=back+to_string((int)s.vals.arratStack[tempBack]);
                tempBack++;
            }
            while(s.vals.arratStack[tempFront]>0){
                front=to_string((int)s.vals.arratStack[tempFront])+front ;
                tempFront--;
            }
            cout<<front<<"   "<<back<<endl;
            double result  = stod(back)+stod(front);
            cout<<result<<endl;

            //获取前后然后得到结果 然后加到 array 后面 再把前移
            s.vals.arratStack[tempFront+1]=result;
            s.vals.show();

            int tempLen;
            for (tempLen=tempBack;tempLen<=s.vals.stackTop;tempLen++ ) {
                tempFor[tempLen]=s.vals.arratStack[tempLen];
            }
            s.vals.show();
            s.vals.stackTop=s.vals.stackTop-(tempBack-tempFront-2);
            tempLen=tempBack;
            for (int j= tempFront+2 ;j<= s.vals.stackTop;j++,tempLen++ ) {
                s.vals.arratStack[j]=tempFor[tempLen];
            }
            s.vals.show();

            cout<<count+i+1<< "  "<<s.ops.stackTop<<endl;
            for (int j= count+i+1;j<=s.ops.stackTop ;j++ ) {
                tempForString[j]=s.ops.arratStack[j];
            }
            s.vals.show();

            s.ops.stackTop--;
            for (int h= count+i; h<=s.ops.stackTop;h++ ) {
                s.ops.arratStack[h]=tempForString[h+1];

            }
            i--;
            num--;
            s.ops.show();
            s.vals.show();
        }else if(s.ops.find("-")>0){
            cout<<"wsngg chufa"<<endl;
            int countVal = s.vals.find(-5);
            int addNumber=0;
            for(int j=countVal;j<s.vals.size();j++){
                if(s.vals.arratStack[j]==-2){
                    addNumber=j;//remember the multi sign number
                    break;
                }
            }
            int tempBack=addNumber+1;
            string back="";
            string front="";
            s.ops.show();
            s.vals.show();
            int tempFront=addNumber-1;
            while(s.vals.arratStack[tempBack]>0){
                if(tempBack>s.vals.stackTop){
                    break;
                }
                back=back+to_string((int)s.vals.arratStack[tempBack]);
                tempBack++;
            }
            while(s.vals.arratStack[tempFront]>0){
                front=to_string((int)s.vals.arratStack[tempFront])+front ;
                tempFront--;
            }
            cout<<front<<" "<<back<<endl;
            double result  = stod(front)-stod(back);
            cout<<result<<endl;

            //获取前后然后得到结果 然后加到 array 后面 再把前移
            s.vals.arratStack[tempFront+1]=result;
            s.vals.show();

            int tempLen;
            for (tempLen=tempBack;tempLen<=s.vals.stackTop;tempLen++ ) {
                tempFor[tempLen]=s.vals.arratStack[tempLen];
            }
            s.vals.show();
            s.vals.stackTop=s.vals.stackTop-(tempBack-tempFront-2);
            tempLen=tempBack;
            for (int j= tempFront+2 ;j<= s.vals.stackTop;j++,tempLen++ ) {
                s.vals.arratStack[j]=tempFor[tempLen];
            }
            s.vals.show();

            cout<<count+i+1<< "  "<<s.ops.stackTop<<endl;
            for (int j= count+i+1;j<=s.ops.stackTop ;j++ ) {
                tempForString[j]=s.ops.arratStack[j];
                cout<<s.ops.arratStack[j]<<endl;
            }
            s.vals.show();

            s.ops.stackTop--;
            for (int h= count+i; h<=s.ops.stackTop;h++ ) {
                s.ops.arratStack[h]=tempForString[h+1];
                cout<<s.ops.arratStack[h+1]<<endl;

            }
            i--;
            num--;
            s.ops.show();
            s.vals.show();
        }
    }

    cout<<"yingle"<<endl;
    s.ops.pop();
    int tempLen;
    for (tempLen=count;tempLen<=count+1;tempLen++ ) {
        tempFor[tempLen]=s.vals.arratStack[tempLen];
    }
    s.vals.show();
    s.vals.arratStack[count]=tempFor[count+1];
    s.vals.stackTop=s.vals.stackTop-1;

    s.vals.show();
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
