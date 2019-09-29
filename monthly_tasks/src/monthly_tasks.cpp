#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void Add (vector<vector<string>>& calendar, int day, string task) {
	calendar[day - 1].push_back(task);
}

void Next (vector<vector<string>>& calendar, int month_index) {
	vector<int> days_in_months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int n_days = days_in_months[month_index];

	vector<string> backup;

	if (n_days < calendar.size()) {
		for (int i = n_days; i < calendar.size(); ++i) {
			backup.insert(end(backup), begin(calendar[i]), end(calendar[i]));
		}
	}

	calendar.resize(n_days);

	if (backup.size() > 0) {
		calendar[n_days - 1].insert(end(calendar[n_days - 1]), begin(backup), end(backup));
	}
}

void Dump (const vector<vector<string>>& calendar, int day) {
	auto tasks = calendar[day - 1];
	cout << tasks.size() << " ";
	for (auto task : tasks ) {
		cout << task << " ";
	}
	cout << endl;
}


int main() {
	vector<vector<string>> calendar(31);
	int month_index = 0;

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		string op;
		int day;
		string task;

		cin >> op;

		if (op == "ADD") {
			cin >> day;
			cin >> task;
			Add (calendar, day, task);
		} else if (op == "NEXT") {
			month_index++;
			Next(calendar, month_index);
		} else if (op == "DUMP") {
			cin >> day;
			Dump(calendar, day);
		}
	}
	return 0;
}
