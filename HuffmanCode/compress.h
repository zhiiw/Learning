#ifndef COMPRESS_H
#define COMPRESS_H

#include<iostream>
#include<fstream>
#include<string>
#include "huffmanNode.h"
#include<queue>
#include<time.h>
#include<map>
using namespace std;
class compress
{
private:
    ifstream in;
    ofstream out;
    map<string, int> wordMap;
    string fileName;
    string zipName;
    bool encryption;
    string password;
public:
    compress()=default;
    compress(string fileName , string zipName,bool encryption,string password);
    ~compress();
    void generateHuffmanCode(huffmanNode *node,string str);
    void huffmanForEnglish();
    void constructHuffmantree(huffmanNode *node1,huffmanNode *node2,huffmanNode *root,int wordNum,priority_queue<huffmanNode*, vector<huffmanNode*>, cmp> *min_queue);
    void unCompressHuffmanForEnglish();

};

#endif // COMPRESS_H
