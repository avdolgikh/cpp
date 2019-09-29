#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

void NewBus (map<string, vector<string>>& buses, map<string, vector<string>>& stops, string bus, int stopCount) {
	for (int i = 0; i < stopCount; ++i) {
		string stop;
		cin >> stop;
		buses[bus].push_back(stop);
		stops[stop].push_back(bus);
	}
}

void BusesForStop (map<string, vector<string>>& stops, string stop) {
	if (stops.count(stop) == 0) {
		cout << "No stop" << endl;
	} else {
		for (const auto& item : stops[stop]) {
			cout << item << " ";
		}
		cout << endl;
	}
}

void StopsForBus (map<string, vector<string>>& buses, map<string, vector<string>>& stops, string bus) {
	if (buses.count(bus) == 0) {
		cout << "No bus" << endl;
	} else {
		for (const auto& stop : buses[bus]) {
			cout << "Stop " << stop << ": ";
			if (stops[stop].size() == 1) {
				cout << "no interchange";
			} else {
				for (const auto& item : stops[stop]) {
					if (item != bus) {
						cout << item << " ";
					}
				}
			}
			cout << endl;
		}
	}
}

void AllBuses (map<string, vector<string>>& buses) {
	if (buses.size() == 0) {
		cout << "No buses" << endl;
	} else {
		for (const auto& item : buses) {
			cout << "Bus " << item.first << ": ";
			for (const auto& stop : item.second) {
				cout << stop << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	int q;
	cin >> q;

	map<string, vector<string>> buses;
	map<string, vector<string>> stops;

	for (int i = 0; i < q; ++i) {
		string op;
		cin >> op;
		if (op == "NEW_BUS") {
			string bus;
			cin >> bus;
			int stopCount;
			cin >> stopCount;
			NewBus(buses, stops, bus, stopCount);
		} else if (op == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;
			BusesForStop(stops, stop);
		} else if (op == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			StopsForBus(buses, stops, bus);
		} else if (op == "ALL_BUSES") {
			AllBuses(buses);
		}
	}
	cout << endl;

	return 0;
}
