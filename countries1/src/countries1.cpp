#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

void ChangeCapital (string country, string capital, map<string, string>& capitalsDictionary) {
	if (capitalsDictionary.count(country) == 0) {
		cout << "Introduce new country " << country << " with capital " << capital << endl;
	} else if (capitalsDictionary[country] == capital) {
		cout << "Country " << country << " hasn't changed its capital" << endl;
	} else {
		cout << "Country " << country << " has changed its capital from " << capitalsDictionary[country] << " to " << capital << endl;
		capitalsDictionary[country] = capital;
	}
}

void ChangeCapital (string country, string capital, map<string, string>& capitalsDictionary) {
	if (capitalsDictionary.count(country) == 0) {
		cout << "Introduce new country " << country << " with capital " << capital << endl;
	} else if (capitalsDictionary[country] == capital) {
		cout << "Country " << country << " hasn't changed its capital" << endl;
	} else {
		cout << "Country " << country << " has changed its capital from " << capitalsDictionary[country] << " to " << capital << endl;
		capitalsDictionary[country] = capital;
	}
}

int main() {
	int q;
	cin >> q;

	map<string, string> capitalsDictionary;

	for (int i = 0; i < q; ++i) {
		string op;
		cin >> op;
		if (op == "CHANGE_CAPITAL") {
			string country, capital;
			cin >> country >> capital;
			ChangeCapital(country, capital, capitalsDictionary);
		} else if (op == "RENAME") {
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			// Rename(old_country_name, new_country_name, capitalsDictionary);
		} else if (op == "ABOUT") {
			string country;
			cin >> country;
			// About(country, capitalsDictionary);
		} else if (op == "DUMP") {
			// Dump(capitalsDictionary);
		}
	}

	return 0;
}
