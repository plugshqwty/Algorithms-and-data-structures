//............................... Калечиц Александра, 5 группа 
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	fstream inputFile("input.txt");
	vector<char> str;
	char c;
	while (inputFile >> c) {
		str.push_back(c);
	}

	/*for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;*/

	inputFile.close();
	int n = str.size();
	vector<vector<int>>matrix(n, vector<int>(n,0));

	if (n == 1) {
		//cout << 1<<endl;
		//cout << str[0];
		ofstream outputFile("output.txt");
		outputFile << 1 << endl;
		outputFile << str[0];
		outputFile.close();
		return 0;
	}
	if (n == 2) {
		for (int i = 0; i < n-1; i++) {
			if (str[i] == str[i + 1]) {
				matrix[i][i + 1] = 2;
			}
			else {
				matrix[i][i + 1] = 1;
		    }
		}
		ofstream outputFile("output.txt");
		
		if (str[0] == str[1]) {
			outputFile << 2 << endl;
			outputFile << str[0]<<str[1];
		}
		else {
			outputFile << 1 << endl;
			outputFile << str[0];
		}
		outputFile.close();
		return 0;
	}
	if (n > 2) {
		for (int i = 0; i < n; i++) {
			matrix[i][i] = 1;
		}
		for (int i = 0; i < n-1; i++) {
			if (str[i] == str[i + 1]) {
				matrix[i][i + 1] = 2;
			}
			else {
				matrix[i][i + 1] = 1;
			}
		}
		int k;
		for (int m = 0; m < n - 2; m++) {
			k = m + 2;
			for (int i = 0; i < n -(m+2); i++) {
				if (str[i] == str[k]) {
					matrix[i][k] = matrix[i + 1][k - 1] + 2;
				}
				else {
					matrix[i][k] = max(matrix[i + 1][k], matrix[i][k - 1]);
				}
				k++;
			}
		}

		
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j]<< " ";
		}
		cout << endl;
	}*/
	//cout << matrix[0][n - 1]<<endl;
	int count = matrix[0][n - 1];

	vector<char> ind1;
	int p = 0; 
	int r = n-1;
	while (p < n && r > 0) {
		if (str[p] == str[r]) {
			if (p > r) {
				break;
			}
			ind1.push_back(str[p]);
			
			p++;
			r--;
		}
		else {
			if (p > r) {
				break;
			}
			if (matrix[p + 1][r] == matrix[p][r]) {
				p++;
			}
			else {
				r--;
			}
		}
	}
	
	ofstream outputFile("output.txt");
	outputFile << count << endl;
	if (count % 2 == 0) {
		for (int i = 0; i < count / 2; i++) {
			outputFile << ind1[i];
		}
		for (int i = count / 2 - 1; i > -1; i--) {
			outputFile << ind1[i];
		}
	}
	if (count % 2 != 0)
	{
		for (int i = 0; i < count / 2 + 1; i++) {
			outputFile << ind1[i];
		}
		for (int i = count / 2 - 1; i > -1; i--) {
			outputFile << ind1[i];
		}
	}
	outputFile.close();
	return 0;

}