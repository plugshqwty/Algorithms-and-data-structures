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
	vector<int> mas(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(inputFile, "%d", &v1);
			if (v1 != 0) {
				mas[j] = i+1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		fprintf(outputFile, "%d ", mas[i]);
	}
}