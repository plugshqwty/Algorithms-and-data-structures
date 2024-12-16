//............................ Калечиц Александра, 5 группа 
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;

    long long** array = new long long* [n + 1]; 
    for (int i = 0; i <= n; ++i) {
        array[i] = new long long[i + 1]; 
    }


    for (int i = 0; i <= n; i++) {
        array[i][0] = 1; 
        array[i][i] = 1;
        for (int j = 1; j < i; j++) {
            array[i][j] = array[i - 1][j - 1] + array[i - 1][j] % MOD;
        }
    }
   /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
  
   cout << "result" << endl;*/

    cout << array[n][k] % MOD << endl;

    for (int i = 0; i <= n; ++i) {
        delete[] array[i]; 
    }
    delete[] array; 

    return 0;
}