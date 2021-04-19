#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <decompress.h>
#include <time.h>
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
    QString targetFileName = QFileDialog::getSaveFileName(this, "open Target File");
    ui->targetFileEdit->setText(targetFileName);
}


void MainWindow::on_pushButton_3_clicked()
{
    int startTime = time(0);
    ui->textEdit->append("compressing files ");
    if (ui->checkBox->isChecked()){
        if(ui->souceFileEdit->text()!=""&&ui->targetFileEdit->text()!=""&&ui->souceFileEdit_2->text()!=""&&ui->targetFileEdit_2->text()!=""&&ui->targetFileEdit_2->text()!=ui->targetFileEdit->text()&&ui->souceFileEdit->text()!=ui->souceFileEdit_2->text()){
            c1 = new compress(ui->souceFileEdit->text().toStdString(),ui->targetFileEdit->text().toStdString(),true,ui->kpasswordlineedit->password().toStdString());
            c2 = new compress(ui->souceFileEdit_2->text().toStdString(),ui->targetFileEdit_2->text().toStdString(),false,"");
            c1->huffmanForEnglish();
            c2->huffmanForEnglish();
        }else if(ui->souceFileEdit->text()!=""&&ui->targetFileEdit->text()!="") {
            c1 = new compress(ui->souceFileEdit->text().toStdString(),ui->targetFileEdit->text().toStdString(),true,ui->kpasswordlineedit->password().toStdString());
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
    }else{
        if(ui->souceFileEdit->text()!=""&&ui->targetFileEdit->text()!=""&&ui->souceFileEdit_2->text()!=""&&ui->targetFileEdit_2->text()!=""&&ui->targetFileEdit_2->text()!=ui->targetFileEdit->text()&&ui->souceFileEdit->text()!=ui->souceFileEdit_2->text()){
            c1 = new compress(ui->souceFileEdit->text().toStdString(),ui->targetFileEdit->text().toStdString(),false,"");
            c2 = new compress(ui->souceFileEdit_2->text().toStdString(),ui->targetFileEdit_2->text().toStdString(),false,"");
            c1->huffmanForEnglish();
            c2->huffmanForEnglish();

        }else if(ui->souceFileEdit->text()!=""&&ui->targetFileEdit->text()!="") {
            c1 = new compress(ui->souceFileEdit->text().toStdString(),ui->targetFileEdit->text().toStdString(),false,"");
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
    ui->textEdit->append("compress successfully");
    int endTime = time(0);
    string x="time ";
    x+=endTime-startTime;
    x+="s";
    ui->textEdit->append(QString::fromStdString(x));


    
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->append("depressing");
    int startTime = time(0);
    ifstream fin(ui->targetFileEdit->text().toStdString()+".huffman", ios::binary);
    int passNumber = 0;
    fin.read((char*)&passNumber, sizeof(int));
    string passwordUser = "";
    if(passNumber>0){
        bool ok;
        QString text = QInputDialog::getText(this, tr("PASSWORD"),tr("Please enter password"), QLineEdit::Password,0, &ok);
        if (ok && !text.isEmpty())
        {
            passwordUser+=text.toStdString();
        }
        for (int x= 0 ;x<passNumber ;x++ ) {

        }
        char ch;
        string passwordTrue;
        while (true)
        {
            fin.read(&ch, sizeof(char));
            if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')) {
                passwordTrue += ch;
            }
            else {
                if (passwordTrue == "") {
                    passwordTrue += ch;
                    continue;
                }
                if (ch == ',') //读到分隔符（逗号）//
                    break;
            }
        }
        cout<<"the passwordUser is"<<passwordUser<<"the oteher is"<<passwordTrue<<endl;
        if(passwordTrue!=passwordUser&&ui->targetFileEdit->text()!=""&&passNumber>0){
            QMessageBox *msgBox = new QMessageBox("title",    ///--这里是设置消息框标题
                  "password wrong",            ///--这里是设置消息框显示的内容
                  QMessageBox::Critical,              ///--这里是在消息框显示的图标
                  QMessageBox::Ok | QMessageBox::Default,    ///---这里是显示消息框上的按钮情况
                  QMessageBox::Cancel | QMessageBox::Escape,  ///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
                  0);
            msgBox->show();
            return;
        }else{
            d1 = new decompress(ui->targetFileEdit->text().toStdString());
            d1->unCompressHuffmanForEnglish();
        }
    }else{
        d1 = new decompress(ui->targetFileEdit->text().toStdString());
        d1->unCompressHuffmanForEnglish();
    }


    ifstream srcfin(ui->targetFileEdit->text().toStdString()+".dehuff");
    ifstream zipfin(ui->targetFileEdit->text().toStdString()+".huffman");
    long fbeg1 = srcfin.tellg();
    srcfin.seekg(0, ios::end);
    long fend1 = srcfin.tellg();

    long fbeg2 = zipfin.tellg();
    zipfin.seekg(0, ios::end);
    long fend2 = zipfin.tellg();

    cout << ui->targetFileEdit->text().toStdString()+".dehuff" << "大小：" << (fend1 - fbeg1)*1.0 / 1024 << "kb" << endl;
    cout << ui->targetFileEdit->text().toStdString()+".huffman" << "大小：" << (fend2 - fbeg2)*1.0 / 1024 << "kb" << endl;
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "压缩率：" << (fend2 - fbeg2+7) *1.0 / (fend1 - fbeg1) * 100 << "%" << endl;

    srcfin.close();
    zipfin.close();
    ui->textEdit->append("Depress Successfully");
    int endTime = time(0);
    string x="time ";
    x+=endTime-startTime;
    x+="s";
    ui->textEdit->append(QString::fromStdString(x));

    string temp=ui->targetFileEdit->text().toStdString();
    temp+=".dehuff 大小： ";
    temp+=(fend1 - fbeg1)*1.0 / 1024 ;
    temp+="kb";
    ui->textEdit->append(QString::fromStdString(temp));

    string temp2=ui->targetFileEdit->text().toStdString();
    temp2+=".huffman 大小： ";
    temp2+=(fend2 - fbeg2)*1.0 / 1024 ;
    temp2+="kb";
    ui->textEdit->append(QString::fromStdString(temp));


}

