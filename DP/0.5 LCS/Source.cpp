//................................ Калечиц Александра, 5 группа
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	vector<vector<int>>matrix(n+1, vector<int>(n+1,-1));

	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < n+1; j++) {
			matrix[i][0] = 0;
			matrix[0][j] = 0;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (a[i-1] == b[j-1]) {
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			}
			if(a[i-1] != b[j-1]){
				matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
			}
		}
		
	}
	/*
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}*/
	int count = matrix[n][n];
	cout << count << endl;
	vector<int> ind1;
	vector<int> ind2;
	int k = n;
	int m = n;
	while (k > 0 && m > 0) {
		if (a[k - 1] == b[m - 1]) {
			ind1.push_back(k - 1);
			ind2.push_back(m - 1);
			if (k == 1 && m == 1) {
				break;
			}
			k--;
			m--;
			
		}
		else {
			if (matrix[k - 1][m] == matrix[k][m]) {
				k--;
			}else {
				m--;
			}
		

		}
	}
	for (int i = count-1; i>-1; i--) {
		cout << ind1[i] << " ";
	}
	cout << endl;
	for (int i = count - 1; i > -1; i--) {
		cout << ind2[i] << " ";
	}
	
	
}