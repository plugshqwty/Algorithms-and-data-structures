///........................ Калечиц Александра, 5 группа 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
using namespace std;

int main() {
    FILE* inputFile = fopen("huffman.in", "r");
    long long n;
    fscanf(inputFile, "%lld", &n);
    vector<long long> mas1;
    long long key1;
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%lld", &key1);
        mas1.push_back(key1);
    }
    vector<long long> mas2(n-1);
   /* for (int i = 0; i < n; i++) {
        cout << mas1[i]<<" ";
    }*/
    fclose(inputFile);
    int k = 2;
    int m = 0;
    int c = 1;
    long long el = mas1[k - 2] + mas1[k - 1];
    mas2[0] = el;
    long long min1;
    long long min2;
    while (c < n - 1) {
        if (k < n) {
            if (m >= c) {
                min1 = mas1[k];
                k++;
            }
            else if (mas1[k] < mas2[m]) {
                min1 = mas1[k];
                k++;
            }
            else {
                min1 = mas2[m];
                m++;
            }
        }
        else {
            min1 = mas2[m];
            m++;
        }

        if (k < n) {
            if (m >= c) {
                min2 = mas1[k];
                k++;
            }
            else if (mas1[k] < mas2[m]) {
                min2 = mas1[k];
                k++;
            }
            else {
                min2 = mas2[m];
                m++;
            }
        }
        else {
            min2 = mas2[m];
            m++;
        }

        el = min1 + min2;
        mas2[c] = el;
        c++;
    }
   /* cout << endl;
    for (int i = 0; i < n-1; i++) {
       cout << mas2[i]<<" ";
    }*/
    long long sum = 0;
    for (int i = 0; i < n-1;i++) {
        sum =sum+ mas2[i]; 
    }
    //cout <<endl<< sum;
    FILE* outputFile = fopen("huffman.out", "w");
    fprintf(outputFile, "%lld\n", sum);
    fclose(outputFile);
    return 0;


}