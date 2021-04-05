#ifndef CAR_H
#define CAR_H
#include "queue.h"
#include <random>
#include <string>
#define PARKINGMAXTIME 480;
#define PARKINGMINTIME 15;
template<class T>
class car{
private:
    double waitingTime;
    double enterTime;
    double outTime;
    double charge;
    string plate;
    int parkingTime;
    string randomGetPlate();
    double countCharge();
    int randomParkingTime();
    int  index;//car's index in parking lot
public:
    car();
    car(double enter);
    ~car();

    double getOutTime();
    double getCharge();
    double getEnterTime();
    double getParkTime();

    string getPlate();


};
template<class T>
car<T>::car(){

}

template<class T>
car<T>::~car(){

}
template<class T>
car<T>::car(double enter){
    enterTime=enter;
    waitingTime=0;
    outTime=0;
    charge=0;
    plate="";
    waitingTime=randomParkingTime();
    outTime= enterTime+waitingTime;
}
template<class T>
string car<T>::getPlate(){
    return plate;
}
template<class T>
double car<T>::getCharge(){
    return charge;
}
template<class T>
double car<T>::getEnterTime(){
    return enterTime;
}
template<class T>
double car<T>::getParkTime(){
    return waitingTime;
}
template<class T>
int car<T>::randomParkingTime(){
    random_device rd;
    default_random_engine random(rd());
    parkingTime = 15+random()%465;
    return parkingTime;
}
template<class T>
double car<T>::getOutTime(){
    return outTime;
}

template<class T>
string car<T>::randomGetPlate(){
    string plate = "";
    
    char tmp;
    
    random_device rd;
    default_random_engine random(rd());
    plate+="京";
    plate+="A";
    
    for (int i = 0; i < 5; i++) {
        tmp = random() % 36;	// 随机一个小于 36 的整数，0-9、A-Z 共 36 种字符
        if (tmp < 10) {			// 如果随机数小于 10，变换成一个阿拉伯数字的 ASCII
            tmp += '0';
        } else {				// 否则，变换成一个大写字母的 ASCII
            tmp -= 10;
            tmp += 'A';
        }
        plate += tmp;
    }
    return plate;
}

template<class T>
double car<T>::countCharge(){
    charge = (parkingTime/15+1)*1.5;
    return charge;
}

#endif // CAR_H
