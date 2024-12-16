//................................ Калечиц Александра, 5 группа
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long modPow(long long a, long long b, long long m) {
    if (b == 0) {
        return 1; 
    }
    if (b == 1) {
        return a;
    }
    long long result = modPow(a, b / 2, m) % m;

    if (b % 2 == 0) {
        return (result * result) % m; 
    }
    else {
        return (result * result % m * a % m) % m; 
    }
}


int main() {
    int n, k;
    cin >> n >> k;

    long long* fact = new long long[n + 1];
    long long* invFact = new long long[n + 1];

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    
    invFact[n] = modPow(fact[n], MOD - 2, MOD); 
    for (int i = n - 1; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    long long result = (fact[n] * invFact[k] % MOD) * invFact[n - k] % MOD;
    cout << result << endl;

    delete[] fact;
    delete[] invFact;

    return 0;
}