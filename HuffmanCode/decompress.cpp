#include "decompress.h"

decompress::decompress(string filename)
{
    this->fileName=filename;

}
void decompress::generateHuffmanCode(huffmanNode *node,string str){
    node->huffcode+=str;
    if(node->left!=NULL){
        generateHuffmanCode(node->left,node->huffcode+"0");
    }

    if(node->right!=NULL){
        generateHuffmanCode(node->right,node->huffcode+"1");
    }
}

void decompress::unCompressHuffmanForEnglish(){
    cout << "正在解压……" << endl;
        int start = time(0);
        ifstream fin(fileName, ios::binary);
        ofstream fout(fileName + ".unzip", ios::binary);
        long fbeg, fend;
        fbeg = fin.tellg();
        int wordsum = 0;
        fin.read((char*)&wordsum, sizeof(int));
        int wordNum = 0;
        fin.read((char*)&wordNum, sizeof(int));
        string wordstr; int freq; char ch; int spaceflag = 0;
        //最小优先队列 priority_queue
        priority_queue<huffmanNode*, vector<huffmanNode*>, cmp> min_queue;
        for (int i = 0; i < wordNum; i++)
        {
            fin.read((char*)&freq, sizeof(int));
            wordstr = "";
            spaceflag = 0;
            while (true)
            {
                fin.read(&ch, sizeof(char));
                if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')) {
                    wordstr += ch;
                }
                else {
                    if (wordstr == "") {
                        wordstr += ch;
                        continue;
                    }
                    if (wordstr != ""&&ch == ',') //读到分隔符（逗号）//
                        break;
                }
            }
            //cout << wordstr << " : " << freq << endl;
            huffmanNode *huffnode = new huffmanNode();
            huffnode->left = NULL; huffnode->right = NULL;
            huffnode->value = wordstr;
            huffnode->freque = freq;
            //入队列
            min_queue.push(huffnode);
        }

        fend = fin.tellg();
        cout << "哈夫曼树大小：" << (fend - fbeg)*1.0 / 1024 << "kB" << endl;
        fbeg = fend;
        fin.seekg(0, ios::end);
        fend = fin.tellg();
        fin.seekg(fbeg, ios::beg);
        cout << "Huffman编码大小：" << (fend - fbeg)*1.0 / 1024 << "kB" << endl;

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
        generateHuffmanCode(root, "");
        //printLeaf(root);
        //开始解码
        char tempchar = 0;
        huffmanNode *tempNode = root;
        while (!fin.eof())
        {
            fin.read(&ch, sizeof(char));
            for (int i = sizeof(char)* 8 - 1; i >= 0; i--)
            {
                if (tempNode->left != NULL)
                {
                    if ((ch >> i) & 1)
                        tempNode = tempNode->right;
                    else tempNode = tempNode->left;
                }
                if (tempNode->left == NULL) //找到叶节点则将单词写入文件
                {
                    if (wordsum == 0)
                        break;
                    wordsum--;
                    wordstr = tempNode->value;
                    fout << wordstr;
                    //cout <<wordstr;
                    tempNode = root; //将tempNode重新指向根节点
                }

            }
        }

        int end = time(0);
        cout << "解压完成！" << endl;
        cout << "用时 " << end - start << " 秒" << endl;
        //释放内存，释放Huffman树的每一个节点内存
        //destroy(root);
        fin.close();
        fout.close();
}
