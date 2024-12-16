//......................... Калечиц Александра, 5 группа 
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int LowerBound(const vector<int>& a, int x) { // возвр поз куда можно поставит этот эл в отсорт мас 
    int q = 0;
    int r = a.size();
    while (q < r) {
        int k = (q + r) / 2;
        if (x <= a[k]) {
            r = k; 
        }
        else {
            q = k + 1;
        }
    }
    return q; 
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        input >> A[i];
    }

    vector<int> lis;

    for (int i = 0; i < n; ++i) {
        int pos = LowerBound(lis, A[i]);
        if (pos == lis.size()) {
            lis.push_back(A[i]);
        }
        else {
            lis[pos] = A[i]; 
        }
    }

    output << lis.size() << endl;

    input.close();
    output.close();

    return 0;
}
