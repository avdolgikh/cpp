#include <iostream>
using namespace std;

int main() {
	unsigned a, b;
	cin >> a >> b;

	if (b == 0) {
		cout << "Impossible";
	} else {
		cout << a / b;
	}

	return 0;
}
