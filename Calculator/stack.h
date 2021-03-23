#ifndef STACK_H
#define STACK_H
#include <sstream>
template <class T>
class stack{
public:
    void push(const T& val);
    T pop(){
        if (stackTop==-1){

        }
        stackTop--;
        return arratStack[stackTop+1];
    }
    void deleteAll()const {stackTop==-1;}
    int size()const {return stackTop+1;}
    bool isEmpty();
    T& top(){
        if(stackTop==-1){

        }
        return arratStack[stackTop];
    }
    stack();
    ~stack() {delete [] arratStack;}
    int count;
private:
    int stackTop;
    T *arratStack;
    int length;
};


template<class T>
stack<T>::stack()
{// Constructor.

   arratStack = new T[1024];
   stackTop = -1;
}

template <class T>
void stack<T>::push(const T &val){
    arratStack[++stackTop] = val;

}

#endif // STACK_H
