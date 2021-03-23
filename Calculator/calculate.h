#ifndef CALCULATE_H
#define CALCULATE_H
#include "stack.h"
#include <iostream>
#include <string>
template <class T>
class calculate{
public:
    calculate();
    stack<T> ops;
    stack<double> vals;



};

template <class T>
calculate<T>::calculate(){

}

#endif // CALCULATE_H
