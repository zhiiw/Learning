#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <string>
using namespace std;

class huffmanNode{
public:
    huffmanNode *left;
    huffmanNode *right;
    string value;
    int freque;//频率
    string huffcode;

};

struct cmp {
    cmp() {}
    bool operator()(const huffmanNode *node1, const huffmanNode *node2)const {
            return node1->freque > node2->freque;//根据字符频率最小值优先
    }
};
#endif // HUFFMANNODE_H
