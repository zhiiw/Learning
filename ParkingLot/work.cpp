#include "worker.h"
#include "parkinglot.h"
#include "mainwindow.h"
void worker::run(){

    parkinglot<int> pl(x,y);

    pl.startThreading();


}
