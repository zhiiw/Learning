#ifndef STACK_H
#define STACK_H
#include <sstream>
#include <iostream>
using namespace std;
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
    void show();

    void deleteAll()const {stackTop==-1;}
    int size()const {return stackTop+1;}
    bool isEmpty();
    T& top(){
        if(stackTop==-1){

        }
        return arratStack[stackTop];
    }
    int find(string str);
    int find(int count);

    stack();
    ~stack() {delete [] arratStack;}
    int count;
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


template<class T>
int stack<T>::find(string str)
{
    int x=0,y=0;
    for(int i= 0;i<=stackTop;i++){
        if(arratStack[i]==str){
            x++;
        }
    }

    for(int i= 0;i<=stackTop;i++){

        if(arratStack[i]==str){
            y++;
        }
        if(x==y&&x!=NULL){
            return i;
        }
    }

    return -1;
}
template<class T>
int stack<T>::find(int count)
{
    int x=0,y=0;
    for(int i= 0;i<=stackTop;i++){
        if(arratStack[i]==count){
            x++;
        }
    }

    for(int i= 0;i<=stackTop;i++){

        if(arratStack[i]==count){
            y++;
        }
        if(x==y){
            return i;
        }
    }

    return -1;
}
template<class T>
void stack<T>::show()
{
    for(int i= 0;i<=stackTop;i++){
        cout<<arratStack[i]<<" ";
    }
    cout<<endl;
}
#endif // STACK_H
