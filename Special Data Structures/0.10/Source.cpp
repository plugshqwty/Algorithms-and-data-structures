#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
#include <set>

using namespace std;

struct HashT {
    int key;
    int hvalue;
    
};

int HashF(int x, int i, int m, int c) {
    int res;
    res = ((x % m) + c * i) % m;
    return res;
}
int main() {
    setlocale(LC_ALL, "rus");
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");
    int m, c,n;
    fscanf(inputFile, "%d", &m);
    fscanf(inputFile, "%d", &c);
    fscanf(inputFile, "%d", &n);
    //cout << m << " " << c <<" " << n << endl;
    int a;
    vector<HashT>keys;
    for (int i = 0; i < n; i ++) {
        fscanf(inputFile, "%d", &a);
        HashT ob;
        ob.key = a;
        bool isDuplicate = false;
        for (int j = 0; j < keys.size(); j++) {
            if (keys[j].key == a) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            keys.push_back(ob);
        }
    }
   /* for (int i = 0; i < keys.size(); i++) {
        cout << keys[i].key << " ";
    }*/
    //cout << endl << endl;
    int d = keys.size();
    vector<int> index(m, 0);
    int q = 0;
    int w = 0;
    int r;
    while (q<keys.size()) {
       r = HashF(keys[q].key, w, m, c);
       if (index[r] == 0) {
           keys[q].hvalue = r;
           index[r] = 1;
           q++;
           w = 0;
           continue;
       }
       else {
           w++;
           continue;
       }
    }
    /*for (int i = 0; i < keys.size(); i++) {
        cout << keys[i].key << " "<< keys[i].hvalue<<endl;
    }*/
    vector<int>result(m,-1);
    for (int i = 0; i < d; i++) {
        result[keys[i].hvalue] = keys[i].key;
    }
    //cout << endl << endl;
    for (int i = 0; i < m; i++) {
      //  cout << result[i] << " ";
        fprintf(outputFile, "%d ", result[i]);
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
   
   

}