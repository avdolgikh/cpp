#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
	vector<int> result;
	for (int i = v.size() - 1; i >= 0; --i) {
		result.push_back(v[i]);
	}
	return result;
}

void Print(const vector<int>& v) {
	for (auto s : v) {
		cout << s << " ";
	}
}

int main() {
	vector<int> numbers = {1, 5, 3, 4, 2};
	Print(Reversed(numbers));
	return 0;
}
