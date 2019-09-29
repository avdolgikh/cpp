#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
	for (int i = 0; i < v.size() / 2; ++i) {
        auto tmp = v[i];
		v[i] = v[v.size() - 1 - i];
		v[v.size() - 1 - i] = tmp;
	}
}

void Print(const vector<int>& v) {
	for (auto s : v) {
		cout << s << " ";
	}
}

int main() {
	vector<int> numbers = {1, 5, 3, 4, 2};
	Reverse(numbers);
	Print(numbers);
	return 0;
}
