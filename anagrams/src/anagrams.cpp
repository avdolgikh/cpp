#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int IsAnagram (const string& a, const string& b) {
	if (a.size() != b.size()) {
		return 0;
	}

	map<char, int> amap;
	map<char, int> bmap;

	for (const auto& ch : a)
	{
		amap[ch]++;
	}

	for (const auto& ch : b)
	{
		if (amap.count(ch) == 0) {
			//cout << "'" << ch << "'" << " is absent in b." << endl;
			return 0;
		}

		bmap[ch]++;
	}

	if (amap != bmap) {
		return 0;
	}

	return 1;
}

int main() {
	int n;
	cin >> n;

	vector<int> result;

	for (int i = 0; i < n; ++i) {
		string a, b;
		cin >> a >> b;
		result.push_back( IsAnagram(a, b) );
	}

	for (const auto& item : result) {
		if (item > 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
