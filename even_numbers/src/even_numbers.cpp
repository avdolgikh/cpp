#include <iostream>
using namespace std;

int main() {
	int a, b; // a <= b, a >= 1, b <= 30000.
	cin >> a >> b;

	if (a % 2 == 0) {
		cout << a << " ";
		a += 2;
	} else {
		++a;
	}

	while (a <= b) {
		cout << a << " ";
		a += 2;
	}


//	for (int i = a; i <= b; i += 2 ) {
//		cout << i << " ";
//	}

	return 0;
}
