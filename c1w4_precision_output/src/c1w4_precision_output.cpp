#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	ifstream input("input.txt");

	if (input) {
		cout << fixed << setprecision(3);

//		string line;
//		while (getline(input, line)) {
//			cout << stof(line) << endl;
//		}

		double a;
		while (input >> a) {
			cout << a << endl;
		}
	}	return 0;
}
