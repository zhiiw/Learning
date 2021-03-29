#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include "queue.h"
#include "car.h"
#include <memory>
template<class T>
class parkinglot{
private:
    unique_ptr<queue<T>> queue;

public:
    parkinglot();
    ~parkinglot();

    void insertCar();
    int chargeForCar();

    void randomTime();

}
#endif // PARKINGLOT_H
