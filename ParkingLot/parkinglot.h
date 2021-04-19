#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include "queue.h"
#include "car.h"
#include "parkingSpot.h"
#include <memory>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <unistd.h>
#include <QDebug>
using namespace std;
static const int repository_size = 10;//循环队列的大小
static const int item_total = 30;//要生产的产品数目
static std::size_t read_position = 0;//消费者读取产品的位置
static std::size_t write_position = 0;
static std::size_t  item_counter = 0;//消费者消费产品计数器
template<class T>
class parkinglot{

private:


    std::mutex mtx;
    std::mutex mtxCounter;

    condition_variable queueNotFull;
    condition_variable queueNotEmpty;
    condition_variable parkinglotNotFull;
    condition_variable parkinglotNotEmpty;


public:
    int count;

    queue<T> *wait;//the waiting queue.
    int totalCar;
    parkingSpot<T> carInParkingLot; //the car array in parkinglot

    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp;
    int parkNumber;

    double initialTime;
    double nowaTime;
    parkinglot();
    parkinglot(int parkingNumber,int queueNumber);//n is p
    ~parkinglot();

    void insertCar();
    double totalCharge;
    double chargeForCar();
    bool isParkinglotFull();
    bool isParkinglotEmpty();
    bool isQueueFull();
    bool isQueueEmpty();
    void enqueueCar(car<int> x);
    void randomTime();

};
template<class T>
parkinglot<T>::parkinglot(){
}
template<class T>
parkinglot<T>::~parkinglot(){

}

template<class T>
void parkinglot<T>::enqueueCar(car<int> x){
    wait->EnQueue(x);
}
template<class T>
parkinglot<T>::parkinglot(int parkingNumber,int queueNumber){
    carInParkingLot= parkingSpot<T>(parkingNumber);
    parkNumber=parkingNumber;
    tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());

    initialTime= (double)std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count();//according to the now time to get the initial time
    for (int i= 0 ; i<parkingNumber;i++){
        carInParkingLot.existence[i]=false;
        carInParkingLot.carSpace[i]=car<T>(initialTime);
    }
    wait = new queue<int>(queueNumber);
    totalCar=0;
    count=0;



}
template<class T>
bool parkinglot<T>::isParkinglotFull(){
    for (int i= 0 ; i<parkNumber;i++){
        if(carInParkingLot.existence[i]==false){
            cout<<"the lot is full"<<endl;
            return false;
        }
    }
    return true;
}
template<class T>
bool parkinglot<T>::isParkinglotEmpty(){
    for (int i= 0 ; i<parkNumber;i++){
        if(carInParkingLot.existence[i]==true){
            return false;
        }
    }
    return true;

}
template<class T>
bool parkinglot<T>::isQueueEmpty(){
    return wait->IsEmpty();
}
template<class T>
bool parkinglot<T>::isQueueFull(){
    if(wait->IsFull()){
        cout<<"the queue is full .";
        return true;
    }
    return wait->IsFull();

}

#endif // PARKINGLOT_H
