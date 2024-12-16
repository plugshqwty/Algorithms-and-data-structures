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

    void Delete(int x) {
        Root = DeleteRecur(Root, x);

    }

private:
    void DestroyNode(TNode* node) {
        if (node) {
            DestroyNode(node->Left);
            DestroyNode(node->Right);
            delete node;
        }
    }

    TNode* DeleteRecur(TNode* node, int x) {
        if (!node) {
            return 0;
        }
        if (x < node->Key) {
            node->Left = DeleteRecur(node->Left, x);
            return node;
        }
        else if (x > node->Key) {
            node->Right = DeleteRecur(node->Right, x);
            return node;
        }
        if (!node->Left) {
            return node->Right;
        }
        else if (!node->Right) {
            return node->Left;
        }
        else {
            int min_key = FindMin(node->Right)->Key;
            node->Key = min_key;
            node->Right = DeleteRecur(node->Right, min_key);
        }
        return node;
    }
    
    TNode* FindMin(TNode* node) {
        if (node->Left) {
            return FindMin(node->Left);
        }
        else { return node; 
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
    int n;
    ifstream inputFile("input.txt");
    inputFile >> n;
    int key;
    while (inputFile >> key) {
        tree.Insert(key);
    }

    ofstream outputFile("output.txt");
    tree.Delete(n);
    tree.ObhodWrite(outputFile);
    outputFile.close();

    return 0;

}