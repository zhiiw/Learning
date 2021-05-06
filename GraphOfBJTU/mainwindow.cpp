#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = new sqlUse();
    if(db->db.open()){
        cout<<"open successfully"<<endl;
    }
    QSqlQuery query;
    query.exec("SELECT name, salary FROM employee WHERE salary > 50000");
    while (query.next()) {
        QString name = query.value(0).toString();
        int salary = query.value(1).toInt();
        rp->AddEdge()
    }
    string str = db->db.exec("select * from ");
    for{

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->text();

}
