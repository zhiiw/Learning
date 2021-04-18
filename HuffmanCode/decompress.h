#ifndef DECOMPRESS_H
#define DECOMPRESS_H
#include<iostream>
#include<fstream>
#include<string>
#include "huffmanNode.h"
#include<queue>
#include<time.h>
#include<map>

class decompress
{
private:
    ifstream in;
    ofstream out;
    map<string, int> wordMap;
    string fileName;
    string zipName;
public:
    decompress()=default;
    decompress(string fileName );
    void unCompressHuffmanForEnglish();
    void generateHuffmanCode(huffmanNode *node,string str);
};

#endif // DECOMPRESS_H
