#include "compress.h"

compress::compress(string filename,string zipname){
    this->fileName=filename;
    this->zipName = zipname;

}
void compress::generateHuffmanCode(huffmanNode *node,string str){
    node->huffcode+=str;
    if(node->left!=NULL){
        generateHuffmanCode(node->left,node->huffcode+"0");
    }

    if(node->right!=NULL){
        generateHuffmanCode(node->right,node->huffcode+"1");
    }
}

void compress::huffmanForEnglish(){
    ifstream fin(fileName, ios::binary);
    if (!fin) {
        cout << "file open error!" << endl;
        exit(1);
    }
    cout<<"compressing files "<<endl;
    int startTime = time(0);
    fstream fout(zipName + ".huffman", ios::binary);
    long fbeg = fin.tellg();

    fin.seekg(0, ios::end);
    long fend = fin.tellg();
    long filelength = fend - fbeg;

    fin.seekg(0, ios::beg);

    map<string, int> wordMap;
    char ch;
    string wordstr = "";
    string chstr = "";
    int wordsum = 0;
    for (long fp = fbeg; fp<fend; fp++)
    {
        fin.read(&ch, sizeof(char));
        //cout << ch;
        if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
            wordstr += ch;
        else {
            //cout << "字符：" << ch << endl;
            if (wordstr != "") {
                if (wordMap.find(wordstr) == wordMap.end())
                    wordMap[wordstr] = 1;
                else wordMap[wordstr]++;
                wordstr = "";
                wordsum++;
            }
            chstr = "";   //非字母类型入map
            chstr += ch;
            if (wordMap.find(chstr) == wordMap.end())
                wordMap[chstr] = 1;
            else wordMap[chstr]++;
            wordsum++;
        }
    }
    fin.close();
    //最后一个字符的处理
    if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')) //如果最后一个字符是字母
    {
        if (wordMap.find(wordstr) == wordMap.end())
            wordMap[wordstr] = 1;
        else wordMap[wordstr]++;
        wordstr = "";
        wordsum++;
    }

    fout.write((char*)&wordsum, sizeof(int)); //向压缩文件写入单词总数
    int wordNum = wordMap.size(); //获取单词种类
    fout.write((char*)&wordNum, sizeof(int));//向压缩文件写入单词种类数

    char spacech = ','; //分隔符
    //获取最小优先队列
    map<string, huffmanNode*> huffmanWordMap;
    map<string, int>::iterator iter;
    priority_queue<huffmanNode*, vector<huffmanNode*>, cmp> min_queue;
    for (iter = wordMap.begin(); iter != wordMap.end(); iter++)
    {
        huffmanNode *huffNode = new huffmanNode();
        huffNode->left = NULL; huffNode->right = NULL;
        huffNode->value = iter->first;
        huffNode->freque = iter->second;
        min_queue.push(huffNode);
        huffmanWordMap[huffNode->value] = huffNode;
        //cout << huffNode->value << " : " << huffNode->freq << endl;
        fout.write((char*)&huffNode->freque, sizeof(int)); //写入单词-频率对
        //fout.write((char*)&huffNode->value,huffNode->value.size());		//注意不能用sizeof(string)
        //fout.write(string)这种方式当字符串很长的时候也会发生乱码错误
        fout << huffNode->value;
        fout.write((char*)&spacech, sizeof(char));//写一个spacech作为分隔符

    }

    //构造哈夫曼树
    huffmanNode *node1, *node2, *root = NULL;
    for (int i = 0; i < wordNum - 1; i++) {	//n-1次
            huffmanNode *newNode = new huffmanNode();
            if (min_queue.size() == 2)	//为了避免每次循环都要判断，可以先循环处理n-2次，最后一次再单独处理
                root = newNode; //
            node1 = min_queue.top(); min_queue.pop();
            node2 = min_queue.top(); min_queue.pop();
            newNode->left = node1;
            newNode->right = node2;
            newNode->freque = node1->freque + node2->freque;

            min_queue.push(newNode);
        }
        if (root == NULL)
            return;
    generateHuffmanCode(root, ""); //生成各个字符的Huffman编码串
    //写入Huffman编码到压缩文件
    wordstr = "";
    int length = 8; char tempchar = 0;
    ifstream infile(fileName, ios::binary);
    string codestr;
    //while (!infile.eof())
    for (long fp = fbeg; fp<fend; fp++)
    {
        infile.read(&ch, sizeof(char));
        //cout << "字符："<<ch << endl;
        if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
            wordstr += ch;
        else {
            //cout << "字符：" << ch << endl;
            if (wordstr != ""){
                codestr = huffmanWordMap[wordstr]->huffcode;
                //cout << wordstr<<" : "<<codestr << endl;
                for (int i = 0; i < codestr.size(); i++) {
                    length--;
                    if (codestr[i] == '0')
                        tempchar = tempchar | (0 << length);
                    else tempchar = tempchar | (1 << length);
                    if (length == 0) {
                        fout.write(&tempchar, sizeof(char));
                        //写入Huffman编码串到压缩文件
                        //printCharToBin(tempchar);
                        length = 8;
                        tempchar = 0;
                    }
                }
                wordstr = "";
            }
            //非字母类型
            chstr = ""; chstr += ch;
            codestr = huffmanWordMap[chstr]->huffcode;
            for (int i = 0; i < codestr.size(); i++) {
                length--;
                if (codestr[i] == '0')
                    tempchar = tempchar | (0 << length);
                else tempchar = tempchar | (1 << length);
                if (length == 0) {
                    fout.write(&tempchar, sizeof(char));
                //	printCharToBin(tempchar);
                    //写入Huffman编码串到压缩文件
                    length = 8;
                    tempchar = 0;
                }
            }
        }
    }
    //如果最后一个字符是字母
    if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')) {
        codestr = huffmanWordMap[wordstr]->huffcode;
        for (int i = 0; i < codestr.size(); i++) {
            length--;
            if (codestr[i] == '0')
                tempchar = tempchar | (0 << length);
            else tempchar = tempchar | (1 << length);
            if (length == 0) {
                fout.write(&tempchar, sizeof(char));
                //写入Huffman编码串到压缩文件
                //printCharToBin(tempchar);
                length = 8;
                tempchar = 0;
            }
        }
    }
    if (length != 0) //最后一个字节的处理，防止写入压缩文件的时候长度未写满8位的倍数
    {
        //printCharToBin(tempchar);
        fout.write(&tempchar, sizeof(char));
    }
    int end = time(0);
    cout << "compress successfully" << endl;
    cout << "TIME: " << end - startTime << " s" << endl;
    //释放内存，清除Huffman树每个节点
    //destroy(root);
    infile.close();
    fout.close();

}
void compress::constructHuffmantree(huffmanNode *node1,huffmanNode *node2,huffmanNode *root,int wordNum,priority_queue<huffmanNode*, vector<huffmanNode*>, cmp> *min_queue){
    for (int i = 0; i < wordNum - 1; i++) {	//n-1次
            huffmanNode *newNode = new huffmanNode();
            if (min_queue->size() == 2)	//为了避免每次循环都要判断，可以先循环处理n-2次，最后一次再单独处理
                root = newNode; //
            node1 = min_queue->top(); min_queue->pop();
            node2 = min_queue->top(); min_queue->pop();
            newNode->left = node1;
            newNode->right = node2;
            newNode->freque = node1->freque + node2->freque;

            min_queue->push(newNode);
        }
}
