//................... Калечиц Александра, 5 группа 
#include <iostream>
#include <vector>

using namespace std;

bool BinarySearch(const vector<int>& a, int x) {
    int q = 0;
    int r = a.size();

    while (q < r) {
        int k = (q + r) / 2;
        if (x == a[k]) {
            return true;
        }
        else if (x < a[k]) {
            r = k;
        }
        else {
            q = k + 1;
        }
    }
    return false;
}

int LowerBound(const vector<int>& a, int x) {
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

int UpperBound(const vector<int>& a, int x) {
    int q = 0;
    int r = a.size();
    while (q < r) {
        int k = (q + r) / 2;
        if (x < a[k]) {
            r = k;
        }
        else {
            q = k + 1;
        }
    }
    return q;
}

int main() {

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    vector<int> queries(k);
    for (int i = 0; i < k; ++i) {
        cin >> queries[i];
    }

    for (int x : queries) {
        bool found = BinarySearch(a, x);
        int l = LowerBound(a, x);
        int r = UpperBound(a, x);
        cout << (found ? 1 : 0) << " " << l << " " << r << endl;
    }

    return 0;
}