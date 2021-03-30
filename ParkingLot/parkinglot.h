#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include "queue.h"
#include "car.h"
#include <memory>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <thread>
static const int repository_size = 10;//循环队列的大小
static const int item_total = 30;//要生产的产品数目
static std::size_t read_position = 0;//消费者读取产品的位置
static std::size_t write_position = 0;
static std::size_t item_counter = 0;//消费者消费产品计数器
template<class T>
class parkinglot{
private:
    unique_ptr<queue<T>> queue;
    std::mutex mtx;
    std::mutex mtxCounter;
    double initialTime;
    condition_variable queueNotFull;
    condition_variable queueNotEmpty;
    chrono::seconds t(1);
    

public:
    parkinglot();
    ~parkinglot();
    void produceCar(int i);
    int consumeCar();
    void insertCar();
    int chargeForCar();

    void randomTime();

}

template<class T>
void parkinglot<T>::produceCar(int i){
    
}
#endif // PARKINGLOT_H
