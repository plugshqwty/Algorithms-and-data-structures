#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void DFS(int v, const vector<vector<int>>& svList, vector<bool>& visited, vector<int>& met, int& metCounter) {
    visited[v] = true;
    met[v] = metCounter++;

    
    for (size_t i = 0; i < svList[v].size(); ++i) {
        int u = svList[v][i] - 1; 
        if (!visited[u]) {
            DFS(u, svList, visited, met, metCounter);
        }
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    int n;
    fscanf(inputFile, "%d", &n);

    vector<vector<int>> svList(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            fscanf(inputFile, "%d", &x);
            if (x != 0) {
                svList[i].push_back(j + 1); 
            }
        }
    }


    vector<int> met(n, 0);
    int metCounter = 1;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            DFS(i, svList, visited, met, metCounter);
        }
    }


    for (int i = 0; i < n; ++i) {
        fprintf(outputFile, "%d ", met[i]);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}