#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
using namespace std;

void Add (map<string, set<string>>& sinonims, string word1, string word2) {
	sinonims[word1].insert(word2);
	sinonims[word2].insert(word1);
}

void Count (map<string, set<string>>& sinonims, string word) {
	if (sinonims.count(word) == 0) {
		cout << 0 << endl;
	} else {
		cout << sinonims[word].size() << endl;
	}
}

void Check (map<string, set<string>>& sinonims, string word1, string word2) {
	if (sinonims.count(word1) > 0 && sinonims[word1].count(word2) > 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main() {
	int q;
	cin >> q;

	map<string, set<string>> sinonims;

	for (int i = 0; i < q; ++i) {
		string op;
		cin >> op;
		if (op == "ADD") {
			string word1, word2;
			cin >> word1 >> word2;
			Add(sinonims, word1, word2);
		} else if (op == "COUNT") {
			string word;
			cin >> word;
			Count(sinonims, word);
		} else if (op == "CHECK") {
			string word1, word2;
			cin >> word1 >> word2;
			Check(sinonims, word1, word2);
		}
	}
	cout << endl;

	return 0;
}
