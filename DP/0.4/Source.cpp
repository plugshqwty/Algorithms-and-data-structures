//.............................. Калечиц Александра, 5 группа 
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ifstream inputFile("input.txt");
	int count;
	inputFile >> count;
	vector<int> rows(count);
	vector<int> column(count);
	for (int i = 0; i < count; i++) {
		inputFile >> rows[i] >> column[i];
	}
	inputFile.close();
	vector<vector<int>>matrix(count, vector<int>(count,-1));
	
	for (int i = 0; i < count - 1; i++) {
		matrix[i][i+1] = rows[i] * column[i] * column[i+1];
	}
	for (int i = 0; i < count; i++) {
		matrix[i][i] = 0;
	}
	int infinity = numeric_limits<int>::max();
	for (int length = 3; length <= count; length++) {
		for (int i = 0; i <= count - length; i++) {
			int j = i + length - 1; 
			matrix[i][j] = infinity; //устремили якобы к +бесконечность 

			for (int k = i; k < j; k++) {
				int cost = matrix[i][k] + matrix[k + 1][j] + rows[i] * column[k] * column[j];
				matrix[i][j] = min(matrix[i][j], cost);
			}
		}
	}
	ofstream outputFile("output.txt");
	outputFile << matrix[0][count - 1];
	outputFile.close();

	return 0;
}
