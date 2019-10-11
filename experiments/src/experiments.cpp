#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Lecture {
	string title = "C++";
	int duration = 0;
};

class Route {
private:
	static int ComputeDistance(string source, string destination) {
		return 100;
	}

	void UpdateLength() {
		length = ComputeDistance(source, destination);
		//compute_distance_log.push_back(source + " - " + destination);
	}

	string source;
	string destination;
	int length;
	//vector<string> compute_distance_log;

public:
	Route () {
		source = "Moscow";
		destination = "S-Pb";
		UpdateLength();
		cout << "Default constructed\n" ;
	}
	Route (const string& new_source, const string& new_destination) {
		source = new_source;
		destination = new_destination;
		UpdateLength();
		cout << "Constructed\n" ;
	}
	~Route () {
		cout << "Destructed\n" ;
//		for (const string& entry : compute_distance_log) {
//			cout << entry << "\n";
//		}
	}

	int GetLength() const {
		return length;
	}

	string GetSource() const {
		return source;
	}

	string GetDestination() const {
		return destination;
	}
};


void PrintRoute(const Route& r) {
	cout << r.GetLength() << endl;
	cout << r.GetSource() << endl;
	cout << r.GetDestination() << endl;
}

Route GetRoute () {
	cout << 1 << endl;
	return {};
}

void Worthless(Route route) {
	cout << 2 << endl;
}


int main() {
	GetRoute();
	cout << 2 << endl;
	return 0;
}
