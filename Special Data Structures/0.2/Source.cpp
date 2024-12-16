#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
using namespace std;

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    int n;
    fscanf(inputFile, "%d", &n);
    vector<long long> mas(n);
    long long key1;
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%lld", &key1);
        mas[i]=key1;
    }
    fclose(inputFile);

    int i = 0;
    long long sonL;
    long long sonR;
    FILE* outputFile = fopen("output.txt", "w");
    while (2*i + 2 < n) {
        sonL = mas[2 * i + 1];
        sonR= mas[2 * i + 2];
        if (mas[i] > sonR) {
            fprintf(outputFile, "No");
            fclose(outputFile);
            return 0;
        }
        if (mas[i] > sonL) {
            fprintf(outputFile, "No");
            fclose(outputFile);
            return 0;
        }
        i++;
    }
    if (2 * i + 1 < n) {
        sonL = mas[2 * i + 1];
        if (mas[i] > sonL) {
            fprintf(outputFile, "No");
            fclose(outputFile);
            return 0;
        }
        else {
            fprintf(outputFile, "Yes");
            fclose(outputFile);
            return 0;
        }
    }
    else {
        fprintf(outputFile, "Yes");
        fclose(outputFile);
        return 0;
    }

     
    

}
