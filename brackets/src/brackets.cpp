#include <iostream>
#include <string>
using namespace std;

void Generate (string s, int opened, int closed, int n) {
	// cout << "opened: " << opened << ", closed: " << closed << endl;

	if (s.size() == 2*n) {
		cout << s << endl;
		return;
	}

	if (opened < n) {
		Generate(s + "(", opened + 1, closed, n);
	}

	if (closed < opened) {
		Generate(s + ")", opened, closed + 1, n);
	}
}

int main () {
	int n;
	cin >> n;

	Generate("", 0, 0, n);

	return 0;
}
