#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <exception>
using namespace std;

class Date {
public:
  int GetYear() const {
	  return year;
  }
  int GetMonth() const {
	  return month;
  }
  int GetDay() const {
	  return day;
  }

  // "year-month-day" (string)
  friend istream& operator >> (istream& stream, Date& date) {
  	stream >> date.year;
  	stream.ignore(1);
  	stream >> date.month;
  	stream.ignore(1);
  	stream >> date.day;
//	if () {
//		throw invalid_argument("...");
//	}
  	return stream;
  }

  friend bool operator < (const Date& lhs, const Date& rhs) {
	  if (lhs.year == rhs.year) {
		  if (lhs.month == rhs.month) {
			  return lhs.day < rhs.day;
		  }
		  return lhs.month < rhs.month;
	  }
	  return lhs.year < rhs.year;
  }

private:
  int year;
  int month;
  int day;
};


class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		// Event: "sdvsdvsdvasdvasdvdsfbvdsbdfgbn" (string without space and delimiters), not empty!
		if (event == "") {
			return;
		}
		data[date].insert(event);
		// ignore similar event for a one date
		cout << data.size() << " " << data[date].size() << endl;
	}

	bool DeleteEvent(const Date& date, const string& event) {
		if (data.count(date) > 0) {
			if (data[date].count(event)) {
				data[date].erase(event);

				// TODO: if data[date].size() == 0 => call DeleteDate()

				cout << data.size() << " " << data[date].size() << endl;
				return true;
			}
		}
		cout << data.size() << " " << data[date].size() << endl;
		return false;
	}

	int  DeleteDate(const Date& date);
	void /*bool ?*/ Find(const Date& date) const;
	void Print() const;

private:
	map<Date, set<string>> data;
};

void ParseCommand(stringstream& stream, Date& date, string& event) {
	stream.ignore(1); // or more?
	stream >> date;
	//cout << date.GetDay() << endl;

	stream.ignore(1); // or more?
	stream >> event;
	//cout << event << endl;
}

int main() {
	Database db;
	string command;

	// Commands:
	// Add Date Event
	// Del Date Event
	// Del Date
	// Find Date
	// Print
	// !!! ignore empty strings!

	string operation;
	Date date;
	string event;

	// while (true)
	while (getline(cin, command)) {

		//cout << '"' << command << '"' << endl;

		if (command == "") {
			//cout << "Command is empty!" << endl;
			continue;
		}

		stringstream stream(command);
		stream >> operation;

		//cout << operation << endl;

		if (operation == "Add") {
			ParseCommand(stream, date, event);
			db.AddEvent(date, event);

		} else if (operation == "Del") {
			ParseCommand(stream, date, event);
			db.DeleteEvent(date, event);
//		} else if (command == "Find") {
//			db.Find();
//		} else if (command == "Print") {
//			db.Find();
		} else {
			// unknown command
			cout << "Unknown command" << endl;
		}
	}
	return 0;
}
