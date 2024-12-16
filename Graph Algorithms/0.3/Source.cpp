#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>

using namespace std;

int main() {
	FILE* inputFile = fopen("input.txt", "r");
	FILE* outputFile = fopen("output.txt", "w");
	int n;
	int m;
	fscanf(inputFile, "%d", &n);
	fscanf(inputFile, "%d", &m);
	int v1;
	int v2;
	vector<int> mas(n, 0);
	vector<vector<int>> sv(n);
	for (int i = 0; i < m; i++) {
		fscanf(inputFile, "%d", &v1);
		fscanf(inputFile, "%d", &v2);
		sv[v1 - 1].push_back(v2);
		sv[v2 - 1].push_back(v1);
		mas[v1 - 1]++;
		mas[v2 - 1]++;
	}
	for (int i = 0; i < n; i++) { 
		fprintf(outputFile, "%d ", mas[i]); 
		for (int j = 0; j < sv[i].size(); j++) {
			fprintf(outputFile, "%d ", sv[i][j]);
		}
		fprintf(outputFile, "\n"); 
	}

}