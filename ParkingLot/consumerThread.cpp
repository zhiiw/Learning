#include "consumerThread.h"

consumerThread::consumerThread(QObject *parent) : QThread(parent)
{

}
void consumerThread::consumeCar(){
    while (pl->isQueueEmpty()&&pl->isParkinglotEmpty())
    {
        std::cout << "Parking lot is waiting for cars..." << std::endl;
        sleep(5);
        return;// 消费者等待"产品库缓冲区不为空"这一条件发生.
    }
    pl->tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    pl->nowaTime=(double)std::chrono::duration_cast<std::chrono::milliseconds>(pl->tp.time_since_epoch()).count() - pl->initialTime;
    cout<<"nowatime is "<<pl->nowaTime/200<<endl ;

    QString temmp = "";
    for (int i=0;i<pl->parkNumber;i++){
        if(pl->nowaTime/200>=pl->carInParkingLot.carSpace[i].getOutTime()&&pl->carInParkingLot.existence[i]==true){
            temmp.append("\nThe getOut Time of car is ");
            temmp.append(QString::fromStdString(to_string(pl->carInParkingLot.carSpace[i].getOutTime())));
            cout<<"the enter time is "<<pl->carInParkingLot.carSpace[i].getEnterTime()<<endl;
            temmp.append("\n The enter Time of car is ");
            temmp.append(QString::fromStdString(to_string(pl->carInParkingLot.carSpace[i].getEnterTime())));

            cout<<"The waitingtime is "<<pl->carInParkingLot.carSpace[i].getParkTime()<<endl;
            temmp.append("\nThe waiting Time of car is ");
            temmp.append(QString::fromStdString(to_string(pl->carInParkingLot.carSpace[i].getParkTime())));
            cout<<"The plate is "<<pl->carInParkingLot.carSpace[i].getPlate()<<endl;
            temmp.append("\nThe plate of car is ");
            temmp.append(QString::fromStdString(pl->carInParkingLot.carSpace[i].getPlate()));
            cout<<"The charge is "<<pl->carInParkingLot.carSpace[i].getCharge()<<endl;
            temmp.append("\nThe charge of car is ");
            temmp.append(QString::fromStdString(to_string(pl->carInParkingLot.carSpace[i].getCharge())));
            emit appendText(temmp);
            temmp="";
            string qr = "UPDATE judgeExist SET existence=0 where id =";
            qr+=to_string(i+1);
            emit addSql(QString::fromStdString(qr));
            emit deleteLabel(i) ;
            pl->carInParkingLot.existence[i]=false;
            pl->count++;
            break;
        }
    }
}
void consumerThread::run(){
    sleep(7);
    while(1){
        mutex.lock();
        if(!pl->isParkinglotEmpty()){
            sleep(5);
            int item = 0;
            consumeCar();
            if(pl->count==item_total){
                break;
            }

        }else{
            sleep(5);
        }
        mutex.unlock();
        this->sleep(3);
    }
}

void consumerThread::setParkinglot(parkinglot<int> * p){
    pl = p;
}

void consumerThread::setName(string n){
    name = n;
}
