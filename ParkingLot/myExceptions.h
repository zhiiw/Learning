#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
#include <string>

using namespace std;

class myException{
public:
    myException(string theMessage = "Exception occured.")
        {message = theMessage;}
    string eMessage(){return message;}

private:
    string message;
};

#endif // MYEXCEPTIONS_H
