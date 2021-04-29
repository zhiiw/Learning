#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <string>
using namespace std;

class myException{
   public:
      myException(string theMessage = "Exception occurred.")
          {message = theMessage;}
      string eMessage() {return message;}
   private:
      string message;
};
#endif // MYEXCEPTION_H
