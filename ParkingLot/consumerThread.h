#ifndef CONSUMERTHREAD_H
#define CONSUMERTHREAD_H
#include "parkinglot.h"
#include <QString>
#include "car.h"
#include <QThread>
#include <QMutex>
using namespace std;

class consumerThread : public QThread
{
    Q_OBJECT
public:
    explicit consumerThread(QObject *parent = nullptr);

    void run() override;

    void setParkinglot(parkinglot<int>*);
    void setName(string);
    void consumeCar();

    QMutex mutex;

signals:
    void appendText(QString);//show the dynamic
    void addSql(QString);//add the sql
    void deleteLabel(int);//delete car image
private:

    parkinglot<int>* pl;
    string name;

};

#endif // CONSUMERTHREAD_H
