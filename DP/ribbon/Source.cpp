//.........................      Калечиц Александра, 5 группа
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	fstream inputFile("input.txt");
	int n;
	int c;
	vector<int> arr;

	inputFile >> n;
	while (inputFile >> c) {
		arr.push_back(c);
	}
	inputFile.close();
	
	vector<int> prefsum(n+1,0);
	vector<vector<int>>matrix(n, vector<int>(n));
	
	for (int i = 1; i < n+1; i++) { //преф сум
		prefsum[i] = prefsum[i - 1] + arr[i - 1];
	}
	/*for (int i = 0; i < n + 1; i++) {
		cout << prefsum[i] << " ";
	}*/
	//cout << endl;
	for (int i = 0; i < n; i++) {
		matrix[i][i] = arr[i];
	}
	for (int length = 2; length <= n; length++) {
		for (int i = 0; i <= n - length; i++) {
			int j = i + length - 1;
			matrix[i][j] = max(arr[i] + (prefsum[j + 1] - prefsum[i + 1] - matrix[i + 1][j]), arr[j] + (prefsum[j] - prefsum[i] - matrix[i][j - 1]));
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n;j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << matrix[0][n - 1];*/

	ofstream outputFile("output.txt");
	outputFile << matrix[0][n - 1];

	outputFile.close();
	return 0;

}

