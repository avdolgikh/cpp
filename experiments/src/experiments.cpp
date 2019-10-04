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


int main() {
	vector<int> v = {
		1, 2, 5, 4, 2
	};


	// sort (begin(v), end(v));


	// cout << count( begin(v), end(v), 2 );


	for (auto& i : v) {
		++i;
	}
	Print(v);

//	int thr = 0;
//	cin >>  thr;
//
//	cout << count_if( begin(v), end(v), [thr](int x) {
//											if (x > thr) {
//												return true;
//											}
//											return false;
//										});

	return 0;
}
