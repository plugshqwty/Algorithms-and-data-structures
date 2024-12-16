//...................................    Калечиц Александра, 5 группа 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class TNode {
public:
    TNode(int key) {
        Key = key;
        Left = nullptr;
        Right = nullptr;
        Height = 0;
    }
    int Key;
    TNode* Left;
    TNode* Right;
    int Height;
    int Depth;
    int Level;
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
    }

    void ObhodWrite(ofstream& outputFile) {
        ObhodRecur(Root, outputFile);
    }
    void SetHeights() {
        if (Root) {
            SetHeights(Root);
        }
    }

    void SetHeights(TNode* node) {
        if (!node) return;

        SetHeights(node->Left);
        SetHeights(node->Right);

        if (!node->Left && !node->Right) {
            node->Height = 0; // Листья имеют высоту 0
        }
        else {
            int leftHeight;
            if (node->Left) {
                leftHeight = node->Left->Height; 
            }
            else {
                leftHeight = -1; 
            }
            int rightHeight;
            if (node->Right) {
                rightHeight = node->Right->Height; 
            }
            else {
                rightHeight = -1; 
            }
            node->Height = 1 + max(leftHeight, rightHeight); 
        }
    }
    void SetDepths() {
        if (Root) {
            SetDepths(Root, 0);
        }
    }

    void SetDepths(TNode* node, int currentDepth) {
        if (!node) return;

        node->Depth = currentDepth; 
        node->Level = Root->Height - node->Depth;
       // cout << node->Key << "  " << node->Level << endl;
        SetDepths(node->Left, currentDepth + 1);
        SetDepths(node->Right, currentDepth + 1);
        
    }

    void DeleteSred() {

        int h = Root->Height;
      //  cout << h;
        int level = h / 2;
        vector<TNode*> onLevel;

        FindOnLevel(Root, level, onLevel);

        vector<TNode*> candidates; /// у котор левых детей больше правых
        for (size_t i = 0; i < onLevel.size(); ++i) {
            TNode* node = onLevel[i];

            if (CountChildren(node->Left) > CountChildren(node->Right)) {
                candidates.push_back(node);
               // cout << " CANDIDATS " << node->Key << " ";
            }
        }

        if (candidates.size() % 2 == 0) {
            return;

        }
        else {
            if (!candidates.empty()) {
                sort(candidates.begin(), candidates.end(), CompareNodes);
                int middleKey = candidates[candidates.size() / 2]->Key;
                Root = DeleteRecur(Root, middleKey);
            }
        }
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
        if (!node) return nullptr;
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
        else {
            return node;
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

    int CountChildren(TNode* node) { // дети с корнем
        if (!node) return 0;
        return 1 + CountChildren(node->Left) + CountChildren(node->Right);
    }

    void FindOnLevel(TNode* node, int level, vector<TNode*>& onLevel) {
        if (!node) {
            return;
        }
        if (node->Level == level) {
            onLevel.push_back(node);
          //  cout <<" ONLEVEL "<< node->Key << " ";
        }
        FindOnLevel(node->Left,level, onLevel);
        FindOnLevel(node->Right, level, onLevel);
    }

    static bool CompareNodes(TNode* a, TNode* b) {
        if (a->Key < b->Key) {
            return true;
        }
        else {
            return false;
        }
       

    }

private:
    TNode* Root;
};

int main() {
    TTree tree;
    ifstream inputFile("in.txt");
    int key;
    if (inputFile.peek() == ifstream::traits_type::eof()) {
        ofstream outputFile("out.txt");
        inputFile.close();
        outputFile.close();
        return 0;
    }
    while (inputFile >> key) {
        tree.Insert(key);
    }
    tree.SetHeights();
    tree.SetDepths();
    inputFile.close();
    tree.DeleteSred();
    ofstream outputFile("out.txt");
    tree.ObhodWrite(outputFile);
    outputFile.close();

    return 0;
}