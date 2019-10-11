#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class ReversibleString {
private:
	string str;

public:
	ReversibleString () {
		str = "";
	}

	ReversibleString (const string& s) {
		str = s;
	}

	string ToString () const {
		return str;
	}

	void Reverse() {
		for (int i = 0; i < (int)(str.size() / 2); ++i) {
			char tmp = str[str.size() - 1 - i];
			str[str.size() - 1 - i] = str[i];
			str[i] = tmp;
		}
	}
};


//int main() {
//  ReversibleString s("live");
//  s.Reverse();
//  cout << s.ToString() << endl;
//
//  s.Reverse();
//  const ReversibleString& s_ref = s;
//  string tmp = s_ref.ToString();
//  cout << tmp << endl;
//
//  ReversibleString empty;
//  cout << '"' << empty.ToString() << '"' << endl;
//
//  return 0;
//}

