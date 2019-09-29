#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

void ChangeCapital (string country, string capital, map<string, string>& capitalsDictionary) {
	if (capitalsDictionary.count(country) == 0) {
		cout << "Introduce new country " << country << " with capital " << capital << endl;
		capitalsDictionary[country] = capital;
	} else if (capitalsDictionary[country] == capital) {
		cout << "Country " << country << " hasn't changed its capital" << endl;
	} else {
		cout << "Country " << country << " has changed its capital from " << capitalsDictionary[country] << " to " << capital << endl;
		capitalsDictionary[country] = capital;
	}
}

void Rename (string oldCountry, string newCountry, map<string, string>& capitalsDictionary) {
	if (oldCountry == newCountry || capitalsDictionary.count(oldCountry) == 0 || capitalsDictionary.count(newCountry) > 0) {
		cout << "Incorrect rename, skip" << endl;
	} else {
		const string& capital = capitalsDictionary[oldCountry];
		cout << "Country " << oldCountry << " with capital " << capital << " has been renamed to " << newCountry << endl;
		capitalsDictionary.erase(oldCountry);
		capitalsDictionary[newCountry] = capital;
	}
}

void About (string country, map<string, string>& capitalsDictionary) {
	if (capitalsDictionary.count(country) == 0) {
		cout << "Country " << country << " doesn't exist" << endl;
	} else {
		cout << "Country " << country << " has capital " << capitalsDictionary[country] << endl;
	}
}

void Dump (const map<string, string>& capitalsDictionary) {
	if (capitalsDictionary.size() == 0) {
			cout << "There are no countries in the world" << endl;
	} else {
		for (const auto& item : capitalsDictionary) {
			cout << item.first << "/" << item.second << " ";
		}
		cout << endl;
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
			string oldCountry, newCountry;
			cin >> oldCountry >> newCountry;
			Rename(oldCountry, newCountry, capitalsDictionary);
		} else if (op == "ABOUT") {
			string country;
			cin >> country;
			About(country, capitalsDictionary);
		} else if (op == "DUMP") {
			Dump(capitalsDictionary);
		}
	}
	cout << endl;

	return 0;
}
