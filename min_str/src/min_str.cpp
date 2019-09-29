#include <iostream>
#include <string>
using namespace std;

int main() {
	int size = 3;
	string input;
	string result;

	cin >> result;

	for (int i = 1; i < size; ++i) {
		cin >> input;
		if (input < result) {
			result = input;
		}
	}

	cout << result;
	return 0;
}
