#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include "queue.h"
#include "car.h"
#include <memory>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <QSql>
#include <thread>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
using namespace std;
static const int repository_size = 10;//循环队列的大小
static const int item_total = 30;//要生产的产品数目
static std::size_t read_position = 0;//消费者读取产品的位置
static std::size_t write_position = 0;
static std::size_t item_counter = 0;//消费者消费产品计数器
template<class T>
class parkinglot{
private:
    queue<T> *wait;//the waiting queue.
    bool *carInParkingLot; //the car array in parkinglot
    queue<unique_ptr<T>> queueForPark;
    unique_ptr<queue<T>> queueForParking;
    std::mutex mtx;
    std::mutex mtxCounter;
    double initialTime;
    condition_variable queueNotFull;
    condition_variable queueNotEmpty;
    std::chrono::seconds t;
    QSqlDatabase database;

public:
    parkinglot();
    parkinglot(int parkingNumber,int queueNumber);//n is p
    ~parkinglot();
    void produceCar(int i);
    void consumeCar();
    void insertCar();
    double totalCharge;
    double chargeForCar();

    void randomTime();

};
template<class T>
parkinglot<T>::parkinglot(){
}
template<class T>
parkinglot<T>::~parkinglot(){

}
template<class T>
parkinglot<T>::parkinglot(int parkingNumber,int queueNumber){
    carInParkingLot= new bool[parkingNumber];
    for (int i= 0 ; i<parkingNumber;i++){
        carInParkingLot[i]=false;
    }
    queue<int> *xm = new queue<int>(queueNumber);
    wait = xm;

}
template<class T>
void parkinglot<T>::produceCar(int i){

    /*
    unique_lock<mutex> lck(mtx);
    while ((write_position+1)%repository_size==read_position) {
        wait.EnQueue();//while is full,add it to the queue
        cout<<"Producer is waiting for ...."<<queueNotFull.wait(lck)<<endl;
    }

    queueNotFull.notify_all();//通知消费者产品库不为空
    lck.unlock();//解锁
    */

}
template<class T>
void parkinglot<T>::consumeCar(){
    /*
    int data;
    unique_lock<mutex> lck(mtx);
    // item buffer is empty, just wait here.
    while (write_position == read_position)
    {
        std::cout << "Consumer is waiting for items..." << std::endl;
        repo_not_empty.wait(lck);// 消费者等待"产品库缓冲区不为空"这一条件发生.
    }

    data = item_buffer[read_position];//读取产品
    read_position++;

    if (read_position >= repository_size)
    {
        read_position = 0;
    }

    repo_not_full.notify_all();//通知产品库不满
    lck.unlock();

    return data;
    */
}
template<class T>
double parkinglot<T>::chargeForCar(){

}
template<class T>
void producerThread(){
    /*
    bool readyToExit;
    while(1){
        unique_lock<mutex> lck(mtxCounter);
        if(item_counter<item_total){
            ++item_counter;
            produceCar();

        }
    }*/
}
template<class T>
void consumerThread(){
    static int cnt=0;
    /*
    while (1) {
        this_thread::sleep_for(t);
        int item = 0;
        std::cout<<"consumer consume "<<item<<"product";
        if(++cnt==item_total){
            break;
        }
    }*/
}
#endif // PARKINGLOT_H
