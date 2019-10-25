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

	  // Wrong date format: DATE

  	stream >> date.year;
  	stream.ignore(1); // check that it is particullarly '-'

  	stream >> date.month;
  	//Month value is invalid: MONTH
  	// string error = "Month value is invalid: " + to_string(month);

  	stream.ignore(1);
  	stream >> date.day;
  	// Day value is invalid: DAY

//	if () {
//		throw invalid_argument("...");
//	}
  	return stream;
  }

  friend ostream& operator << (ostream& stream, const Date& date) {
	  stream << setw(4) << setfill('0') << date.year << '-'
	  		 << setw(2) << setfill('0') << date.month << '-'
			 << setw(2) << setfill('0') << date.day;
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
		//cout << data.size() << " " << data[date].size() << endl;
	}

	bool DeleteEvent(const Date& date, const string& event) {
		if (data.count(date) > 0) {
			if (data[date].count(event)) {
				data[date].erase(event);
				if (data[date].size() == 0) {
					DeleteDate(date);
				}
				//cout << data.size() << " " << data[date].size() << endl;
				return true;
			}
		}
		//cout << data.size() << " " << data[date].size() << endl;
		return false;
	}

	int  DeleteDate(const Date& date) {
		int n = 0;
		if (data.count(date) > 0) {
			n = data[date].size();
			//data[date].clear();
			data.erase(date);
		}
		return n;
	}

	set<string> Find(const Date& date) const {
		// is 'set<string>' already sorted alphabetically?
		return data.at(date);
	}

	void Print() const {
		// 'map' must be already sorted! (sort by date)
		// 'set<string>' must be already sorted? (sort alphabetically)
		for (const auto& date : data) {
			for (const auto& event : date.second) {
				cout << date.first << " " << event << endl;
			}
		}
	}

private:
	map<Date, set<string>> data;
};

void ParseCommand(stringstream& stream, Date& date, string& event) {
	stream.ignore(1); // or more?
	stream >> date;
	//cout << date.GetDay() << endl;

	event = "";

	if (stream.peek() != '\n') {
		stream.ignore(1); // or more?
		stream >> event;
		//cout << event << endl;
	}
}

int main() {
	Database db;
	string command;

	string operation;
	Date date;
	string event;

	while (getline(cin, command)) {
		if (command == "") {
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

			if (event != "") {
				if (db.DeleteEvent(date, event)) {
					cout << "Deleted successfully" << endl;
				} else {
					cout << "Event not found" << endl;
				}
			} else {
				int n = db.DeleteDate(date);
				cout << "Deleted " << n << " events" << endl;
			}

		} else if (operation == "Find") {
			ParseCommand(stream, date, event);
			auto events =  db.Find(date);
			if (events.size() > 0) {
				for (const auto& e : events) {
					cout << e << endl;
				}
			}

		} else if (operation == "Print") {
			db.Print();

		} else {
			cout << "Unknown command: " << operation << endl;
		}
	}
	return 0;
}
