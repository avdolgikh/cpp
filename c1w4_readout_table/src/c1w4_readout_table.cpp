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
	ifstream input("input.txt");

	if (!input) {
		return 0;
	}

	int n, m;
	input >> n;
	input.ignore(1);
	input >> m;
	input.ignore(1);

	string cell;

	for (int i = 0; i < n; ++i) {
		string cell_delim = " ";
		for (int j = 0; j < m; ++j) {
			if (j == m - 1) {
				cell_delim = "";
				getline(input, cell);
			} else {
				getline(input, cell, ',');
			}
			cout << setw(10) << cell << cell_delim;
		}
		if (i < n-1) {
			cout << endl;
		}
	}

	return 0;
}
