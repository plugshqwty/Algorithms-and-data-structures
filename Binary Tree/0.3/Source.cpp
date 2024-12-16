// ................................................    Калечиц Александра, 5 группа 
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>

using namespace std;

struct node {
    int key;
    int parent;
    char letter;
    int max;
    int min;
};

int main() {
    int plusInf =INT_MAX;
    int minusInf = INT_MIN;
   
    
    FILE* inputFile = fopen("bst.in", "r");
   // ifstream inputFile("bst.in");
    int n;
   // inputFile >> n;
    fscanf(inputFile, "%d", &n);
    vector<node> mas(n);
    int key1;
   // inputFile >> key1;
    fscanf(inputFile, "%d", &key1);
    mas[0] = { key1, -1, ' ', plusInf, minusInf };

    for (int i = 1; i < n; i++) {
        fscanf(inputFile, "%d %d %c", &mas[i].key, &mas[i].parent, &mas[i].letter);
    }
    fclose(inputFile);

    ///////////////////////////////////////////////////////////////////////////////////////////
       /* for (int i = 0; i < n; i++) {
            cout << mas[i].key << " " << mas[i].parent << " " << mas[i].letter << endl;
        }*/
     //////////////////////////////////////////////////////////////////////////////////////////


    FILE* outputFile = fopen("bst.out", "w");
   // int p = 0;
    for (int i = 1; i < n; i++) {
        int parent = mas[i].parent;
        if (mas[i].letter == 'L') {
            mas[i].min = mas[parent - 1].min;
            mas[i].max = mas[parent - 1].key-1;
            if (mas[i].key >= mas[parent - 1].key) {
                fprintf(outputFile, "NO");
                fclose(outputFile);
                return 0;
            }
            if (mas[i].key < mas[i].min || mas[i].key > mas[i].max) {
                fprintf(outputFile, "NO");
                fclose(outputFile);
                return 0;
            }
        }
        if (mas[i].letter == 'R') {
            mas[i].max = mas[parent - 1].max;
            mas[i].min = mas[parent - 1].key;
            if (mas[i].key < mas[parent - 1].key) {
                fprintf(outputFile, "NO");
                fclose(outputFile);
                return 0;
            }
            if (mas[i].key < mas[i].min || mas[i].key > mas[i].max) {
                fprintf(outputFile, "NO");
                fclose(outputFile);
                return 0;
            }
        }
    }
    fprintf(outputFile, "YES");
    fclose(outputFile);
    
    return 0;
}