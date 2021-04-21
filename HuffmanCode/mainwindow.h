#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define ImageCompress 6
#include <QInputDialog>
#include <QMainWindow>
#include "compress.h"
#include "decompress.h"
#include<iomanip>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    compress *c1;
    compress *c2;
    decompress *d1;
    decompress *d2;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
