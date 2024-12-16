#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

class RSQ {
private:
	vector<long long> a;
	vector<long long> b;
	long long k;
	long long n;
public:
	RSQ(vector<long long> A) {
		a = A;
		k = floor(sqrt(a.size()));
		b.resize((A.size() + k - 1) / k);
		for (size_t i = 0; i < a.size(); ++i) {
			b[i / k] = b[i / k]+ a[i];
		}

	}
	long long FindSum(long long l, long long r) {
		long long sum = 0;
		int jl = l / k;
		int jr = r / k;
		if (jl == jr) {
			for (int i = l; i < r; i++) {
				sum = sum + a[i];
			}
			//cout << sum << endl;
			return sum;
		}
		else {
			for (int i = l; i < (jl+1)*k; i++) {
				sum = sum + a[i];
			}
			for (int i = jl+1; i <jr ; i++) {
				sum = sum + b[i];
			}
			for (int i = jr*k; i < r; i++) {
				sum = sum + a[i];
			}
			//cout << sum << endl;
			return sum;
		}

	}
	void Add(long long i,long long  x) {
		a[i] = a[i] + x;
		b[i / k] = b[i / k] + x;
	}

};

int main() {
	int n;
	cin >> n;
	vector<long long> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];

	}
	int q; 
	cin >> q;
	RSQ ob(A);
	string line;
	vector<long long> result;

	cin.ignore(); 

	for (int i = 0; i < q; ++i) {
		getline(cin, line);
		istringstream iss(line);
		string command;
		iss >> command;

		if (command == "FindSum") {
			long long l, r;
			iss >> l >> r;
			result.push_back(ob.FindSum(l, r));
		}
		else if (command == "Add") {
			long long in, x;
			iss >> in >> x;
			ob.Add(in, x);
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
	
}