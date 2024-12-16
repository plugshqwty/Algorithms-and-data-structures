#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cin >> n;

    if (n == 2) {
        cout << "-1" << endl;
        return 0;
    }

    vector<int> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    if (n == 1) {
        cout << m[0]<<endl;
        cout << n;
        return 0;
    }
    vector<int> frog(n, 0); 
    vector<int> path(n, -1);
    frog[0] = m[0]; 
    frog[1] = -1;
    frog[2] = frog[0] + m[2];

    path[2] = 0; 

    for (int i = 3; i < n; i++) {
        
        if (frog[i - 3] > frog[i - 2]) {
            frog[i] = frog[i - 3] + m[i];
            path[i] = i - 3; 
        }
        else {
            frog[i] = frog[i - 2] + m[i];
            path[i] = i - 2; 
        }
    }

    cout << endl << frog[n - 1] << endl;
  
    
    vector<int> sequence;
    int current = n - 1;

    while (current != -1) {
        sequence.push_back(current + 1); 
        current = path[current];
    }

   for (int i = sequence.size() - 1; i >= 0; i--) {
        cout << sequence[i] << " ";
    }


    return 0;
}