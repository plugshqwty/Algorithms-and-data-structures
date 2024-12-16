//.....................................     Калечиц Александра, 5 группа 

#include <iostream>
#include <fstream>

using namespace std;

class TNode {
public:
    TNode(int key) {
        Key = key;
        Left = nullptr; 
        Right = nullptr; 
    }
    int Key;           
    TNode* Left;      
    TNode* Right;      
};

class TTree {
public:
    TTree() {
        Root = nullptr; 
    }

    ~TTree() {
        DestroyNode(Root);
    }

    void Insert(int x) {
        if (!Root) {
            Root = new TNode(x); 
            
        }
        else {
            InsertRecur(Root, x);
        }
        return;
    }

    void ObhodWrite(ofstream& outputFile) {
        ObhodRecur(Root, outputFile);
    }

private:
    void DestroyNode(TNode* node) {
        if (node) {
            DestroyNode(node->Left);
            DestroyNode(node->Right);
            delete node;
        }
    }

    void InsertRecur(TNode* node, int x) {
        if (x < node->Key) {
            if (node->Left) {
                InsertRecur(node->Left, x);
            }
            else {
                node->Left = new TNode(x); 
            }
        }
        else if (x > node->Key) {
            if (node->Right) {
                InsertRecur(node->Right, x);
            }
            else {
                node->Right = new TNode(x); 
            }
        }
       
    }

    void ObhodRecur(TNode* node, ofstream& outputFile) {
        if (node) {
            outputFile << node->Key << "\n"; 
            ObhodRecur(node->Left, outputFile);
            ObhodRecur(node->Right, outputFile);
        }
    }
    
private:
    TNode* Root; 
};

int main() {
    TTree tree;
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int key;
    while (inputFile >> key) {
        tree.Insert(key);
    }

    tree.ObhodWrite(outputFile);

    inputFile.close();
    outputFile.close();
    return 0;
}