#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include "queue.h"
#include "car.h"
#include "parkingSpot.h"
#include <memory>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <QSql>
#include <thread>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <unistd.h>
using namespace std;
static const int repository_size = 10;//循环队列的大小
static const int item_total = 40;//要生产的产品数目
static std::size_t read_position = 0;//消费者读取产品的位置
static std::size_t write_position = 0;
static std::size_t item_counter = 0;//消费者消费产品计数器
template<class T>
class parkinglot{
private:
    queue<T> *wait;//the waiting queue.
    int totalCar;
    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp;
    parkingSpot<T> carInParkingLot; //the car array in parkinglot

    int parkNumber;
    std::mutex mtx;
    std::mutex mtxCounter;
    double initialTime;
    double nowaTime;
    condition_variable queueNotFull;
    condition_variable queueNotEmpty;
    condition_variable parkinglotNotFull;
    condition_variable parkinglotNotEmpty;
    QSqlDatabase database;
public:
    parkinglot();
    parkinglot(int parkingNumber,int queueNumber);//n is p
    ~parkinglot();
    void produceCar(car<T> x);
    void consumeCar();
    void producerThread();
    void consumerThread();
    void insertCar();
    double totalCharge;
    double chargeForCar();
    bool isParkinglotFull();
    bool isParkinglotEmpty();
    bool isQueueFull();
    bool isQueueEmpty();
    void startThreading();

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
    carInParkingLot= parkingSpot<T>(parkingNumber);
    parkNumber=parkingNumber;
    tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    for (int i= 0 ; i<parkingNumber;i++){
        carInParkingLot.existence[i]=false;
    }
    initialTime= (double)std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count();
    queue<int> *xm = new queue<int>(queueNumber);
    wait = xm;
    totalCar=0;
}
template<class T>
bool parkinglot<T>::isParkinglotFull(){
    for (int i= 0 ; i<parkNumber;i++){
        if(carInParkingLot.existence[i]==false){
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

    return wait->IsFull();
}
template<class T>
void parkinglot<T>::produceCar(car<T> x){
    cout<<"tthe produce car thread have started"<<endl;
    QSqlQuery qry;

    unique_lock<mutex> lck(mtx);
    while (wait->IsFull()&&isParkinglotFull()) {
        cout<<"car is waiting for empty space"<<endl;
        queueNotFull.wait(lck);
    }

    if (isParkinglotFull()){
        wait->EnQueue(x);//make a reminder to notify me to dequeue the car and add it to the bool array;
    }else {
        for(int i = 0 ;i<parkNumber;i++){
            if(carInParkingLot.existence[i]==false){

                carInParkingLot.existence[i]=true;//add a car to the bool array;

                carInParkingLot.carSpace.push_back(x);

                totalCar++;
                string query="INSERT INTO names (id, enterTime, leaveTime,plate) VALUES (";

                query+=to_string(totalCar);
                query+=", 2, 3,";
                query+= x.getPlate();
                query+=")";

                qry.prepare(QString::fromStdString(query));
                cout<<"we have produced one car."<<endl;
                break;
            }
        }
    }
    queueNotEmpty.notify_all();//通知消费者产品库不为空
    lck.unlock();//解锁
}
template<class T>
void parkinglot<T>::consumeCar(){

    unique_lock<mutex> lck(mtx);
    // item buffer is empty, just wait here.
    while (wait->IsEmpty()&&isParkinglotEmpty())
    {
        std::cout << "Parking lot is waiting for cars..." << std::endl;
        queueNotEmpty.wait(lck);      // 消费者等待"产品库缓冲区不为空"这一条件发生.
    }
    cout<<"ee"<<endl;
    tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    nowaTime=(double)std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count() - initialTime;
    cout<<"nowatime is "<<nowaTime/1000<<endl ;
    for (int i=0;i<parkNumber;i++){
        if(nowaTime/1000>=carInParkingLot.carSpace[i].getOutTime()&&carInParkingLot.existence[i]==true){
            cout<<"The getOut Time of car is "<<carInParkingLot.carSpace[i].getOutTime()<<endl;
            carInParkingLot.existence[i]=false;
            break;
        }
    }

    queueNotFull.notify_all();//通知产品库不满
    lck.unlock();


}

template<class T>
void parkinglot<T>::producerThread(){

    bool readyToExit;

    while(1){
        unique_lock<mutex> lck(mtxCounter);

        if(item_counter<item_total){
            ++item_counter;
            sleep(5);
            if(isParkinglotFull()){
                if(isQueueFull()){
                    sleep(5);
                }else{
                    tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
                    double enterTime = (double)std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count() - initialTime;
                       cout<<"the enter time is  "<<enterTime/1000<<endl;
                    car<T> temp(enterTime/1000);
                    produceCar(temp);
                }
            }else{
                std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> y = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
                double enterTime = (double)std::chrono::duration_cast<std::chrono::milliseconds>(y.time_since_epoch()).count() - initialTime;
                cout<<"the enter time is  "<<enterTime/1000<<endl;

                car<T> temp(enterTime/1000);
                produceCar(temp);
            }

        }
    }
}
template<class T>
void parkinglot<T>::consumerThread(){
    static int cnt=0;
    bool read_to_exit;
    while (1) {
        sleep(5);
        int item = 0;
        consumeCar();
        if(++cnt==item_total){
            break;
        }
    }
}

template<class T>
void parkinglot<T>::startThreading(){
    std::vector<std::thread> thread_vector;
    for (int i = 0; i <2; ++i)
    {

        thread_vector.push_back(std::thread(&parkinglot<T>::producerThread,this));// 创建消费者线程.
    }
    vector<std::thread> threadVectorConsume;
    threadVectorConsume.push_back(std::thread(&parkinglot<T>::consumerThread,this)); // 创建消费之线程.

    for (auto &thr : thread_vector)
    {
        thr.join();
    }

    for (auto &thr : threadVectorConsume)
    {
        thr.join();
    }
}
#endif // PARKINGLOT_H
