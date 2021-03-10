#ifndef CIRRCULARLINKEDLIST_H
#define CIRRCULARLINKEDLIST_H
#include "Node.h"
template <class T>
class CirrcularLinkedList
{
private:
    Node<T> *head;
    int length;

public:
    CirrcularLinkedList();
    ~CirrcularLinkedList();
    void Insert(Node<T> *x);
    void Delete(int k) const;
    int Length(){return length;};
    void Create(int count);// follow the input data to create k node;


};
template<class T>
CirrcularLinkedList<T>::CirrcularLinkedList(){
    head =nullptr;
    length=0;
}
template<class T>
void CirrcularLinkedList<T>::Create(int count){
    if (head==nullptr){
        if (count<=0){
            return;
        }
        head=(Node<T> *)new Node<T>;
        head->before=nullptr;
        head->next=nullptr;
        head->val=1;
        int j;
        for (j=2;j<=count;j++){
            head->before=head;
            head->next=nullptr;
            head->val=1;
        }

    }
}
template<class T>
CirrcularLinkedList<T>::~CirrcularLinkedList(){
    Node<T> *p =head;
    Node<T> *temp =p;

    if(temp = nullptr|| temp->next=nullptr){
        return;
    }

    else{
        int length =Length();
        for (int i= 0; i<length;i++){
            p=temp;
            temp=temp->next;
            delete p;
            p=nullptr;
        }
    }


}

template<class T>
void CirrcularLinkedList<T>::Delete(int k) const{
    if(k<=0||){
        return;

    for(int i=1;i=k;i++){

    }

}

#endif // CIRRCULARLINKEDLIST_H
