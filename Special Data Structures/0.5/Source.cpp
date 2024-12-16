#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
using namespace std;

class DSU {
public:
    DSU(int n) {
        mas.resize(n, -1);
        c = n;
    }

    int FindSet(int x) {
        //cout << " Ðåêóðñèÿ!!! äëÿ "<< x << endl;
        if (mas[x] < 0) {
            //cout << " íàéäåí ëèäåð  "<< x << endl;
            return x;
        }
       // cout << " ÍÅ ËÈÄÅÐ  " << x << endl;
        mas[x] = FindSet(mas[x]);
        return mas[x];
    }

    int Union(int u, int v) {
        int lid1 = FindSet(u);
        int lid2 = FindSet(v);
       // cout << " ÂÛÂÎÄ ÏÎÑËÅ ÐÅÊÓÐ" << endl;
       // Print();

        if (lid1 == lid2) {
            return c;
        }

        int count1 = -mas[lid1];
        int count2 = -mas[lid2];

        if (count1 <= count2) {
            mas[lid1] = lid2; 
            mas[lid2] = mas[lid2]-count1;
        }
        else {
            mas[lid2] = lid1; 
            mas[lid1] = mas[lid1]- count2; 
        }

        c=c-1; 
        return c;
    }

    void Print() {
        cout << endl;
        for (int i = 0; i < mas.size(); i++) {
            cout << mas[i] << " ";
        }
        cout << endl;
    }

private:
    vector<int> mas; 
    int c; 
};

int main() {
    setlocale(LC_ALL, "rus");
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");
    int n, q;
    fscanf(inputFile, "%d", &n);
    fscanf(inputFile, "%d", &q);
    //cout << n << " " << q << endl;

    DSU mnozh(n);
    int c;
    for (int i = 0; i < q; i++) {
        int u, v;
        fscanf(inputFile, "%d %d", &u, &v);
        u = u - 1; 
        v = v - 1;
        c = mnozh.Union(u, v);
        fprintf(outputFile, "%d\n", c);
        mnozh.Print();
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}