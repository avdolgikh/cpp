#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Come (vector<bool>& queue, int k) {
	queue.resize(queue.size() + k, false);
}

void Worry (vector<bool>& queue, int i) {
	queue[i] = true;
}

void Quit (vector<bool>& queue, int i) {
	queue[i] = false;
}

int WorryCount (const vector<bool>& queue) {
	int count = 0;
	for (auto worried : queue) {
		if (worried) {
			++count;
		}
	}
	return count;
}

int main() {
	vector<bool> queue;
	int q;
	cin >> q;

	vector<int> output;

	for (int i = 0; i < q; ++i) {
		string op;
		int param;
		cin >> op;
		if (op == "COME") {
			cin >> param;
			Come(queue, param);
		} else if (op == "WORRY") {
			cin >> param;
			Worry(queue, param);
		} else if (op == "QUIET") {
			cin >> param;
			Quit(queue, param);
		} else if (op == "WORRY_COUNT") {
			output.push_back( WorryCount(queue) );
		}
	}

	for (auto i : output) {
		cout << i << endl;
	}

	return 0;
}
