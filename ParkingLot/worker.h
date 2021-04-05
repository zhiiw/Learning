#ifndef WORKER_H
#define WORKER_H
#include <QObject>
#include <QThread>
#include "parkinglot.h"
class worker : public QThread
{
public:

    Q_OBJECT
    int x;
    int y;
    parkinglot<int> pl;
public:
    void setValue(int a,int b){
        x=a;
        y=b;
    }

private:
    void run() override;
};



#endif // WORKER_H
