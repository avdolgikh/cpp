#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int f_count = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'f' && ++f_count == 2) {
			cout << i;
			break;
		}
	}

	if (f_count == 0) {
		cout << -2;
	} else if (f_count == 1) {
		cout << -1;
	}

	return 0;
}
