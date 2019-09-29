#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> temperatures(n);
	int average = 0;
	int sum = 0;

	for (int& temperature : temperatures) {
		cin >> temperature;
		sum += temperature;
	}

	average = sum / n;

	//cout << average << endl;

	vector<int> days;
	for (int i = 0; i < n; i++) {
		if (temperatures[i] > average) {
			days.push_back(i);
		}
	}

	cout << days.size() << endl;
	for (int day : days) {
		cout << day << " ";
	}
	cout << endl;

	return 0;
}
