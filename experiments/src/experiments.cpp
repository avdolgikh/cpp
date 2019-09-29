#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void PrintMap(const map<char, vector<string>>& m) {
	// cout << "size = " << m.size() << endl;
	for (const auto& item : m ) {
		cout << item.first << endl;
		for (const auto& word : item.second ) {
			cout << word << " ";
		}
		cout << endl;
	}
}

int main() {
	map<int, string> m = {{1, "odd"}, {2, "even"}, {1, "one"}};
	m[2] = "two";
	m.erase(1);
	m[3] = "three";
	m.erase(4);
	m[5] = "five";
	cout << m.size();
	return 0;
}
