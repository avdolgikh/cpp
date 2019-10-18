#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Student {
	string name;
	string surname;
	string birth_year;
	string birth_month;
	string birth_day;
};

int main() {
	vector<Student> students;

	int n;
	cin >> n;

	string name, surname, birth_year, birth_month, birth_day;

	for (int i = 0; i < n; ++i) {
		cin >> name >> surname >> birth_day >> birth_month >> birth_year;
		students.push_back( { name, surname, birth_year, birth_month, birth_day } );

		//cout << "- " << name << " - " << surname << " - " << birth_day << " - " << birth_month << " - " << birth_year << endl;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		string request;
		int number;
		cin >> request >> number;
		--number;

		if (request == "name" && number >= 0 && number < n) {
			cout << students[number].name << " " << students[number].surname << endl;
		} else if (request == "date" && number >= 0 && number < n) {
			cout << students[number].birth_day << "." << students[number].birth_month << "." << students[number].birth_year << endl;
		} else {
			cout << "bad request" << endl;
		}
	}

	return 0;
}
