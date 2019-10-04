#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


void Print(const vector<int>& v) {
	for (const auto& item : v) {
		cout << item << ' ';
	}
}

bool Compare (int i, int j) {
	return abs(i) < abs(j);
}

int main() {
	vector<int> A;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	//cout << endl;
	sort (begin(A), end(A), Compare);
	Print(A);
	return 0;
}
