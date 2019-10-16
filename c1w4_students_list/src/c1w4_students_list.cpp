#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Student {
	string name;
	string surname;
	int birth_year;
	int birth_month;
	int birth_day;
};

int main() {
	vector<Student> students;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string name, surname;
		cin >> name >> surname;
		int birth_year, birth_month, birth_day;
		cin >> birth_day >> birth_month >> birth_year;

		students.push_back( { name, surname, birth_year, birth_month, birth_day } );

		//cout << name << " " << surname << " " << birth_day << " " << birth_month << " " << birth_year << endl;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		string request;
		cin >> request;
		int number;
		cin >> number;

		if (request == "name") {
			cout << students[number - 1].name << " " << students[number - 1].surname << endl;
		} else if (request == "date") {
			cout << students[number - 1].birth_day << "." << students[number - 1].birth_month << "." << students[number - 1].birth_year << endl;
		} else {
			cout << "bad request" << endl;
		}
	}

	return 0;
}
