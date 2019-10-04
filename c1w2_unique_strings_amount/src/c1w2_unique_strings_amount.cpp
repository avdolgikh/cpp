#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
using namespace std;

void PrintSet(const set<string>& s) {
	for (auto item : s) {
		cout << item << endl;
	}
}

set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> s;
	for (const auto& item : m) {
		s.insert(item.second);
	}
	return s;
}

//int main() {
//	set<string> values = BuildMapValuesSet({
//	    {1, "odd"},
//	    {2, "even"},
//	    {3, "odd"},
//	    {4, "even"},
//	    {5, "odd"}
//	});
//
//	for (const string& value : values) {
//	  cout << value << endl;
//	}
//
//
////	int n;
////	cin >> n;
////
////	set<string> words;
////
////	for (int i = 0; i < n; ++i) {
////		string word;
////		cin >> word;
////		words.insert(word);
////	}
////
////	cout << words.size() << endl;
//
//	return 0;
//}
