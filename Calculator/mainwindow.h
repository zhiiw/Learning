#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <calculate.h>
#include <iostream>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    calculate<std::string> s;
    QMessageBox *msgBox;


private slots:
    void on_equalButton_clicked();

    void on_oneButton_clicked();

    void on_twoButton_clicked();

    void on_threeButton_clicked();

    void on_fourButton_2_clicked();

    void on_fourButton_clicked();

    void on_sixButton_clicked();

    void on_sevenButton_clicked();

    void on_eightButton_clicked();

    void on_nineButton_clicked();

    void on_plusButton_clicked();

    void on_acButton_clicked();

    void on_subButton_clicked();

    void on_leftButton_clicked();

    void on_rightButton_clicked();

    void on_mulButton_clicked();

    void on_divButton_clicked();

    void on_dotButton_clicked();

    void on_rootButton_clicked();

    void on_lnButton_clicked();

    void on_powerButton_clicked();

    void on_eButton_clicked();

    void on_paiButton_clicked();

    void on_powerTButton_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
