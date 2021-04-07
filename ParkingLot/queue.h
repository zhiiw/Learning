#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <iostream>
#include "myExceptions.h"
#include "car.h"
template <class T>
class queue{
private:
    int front;
    int rear;
    int MaxSize;
    car<T> *array;

public:
    queue(int MaxQueueSize = 10);
    ~queue();
    bool IsEmpty() {return front==rear;}
    bool IsFull() {
        return (rear+1)%MaxSize==front;
    }
    car<T> First();
    car<T> Last();
    void EnQueue(car<T> x);
    void DeQueue();
};

template<class T>
queue<T>::queue(int MaxQueueSize) {
    MaxSize =MaxQueueSize+1;
    array = new car<T>[MaxSize];
    front = rear =0;
}
template<class T>
queue<T>::~queue() {
    delete [] array;
}
template<class T>
car<T> queue<T>::First(){
    if(IsEmpty()){
        throw myException("out of bound");
    }
    return array[(front+1)%MaxSize];
}

template<class T>
car<T> queue<T>::Last(){
    if(IsEmpty()){
        throw myException("out of bound");
    }
    return array[rear];
}

template<class T>
void queue<T>::EnQueue(car<T> x){
    if (IsFull()){
        throw myException("Out of space");
    }
    rear=(rear+1)%MaxSize;
    array[rear] = x;

}

template<class T>
void queue<T>::DeQueue(){
    if (IsEmpty()) throw myException("out of Bounds");
    front = (front+1)%MaxSize;

}

#endif // QUEUE_H
