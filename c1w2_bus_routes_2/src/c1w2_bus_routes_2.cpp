#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;


int main() {
	int q;
	cin >> q;

	map<vector<string>, int> buses;

	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;

		vector<string> stops;
		for (int j = 0; j < n; ++j) {
			string stop;
			cin >> stop;
			stops.push_back(stop);
		}
		if (buses.count(stops) > 0) {
			cout << "Already exists for " << buses[stops] << endl;
		} else {
			int new_bus = buses.size() + 1;
			buses[stops] = new_bus;
			cout << "New bus " << new_bus << endl;
		}
	}

	cout << endl;
	return 0;
}
