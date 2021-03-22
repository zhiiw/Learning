#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "CirrcularLinkedList.h"
#include "itemdef.h"
#include "itemdelegate.h"
#include <bits/stdc++.h>
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
    m_delegate = new ItemDelegate(this);
    ui->listView->setItemDelegate(m_delegate);       //为视图设置委托
    ui->listView->setSpacing(15);

    ui->listView->setViewMode(QListView::IconMode); //设置Item图标显示
    ui->listView->setDragEnabled(false);

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
        int x= cl->head->val;
        std::string ee = std::to_string(x);
        ee="猴子王"+ee+"  号";
        int length= cl->getValue();

        std::string len =std::to_string(length);
        QString q_str = QString::fromStdString(len);

        m_model = new QStandardItemModel();

        QStandardItem *Item = new QStandardItem;

        ItemData itemData;

        itemData.name = QString::fromStdString(ee);
        ItemStatus itemStatus;
        itemStatus=Loser;
        Item->setData(itemStatus,Qt::UserRole);  // 单一存取
        Item->setData(QVariant::fromValue(itemData),Qt::UserRole+1);//整体存取

        m_model->appendRow(Item);
        m_proxyModel = new QSortFilterProxyModel(ui->listView);
        m_proxyModel->setSourceModel(m_model);
        m_proxyModel->setFilterRole(Qt::UserRole);
        m_proxyModel->setDynamicSortFilter(true);
        ui->listView->setModel(m_proxyModel);     //追加Item



    }
}

void MainWindow::on_pushButton_2_clicked()
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
       m_model = new QStandardItemModel();
       for (int i = 0; i < in1; ++i) {
           QStandardItem *Item = new QStandardItem;

           ItemData itemData;

           itemData.name = QString("猴子 %1 号").arg(i+1);
           ItemStatus itemStatus;
           itemStatus=Loser;
           Item->setData(itemStatus,Qt::UserRole);  // 单一存取
           Item->setData(QVariant::fromValue(itemData),Qt::UserRole+1);//整体存取

           m_model->appendRow(Item);
           m_proxyModel = new QSortFilterProxyModel(ui->listView);
           m_proxyModel->setSourceModel(m_model);
           m_proxyModel->setFilterRole(Qt::UserRole);
           m_proxyModel->setDynamicSortFilter(true);
           ui->listView->setModel(m_proxyModel);     //追加Item
       }

    }
}
