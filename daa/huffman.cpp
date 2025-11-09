#include<bits/stdc++.h>
using namespace std;

struct huffmanTree{
    char ch;
    int frequency;
    huffmanTree* left;
    huffmanTree* right;

    huffmanTree(char c, int f){
        left = nullptr;
        right = nullptr;
        ch=c;
        frequency=f;
    }
};

struct Compare{
    bool operator()(huffmanTree* left, huffmanTree* right){
        return left->frequency>right->frequency;
    }
};

void printTree(string str,huffmanTree* &root, map<char,string>& codes){
    
    if(!root->left && !root->right){
        codes[root->ch] = str;
        return;
    }
    printTree(str+'0',root->left,codes);
    printTree(str+'1',root->right,codes);
}

void buildHuffmanTree(string s){
    map<char,int> mp;
    for(auto i: s){
        mp[i]++;
    }

    priority_queue<huffmanTree*, vector<huffmanTree*>, Compare> pq;

    for(auto i: mp){
        huffmanTree* node = new huffmanTree(i.first,i.second);
        pq.push(node);
    }

    while(pq.size()>1){
        huffmanTree* leftNode = pq.top();
        pq.pop();
        huffmanTree* rightNode = pq.top();
        pq.pop();

        huffmanTree* newNode = new huffmanTree('0',leftNode->frequency + rightNode->frequency);
        newNode->left = leftNode;
        newNode->right = rightNode;

        pq.push(newNode);
    }

    huffmanTree* root = pq.top(); // root of the tree

    map<char,string> codes;

    printTree("",root,codes);

    cout<<"Encoded String is: "<<endl;
    for(auto i: s){
        cout<<codes[i]<<endl;
    }
    
}

int main(){
    string str;
    cin>>str;
    buildHuffmanTree(str);
}