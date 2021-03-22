#ifndef STACK_H
#define STACK_H
template <class T>
class stack{
public:
    friend void push(T val);
    friend T pop();
    void guiLing();
    friend int Length();
    bool isEmpty();
    stack();
    ~stack();
    int count;
private:
    T x[];
    int length;
};

template <class T>
stack<T>::stack(){
    length=0;
    T x[] =new T[1024];
}
template <class T>
void stack<T>::guiLing(T val){
    length=0;
}
template <class T>
T stack<T>::pop(){
    if(isEmpty()){
        return nullptr;
    }
    else{
        T value = x[length];

        length--;
        return value;
    }
}
template <class T>
void stack<T>::push(T val){
    if((x[length]=='+'||x[length]=='-'||x[length]=='x'||x[length]=='÷')&&(val=='+'||val=='-'||val=='x'||val=='÷'))
    x[length]=val;
    length++;
}
template <class T>
int stack<T>::Length(){

    return length;
}
#endif // STACK_H
