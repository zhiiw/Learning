#ifndef CIRRCULARLINKEDLIST_H
#define CIRRCULARLINKEDLIST_H
#include <bits/stdc++.h>
template <class T>
struct Node{
    Node *next;
    int val;
};

template <class T>
class CirrcularLinkedList
{
public:
    Node<T> *head;
    int length;

public:
    CirrcularLinkedList();
    ~CirrcularLinkedList();
    void insert(Node<T> *x);
    void Delete(int k) ;
    int getValue() const;

    int Length(){return length;};
    void create(int count);// follow the input data to create k node;
    bool isEmpty();

};

template<class T>
CirrcularLinkedList<T>::CirrcularLinkedList(){
    head =new Node<T>;
    head->val =1;
    head->next=head;//initialize
    length=1;

}
template<class T>
bool CirrcularLinkedList<T>::isEmpty(){
    if(head->next==head){
        return true;
    }
    return false;//judge the empty
}
template<class T>
void CirrcularLinkedList<T>::create(int count){
    if (isEmpty()){
        if (count<=1){
            return;
        }

        Node<T> *lastnode =head;


        for(int i=2;i<=count;i++){

            Node<T>* node = new Node<T>;
            node->val=i;//create the number of node
            lastnode->next=node;
            node->next=head;
            lastnode=node;
            length++;

        }

    }
}

template<class T>
CirrcularLinkedList<T>::~CirrcularLinkedList(){
    Node<T> *p =head;
    Node<T> *temp =p;

    if(temp == nullptr|| temp->next=nullptr){
        return;
    }

    else{
        int length =Length();
        for (int i= 0; i<length;i++){
            p=temp;
            temp=temp->next;
            delete p;// deconstruct
            p=nullptr;
        }
    }



}
template<class T>
int CirrcularLinkedList<T>::getValue() const{
    return head->val;
}
template<class T>
void CirrcularLinkedList<T>::Delete(int k) {
    if (k < 0 || k > length) {

        return;
    }

    Node<T> *node =head;
    int e=0;
    while(node!=node->next){
        for(int i=0;i<k-1;i++){
            if(e==0){
                e++;
            }else{
                node = node->next;//go to the needed place
            }

        }

        Node<T> *nodeTemp=node->next;
        node->next=nodeTemp->next;
        std::cout<<nodeTemp->val<<std::endl;
        delete (nodeTemp);
        length--;
    }
    head=node;
}

#endif // CIRRCULARLINKEDLIST_H
