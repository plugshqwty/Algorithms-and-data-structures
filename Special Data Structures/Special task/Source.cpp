
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstdio>

using namespace std;


struct TMem {
	int x;
	int y;
	int z;
};
bool comp(const TMem& a, const TMem& b) {
    return a.x < b.x; 
}


class Tree {
private:
    vector<int> A; 
    vector<int> T; 
    int n; 

    void Build(int v, int l, int r) {
        if (r - l == 1) {
            T[v] = A[l];
        }
        else {
            int k = (l + r) / 2;
            Build(2 * v, l, k);
            Build(2 * v + 1, k, r);
            T[v] = min(T[2 * v], T[2 * v + 1]);
        }
    }

    void Update(int v, int l, int r, int i, int x) {
        if (r - l == 1) {
            T[v] = x;
            A[i] = x;
        }
        else {
            int k = (l + r) / 2;
            if (i < k) {
                Update(2 * v, l, k, i, x);
            }
            else {
                Update(2 * v + 1, k, r, i, x);
            }
            T[v] = min(T[2 * v], T[2 * v + 1]);
        }
    }

    int Query(int v, int l, int r, int myL, int myR) {
        if (l == myL && r == myR) {
            return T[v];
        }
        int k = (l + r) / 2;
        if (myR <= k) {
            return Query(2 * v, l, k, myL, myR);
        }
        if (k <= myL) {
            return Query(2 * v + 1, k, r, myL, myR);
        }
        return min(Query(2 * v, l, k, myL, k), Query(2 * v + 1, k, r, k, myR));
    }

public:
    Tree(const vector<int>& data) : n(data.size()), A(data) {
        T.resize(4 * n, numeric_limits<int>::max());
        Build(1, 0, n);
    }

    void update(int i, int x) {
        Update(1, 0, n, i, x);
    }

    int query(int myL, int myR) {
        return Query(1, 0, n, myL, myR);
    }
};




int main(){
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");
    int n;
    fscanf(inputFile, "%d", &n);
   // cout << n << endl;
    vector<TMem>teams(n);
    vector<int>pl(3*n, 500000);
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d %d %d", &teams[i].x, &teams[i].y, &teams[i].z);
      
    }
    /*for (int i = 0; i < n; i++) {
        cout << teams[i].x << " " << teams[i].y << " " << teams[i].z << endl;
    }*/
    sort(teams.begin(), teams.end(), comp);
   /* cout << endl;
    for (int i = 0; i < pl.size(); i++) {
        cout << pl[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << teams[i].x << " " << teams[i].y << " " << teams[i].z << endl;
    }*/
    Tree segTree(pl);
    
    int counter = 0;
    for (int i = 0; i < n; i++) {
        segTree.update(teams[i].y - 1, teams[i].z);
        pl[teams[i].y - 1] = teams[i].z;
       /* cout << endl;
        for (int j = 0; j < pl.size(); j++) {
            cout << pl[j] << " ";
        }
        cout << endl;*/
        
        int min = segTree.query(0, teams[i].y-1);
       
     //   cout << min << " ";// << teams[i].z << endl;
        if (min > teams[i].z) {
           counter++;
        }
      
    }
   // cout << endl << endl << counter;


    fprintf(outputFile, "%d", counter);

    fclose(inputFile);
    fclose(outputFile);
    return 0;

}