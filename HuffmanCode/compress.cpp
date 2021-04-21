#include "compress.h"

compress::compress(string filename,string zipname,bool encryption,string x ){
    this->fileName=filename;
    this->zipName = zipname;
    this->encryption= encryption;
    this->password= x;
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
void compress::huffmanNormal(){
    ifstream in(fileName, ios::binary);
    if (!in) {
        cout << "file open error!" << endl;
        exit(1);
    }

    ofstream out(zipName+".huffman" , ios::binary);
    if (!out) {
        cout << "file open error!" << endl;
        exit(1);
    }
    long beginNumeber = in.tellg();

    in.seekg(0, ios::end);
    long endNumber = in.tellg();
    long filelength = endNumber - beginNumeber;

    in.seekg(0, ios::beg);

    map<string, int> wordMap;
    char temp;
    string wordstr = "";
    string tempstr = "";
    int wordsum = 0;
    for (long fp = beginNumeber; fp<endNumber; fp++)
    {
        in.read(&temp, sizeof(char));
        //cout << temp;

        tempstr = "";   //非字母类型入map
        tempstr += temp;
        if (wordMap.find(tempstr) == wordMap.end())
            wordMap[tempstr] = 1;
        else wordMap[tempstr]++;
        wordsum++;

    }
    in.close();
    //最后一个字符的处理
    if ((temp >= 'a'&&temp <= 'z') || (temp >= 'A'&&temp <= 'Z'))
    {
        if (wordMap.find(wordstr) == wordMap.end())
            wordMap[wordstr] = 1;
        else wordMap[wordstr]++;
        wordstr = "";
        wordsum++;
    }
    char spacetemp = ','; //space temp

    int size= password.length();
    out.write((char*)&size, sizeof(int));//write the password length
    if(encryption){
        out<<password;
        out.write((char*)&spacetemp, sizeof(char));
    }

    out.write((char*)&wordsum, sizeof(int)); //char sum

    int wordNum = wordMap.size();

    out.write((char*)&wordNum, sizeof(int));//char type sum


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
        out.write((char*)&huffNode->freque, sizeof(int));
        out.write((char*)&spacetemp, sizeof(char));

    }

    //construct huffman tree
    huffmanNode *node1, *node2, *root = NULL;
    for (int i = 0; i < wordNum - 1; i++) {	//n-1次
            huffmanNode *newNode = new huffmanNode();
            if (min_queue.size() == 2)
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
    generateHuffmanCode(root, "");
    wordstr = "";
    int length = 8; char tempchar = 0;
    ifstream infile(fileName, ios::binary);
    string codestr;
    for (long fp = beginNumeber; fp<endNumber; fp++)
    {
        infile.read(&temp, sizeof(char));


        tempstr = ""; tempstr += temp;
        codestr = huffmanWordMap[tempstr]->huffcode;
        for (int i = 0; i < codestr.size(); i++) {
            length--;
            if (codestr[i] == '0')
                tempchar = tempchar | (0 << length);
            else tempchar = tempchar | (1 << length);
            if (length == 0) {
                out.write(&tempchar, sizeof(char));
                length = 8;
                tempchar = 0;
            }
        }

    }

    if (length != 0)
    {

        out.write(&tempchar, sizeof(char));
    }
    cout << "compress successfully" << endl;

    infile.close();
    out.close();
}
void compress::huffmanForEnglish(){
    ifstream in(fileName, ios::binary);
    if (!in) {
        cout << "file open error!" << endl;
        exit(1);
    }

    int startTime = time(0);
    ofstream out(zipName+".huffman" , ios::binary);
    if (!out) {
        cout << "file open error!" << endl;
        exit(1);
    }
    long beginNumeber = in.tellg();

    in.seekg(0, ios::end);
    long endNumber = in.tellg();
    long filelength = endNumber - beginNumeber;

    in.seekg(0, ios::beg);

    map<string, int> wordMap;
    char temp;
    string wordstr = "";
    string tempstr = "";
    int wordsum = 0;
    for (long fp = beginNumeber; fp<endNumber; fp++)
    {
        in.read(&temp, sizeof(char));
                //cout << ch;
                if ((temp >= 'a'&&temp <= 'z') || (temp >= 'A'&&temp <= 'Z'))
                    wordstr += temp;
                else {
                    //cout << "字符：" << ch << endl;
                    if (wordstr != "") {
                        if (wordMap.find(wordstr) == wordMap.end())
                            wordMap[wordstr] = 1;
                        else wordMap[wordstr]++;
                        wordstr = "";
                        wordsum++;
                    }
                    tempstr = "";   //非字母类型入map
                    tempstr += temp;
                    if (wordMap.find(tempstr) == wordMap.end())
                        wordMap[tempstr] = 1;
                    else wordMap[tempstr]++;
                    wordsum++;
                }

    }
    in.close();
    //最后一个字符的处理
    if ((temp >= 'a'&&temp <= 'z') || (temp >= 'A'&&temp <= 'Z'))
    {
        if (wordMap.find(wordstr) == wordMap.end())
            wordMap[wordstr] = 1;
        else wordMap[wordstr]++;
        wordstr = "";
        wordsum++;
    }
    char spacetemp = ','; //分隔符

    int size= password.length();
    out.write((char*)&size, sizeof(int));//向压缩文件写入单词种类数
    if(encryption){
        out<<password;
        out.write((char*)&spacetemp, sizeof(char));//写一个spacetemp作为分隔符
    }

    out.write((char*)&wordsum, sizeof(int)); //向压缩文件写入单词总数
    int wordNum = wordMap.size(); //获取单词种类
    out.write((char*)&wordNum, sizeof(int));//向压缩文件写入单词种类数

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
        out.write((char*)&huffNode->freque, sizeof(int)); //写入单词-频率对

        out << huffNode->value;
        out.write((char*)&spacetemp, sizeof(char));//写一个spacetemp作为分隔符

    }
    //construct the huffman tree
    huffmanNode *node1, *node2, *root = NULL;
    for (int i = 0; i < wordNum - 1; i++) {	//n-1次
            huffmanNode *newNode = new huffmanNode();
            if (min_queue.size() == 2)	//to avoid juedge so do it n-2 ,do last one only
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
    //write it the zip file
    wordstr = "";
    int length = 8; char tempchar = 0;
    ifstream infile(fileName, ios::binary);
    string codestr;
    //while (!infile.eof())
    for (long fp = beginNumeber; fp<endNumber; fp++)
    {
        infile.read(&temp, sizeof(char));
        //cout << "字符："<<temp << endl;
        if ((temp >= 'a'&&temp <= 'z') || (temp >= 'A'&&temp <= 'Z'))
            wordstr += temp;
        else {
            //cout << "字符：" << temp << endl;
            if (wordstr != ""){
                codestr = huffmanWordMap[wordstr]->huffcode;
                //cout << wordstr<<" : "<<codestr << endl;
                for (int i = 0; i < codestr.size(); i++) {
                    length--;
                    if (codestr[i] == '0')
                        tempchar = tempchar | (0 << length);
                    else tempchar = tempchar | (1 << length);
                    if (length == 0) {
                        out.write(&tempchar, sizeof(char));
                        //写入Huffman编码串到压缩文件
                        //printcharToBin(tempchar);
                        length = 8;
                        tempchar = 0;
                    }
                }
                wordstr = "";
            }
            //非字母类型
            tempstr = ""; tempstr += temp;
            codestr = huffmanWordMap[tempstr]->huffcode;
            for (int i = 0; i < codestr.size(); i++) {
                length--;
                if (codestr[i] == '0')
                    tempchar = tempchar | (0 << length);
                else tempchar = tempchar | (1 << length);
                if (length == 0) {
                    out.write(&tempchar, sizeof(char));
                //	printcharToBin(tempchar);
                    //写入Huffman编码串到压缩文件
                    length = 8;
                    tempchar = 0;
                }
            }
        }
    }
    //如果最后一个字符是字母
    if ((temp >= 'a'&&temp <= 'z') || (temp >= 'A'&&temp <= 'Z')) {
        codestr = huffmanWordMap[wordstr]->huffcode;
        for (int i = 0; i < codestr.size(); i++) {
            length--;
            if (codestr[i] == '0')
                tempchar = tempchar | (0 << length);
            else tempchar = tempchar | (1 << length);
            if (length == 0) {
                out.write(&tempchar, sizeof(char));
                //写入Huffman编码串到压缩文件
                //printcharToBin(tempchar);
                length = 8;
                tempchar = 0;
            }
        }
    }
    if (length != 0) //最后一个字节的处理，防止写入压缩文件的时候长度未写满8位的倍数
    {
        //printcharToBin(tempchar);
        out.write(&tempchar, sizeof(char));
    }
    int end = time(0);
    cout << "compress successfully" << endl;
    cout << "TIME: " << end - startTime << " s" << endl;
    //释放内存，清除Huffman树每个节点
    //destroy(root);
    infile.close();
    out.close();

}
void compress::constructHuffmantree(huffmanNode *node1,huffmanNode *node2,huffmanNode *root,int wordNum,priority_queue<huffmanNode*, vector<huffmanNode*>, cmp> *min_queue){
    for (int i = 0; i < wordNum - 1; i++) {	//n-1次
            huffmanNode *newNode = new huffmanNode();
            if (min_queue->size() == 2)
                root = newNode; //
            node1 = min_queue->top(); min_queue->pop();
            node2 = min_queue->top(); min_queue->pop();
            newNode->left = node1;
            newNode->right = node2;
            newNode->freque = node1->freque + node2->freque;

            min_queue->push(newNode);
        }

}

