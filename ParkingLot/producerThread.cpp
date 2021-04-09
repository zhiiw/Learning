#include "producerThread.h"
#include "parkinglot.h"
produceThread::produceThread(QObject *parent) : QThread(parent)
{

}

void produceThread::produceCar(car<int> x){
    // item buffer is empty, just wait here.

    pl->tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    pl->nowaTime=(double)std::chrono::duration_cast<std::chrono::milliseconds>(pl->tp.time_since_epoch()).count() - pl->initialTime;
    cout<<"nowatime is "<<pl->nowaTime/200<<endl ;
    QString temmm = "nowatime is ";
    temmm.append(QString::fromStdString(to_string(pl->nowaTime/200)));
    temmm.append("\n");
    emit appendText(temmm);
    QString temmp = "";
    for(int i = 0 ;i<pl->parkNumber;i++){
        if(pl->carInParkingLot.existence[i]==false){

            pl->carInParkingLot.existence[i]=true;//add a car to the bool array;
            string qr = "UPDATE judgeExist SET existence=1 where id =";
            emit addLabel(i);
            qr+=to_string(i+1);
            emit addSql(QString::fromStdString(qr));


            pl->carInParkingLot.carSpace[i]=x;

            pl->totalCar++;

            string query="INSERT INTO parkinglots (id, enterTime, leaveTime,plate,charge,parkingIndex) VALUES (";

            query+=to_string(pl->totalCar);
            query+=",";
            query+=to_string(x.getEnterTime());
            query+=",";
            query+=to_string(x.getOutTime());
            query+=",'";
            query+=x.getPlate();
            query+="',";
            query+=to_string(x.getCharge());

            query+=",";
            query+=to_string(i);


            query+=")";
            emit addSql(QString::fromStdString(query));
            cout<<query<<endl;
            QString tempp= "\nwe have produced one car and the plate is ";
            tempp.append(QString::fromStdString(pl->carInParkingLot.carSpace[i].getPlate()));

            emit appendText(tempp);
            cout<<"we have produced one car and the plate is "<<pl->carInParkingLot.carSpace[i].getPlate()<<endl;
            break;
        }
    }


}
void produceThread::run(){
    while(1){

        mutex.lock();
        if(item_counter<item_total){
            if(!pl->isParkinglotFull()){
                if(!pl->isQueueEmpty()){
                    pl->tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
                    double enterTime = (double)std::chrono::duration_cast<std::chrono::milliseconds>(pl->tp.time_since_epoch()).count() - pl->initialTime;
                       cout<<"the enter time is  "<<enterTime/1000<<endl;
                    car<int> temp(enterTime/2000);

                    ++item_counter;
                    emit appendText("A car is dequeue from the queue.");

                    produceCar(pl->wait->First());
                    pl->wait->DeQueue();
                }
                else{
                    pl->tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
                    double enterTime = (double)std::chrono::duration_cast<std::chrono::milliseconds>(pl->tp.time_since_epoch()).count() - pl->initialTime;
                    cout<<"the enter time is  "<<enterTime/1000<<endl;
                    car<int> temp(enterTime/2000);
                    cout<<"ee"<<endl;
                    ++item_counter;
                    produceCar(temp);
                }
            }else{
                if(!pl->isQueueFull()){
                    std::cout<<"wozhende  male";
                    pl->tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
                    double enterTime = (double)std::chrono::duration_cast<std::chrono::milliseconds>(pl->tp.time_since_epoch()).count() - pl->initialTime;
                    cout<<"the enter time is  "<<enterTime/1000<<endl;
                    emit appendText("\nA car is enqueue to the waitinglist.");
                    car<int> temp(enterTime/2000);
                    pl->wait->EnQueue(temp);
                    emit showQueueNumber(pl->wait->size());

                    ++item_counter;
                }
                else{
                    sleep(5);
                }

            }
            sleep(5);
        }
        else{
            break;
        }
        mutex.unlock();

    }
}

void produceThread::setParkinglot(parkinglot<int>* p){
    pl = p;
}
