#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void Print(const vector<string>& names, const vector<double>& values, int width, int precision) {
	for (const auto& n : names) {
		cout << setw(width);
		cout << n << ' ';
	}
	cout << endl;
	cout << fixed << setprecision(precision);
	for (const auto& v : values) {
		cout << setw(width);
		cout << v << ' ';
	}
}

int main() {
	vector<string> names = { "a", "b", "c" };
	vector<double> values = { 5, 0.01, 0.000005 };
	cout << setfill('.');
	cout << left;
	Print(names, values, 14, 3);
	return 0;
}
