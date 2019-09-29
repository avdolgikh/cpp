#include <iostream>
using namespace std;

int main() {
	unsigned a, b, prev_a;
	cin >> a >> b;


	while (a % b != 0) {
		// cout << a % b << endl;

		prev_a = a;
		a = b;
		b = prev_a % b;
	}

	cout << b;
	return 0;
}
