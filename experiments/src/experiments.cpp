#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


void Print(const vector<int>& v) {
	for (auto& item : v) {
		cout << item << ' ';
	}
}


int main() {
	vector<int> v = {
		1, 2, 5, 4, 2
	};


	// sort (begin(v), end(v));
	// Print(v);

	// cout << count( begin(v), end(v), 2 );
	cout << count_if( begin(v), end(v), [](int x) {
											if (x > 2) {
												return true;
											}
											return false;
										});

	return 0;
}
