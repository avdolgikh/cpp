#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom (string s) {
	for (int i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}

vector<string> PalindromFilter (vector<string> words, int minLength) {
	vector<string> result = {};
	for (auto w : words) {
		if (w.size() >= minLength && IsPalindrom(w)) {
			result.push_back(w);
		}
	}
	return result;
}

int main() {
	for (auto w : PalindromFilter({ "weew", "bro", "code" }, 4)) {
		cout << w << endl;
	}
	return 0;
}
