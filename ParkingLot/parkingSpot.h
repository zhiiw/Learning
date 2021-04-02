#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H
#include "car.h"
template<class T>
class parkingSpot{
public:
    bool *existence;
    vector<car<int>> carSpace;

    parkingSpot();
    ~parkingSpot();

    parkingSpot(int number);
    car<T> getCar(int i);
};

template<class T>
parkingSpot<T>::parkingSpot(int number){
    existence= new bool[number];
}
template<class T>
parkingSpot<T>::parkingSpot(){

}
template<class T>
parkingSpot<T>::~parkingSpot(){

}
template<class T>
car<T> parkingSpot<T>::getCar(int i){

    return carSpace[i];
}
#endif // PARKINGSPOT_H
