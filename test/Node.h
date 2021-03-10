#ifndef NODE_H
#define NODE_H
template <class T>
struct Node{
    Node *next;
    Node *before;
    T val;
};
#endif // NODE_H
