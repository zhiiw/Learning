#ifndef WORKER_H
#define WORKER_H
#include <QObject>
#include <QThread>
#include "parkinglot.h"
class worker : public QThread
{
    Q_OBJECT
    int x;
    int y;
public:
    void setValue(int a,int b){
        x=a;
        y=b;
    }
private:
    void run();
};



#endif // WORKER_H
