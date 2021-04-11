#ifndef PRODUCERTHREAD_H
#define PRODUCERTHREAD_H
#include <QThread>
#include <QMutex>
#include "parkinglot.h"

#include <QObject>

class produceThread : public QThread {
    Q_OBJECT

public:
    explicit produceThread(QObject *parent = nullptr);
    void run() override;
    void produceCar(car<int> x);
    QMutex mutex;
    void setParkinglot(parkinglot<int>*);
    void setName(string);


signals:

    void appendText(QString);
    void addSql(QString);//add
    void addLabel(int);//add the car image
    void showQueueNumber(int);

private:
    parkinglot<int>* pl;
    string name;
};

#endif // PRODUCERTHREAD_H
