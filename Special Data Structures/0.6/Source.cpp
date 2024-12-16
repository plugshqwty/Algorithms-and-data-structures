
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>

using namespace std;

struct Road {
    int start;
    int end;
    int number;
};
class DSU {
public:


    DSU(int n, int q) {
        mas.resize(n, -1);
        c = n;
    }

    int FindSet(int x) {
        if (mas[x] < 0) {
            return x;
        }
        mas[x] = FindSet(mas[x]);
        return mas[x];
    }

    int Union(int u, int v) {
        int lid1 = FindSet(u);
        int lid2 = FindSet(v);
        int i = 0;
        if (lid1 == lid2) {
            return c;
        }

        int count1 = -mas[lid1];
        int count2 = -mas[lid2];

        if (count1 <= count2) {
            mas[lid1] = lid2;
            mas[lid2] = mas[lid2] - count1;
        }
        else {
            mas[lid2] = lid1;
            mas[lid1] = mas[lid1] - count2;
        }

        c = c - 1;

        return c;
    }

    void Print() {
        cout << endl;
        for (int i = 0; i < mas.size(); i++) {
            cout << mas[i] << " ";
        }
        cout << endl;
    }
    int getC() {
        return c;
    }

private:
    vector<int> mas;
    int c;
};


using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");
    int n, m, q;
    fscanf(inputFile, "%d", &n);
    fscanf(inputFile, "%d", &m);
    fscanf(inputFile, "%d", &q);
    //cout << n << " " << m <<" " << q << endl;
    vector<Road> roads(m);
    for (int i = 0; i < m; i++) {
        fscanf(inputFile, "%d %d", &roads[i].start, &roads[i].end);
        roads[i].number = i + 1;
    }
    /*for (int i = 0; i < m; i++) {
        cout << roads[i].start << " " << roads[i].end << " " << roads[i].number << endl;
    }*/
    vector<int> dest(q);
    for (int i = q - 1; i > -1; i--) {
        fscanf(inputFile, "%d", &dest[i]);
    }
    /* for (int i = 0; i < q; i++) {
         cout << dest[i]<< endl;
     }*/
    vector<int>result(q);
    result[0] = 0;
    DSU mnozh(n, q);
    vector<bool>DestOrNot(m, false);
    for (int i = 0; i < q; i++) {
        DestOrNot[dest[i] - 1] = true;
        cout << dest[i] - 1 << endl;
    }
    for (int i = 0; i < m; i++) {
        cout << DestOrNot[i] << endl;
        if (DestOrNot[i] == false) {
            mnozh.Union(roads[i].start - 1, roads[i].end - 1);
        }
    }
    if (mnozh.getC() <= 1) {
        result[0] = 1;
    }
    if (mnozh.getC() > 1 ) {
        result[0] = 0;
    }
    int c;
    for (int i = 0; i < q; i++) {
        int u, v;
        u = roads[dest[i] - 1].start - 1;
        v = roads[dest[i] - 1].end - 1;
        mnozh.Union(u, v);
        //cout << c<<endl;
        if (mnozh.getC() <= 1&&i<q-1) {
            result[i+1] = 1; 
        }
        if (mnozh.getC() > 1 && i < q - 1) {
            result[i+1] = 0; 
        }
        //fprintf(outputFile, "%d\n", c);
       // mnozh.Print();
    }
    for (int i = q - 1; i > -1; i--) {
        //cout << result[i];
        fprintf(outputFile, "%d", result[i]);
    }


    fclose(inputFile);
    fclose(outputFile);
    return 0;
}


