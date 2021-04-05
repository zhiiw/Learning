#include "worker.h"
#include "parkinglot.h"
#include "mainwindow.h"
void worker::run(){
    while (1) {
        parkinglot<int> pl(x,y);

        pl.startThreading();
    }

}
