#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include "parkinglot.h"
#include "sql.h"
#include "producerThread.h"
#include "consumerThread.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMessageBox *msgBox;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void appendTextEdit(QString);
    void addImage(int);
    void deleteImage(int);
    void runSql(QString);
    void showNumberInLabel(int);
private:
    Ui::MainWindow *ui;
    parkinglot<int> *pl;//
    sql *db;
    produceThread *pro1;//define the pro
    produceThread *pro2;//define the pro

    consumerThread *con;

};
#endif // MAINWINDOW_H
