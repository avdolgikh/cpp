#include <iostream>
#include <vector>
#include <string>
using namespace std;

void MoveStrings (vector<string>& source, vector<string>& destination) {
	for (auto s : source) {
		destination.push_back(s);
	}
	source.clear();
}

void Print(const vector<string>& v) {
	for (auto s : v) {
		cout << s << " ";
	}
}

int main() {
	vector<string> source = {"a", "b", "c"};
	vector<string> destination = {"z"};
	MoveStrings(source, destination);

	cout << "source: ";
	Print(source);
	cout << endl;
	cout << "destination: ";
	Print(destination);
	return 0;
}
