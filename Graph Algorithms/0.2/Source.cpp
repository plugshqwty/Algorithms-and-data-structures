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
	fscanf(inputFile, "%d", &n);
	int v1;
	int v2;
	vector<int> mas(n,0);
	for (int i = 0; i < n-1; i++) {
		fscanf(inputFile, "%d", &v1);
		fscanf(inputFile, "%d", &v2);
		mas[v2 - 1] = v1;
	}
	for (int i = 0; i < n; i++) {
		fprintf(outputFile, "%d ", mas[i]);
	}
}