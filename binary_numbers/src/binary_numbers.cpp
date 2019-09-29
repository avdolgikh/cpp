#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, input;
	vector<int> v;

	cin >> input;

	n = input;

	while (n > 0) {
		v.push_back(n % 2);
		n = n / 2;
	}

	for (int i = v.size()-1; i >= 0; --i) {
		cout << v[i];
	}


//	cout << endl;
//	n = input;
//
//
//	int degree_of_2 = 0;
//	while (n > pow(2, degree_of_2)) {
//		++degree_of_2;
//	}
//
//	if (n == pow(2, degree_of_2)) {
//		cout << 1;
//		n -= pow(2, degree_of_2);
//	}
//
//	for (int i = degree_of_2 - 1; i >= 0; --i) {
//		if (n >= pow(2, i)) {
//			cout << 1;
//			n -= pow(2, i);
//		} else {
//			cout << 0;
//		}
//	}

	return 0;
}
