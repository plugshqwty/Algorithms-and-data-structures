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
	vector<vector<int>>matrix(n, vector<int>(n,0));
	for (int i = 0; i < m; i++) {
		fscanf(inputFile, "%d", &v1);
		fscanf(inputFile, "%d", &v2);
		matrix[v1-1][v2-1] = 1;
		matrix[v2-1][v1-1] = 1;

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0;j < n; j++) {
			fprintf(outputFile, "%d ", matrix[i][j]);
		}
		fprintf(outputFile, "\n");
	}


}