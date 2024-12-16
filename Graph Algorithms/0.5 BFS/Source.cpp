#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

   
    int n;
    fscanf(inputFile, "%d", &n);

    vector<vector<int>> svList(n);
    vector<int> labels(n, 0); // Метки вершин
    int labelCounter = 1;

    int x;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fscanf(inputFile, "%d", &x);
            if (x != 0) {
                svList[i].push_back(j+1);
            }
        }
    }
  /*  
    for (int i = 0; i < n; i++) {
        cout << i + 1<<" ";
        for (int j = 0; j < svList[i].size(); j++) {
            cout<<svList[i][j]<< " ";
        }
        cout << endl;
    }*/

    vector<int> met(n, 0);
    int metCounter = 1;

    queue<int> q;

 
    for (int j = 0; j < n; j++) {
        if (met[j] != 0) continue;

        q.push(j+1);
        met[j] = metCounter;
        metCounter;
        metCounter++;


        while (!q.empty()) {
            int y = q.front();
            q.pop();

            for (int i = 0; i < svList[y - 1].size(); ++i) {
                int neig = svList[y - 1][i]; 
                if (met[neig - 1] == 0) {         
                    met[neig - 1] = metCounter;
                    metCounter++;
                    q.push(neig);                
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        fprintf(outputFile, "%d ", met[i]);
    }
    fprintf(outputFile, "\n");

   
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
