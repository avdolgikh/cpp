#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


string ToLower(string str) {
	string result;
	for (const auto& ch : str) {
		result.push_back(tolower(ch));
	}
	//cout << result;
	return result;
}

void Print(const vector<string>& v) {
	for (const auto& item : v) {
		cout << item << ' ';
	}
}

bool Compare (string i, string j) {
	return ToLower(i) < ToLower(j);
}

int main() {
	vector<string> S;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		S.push_back(s);
	}
	sort (begin(S), end(S), Compare);
	Print(S);
	return 0;
}
