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
	Date (string& str_date) {
		Parse(str_date);
	}

  int GetYear() const {
	  return year;
  }
  int GetMonth() const {
	  return month;
  }
  int GetDay() const {
	  return day;
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

  void EnsureNextSymbol (istream& stream, const string& str_date) {
  	if (stream.peek() != '-') {
  		throw invalid_argument("Wrong date format: " + str_date);
  	}
  	stream.ignore(1);
  }

	void EnsureMonth () {
		if (month < 1 || month > 12) {
			throw invalid_argument("Month value is invalid: " + to_string(month));
		}
	}

	void EnsureDay () {
		if (day < 1 || day > 31) {
			throw invalid_argument("Day value is invalid: " + to_string(day));
		}
	}

	void Parse (string& str_date) {
		stringstream stream(str_date);

		stream >> year;
		EnsureNextSymbol(stream, str_date);

		stream >> month;
		EnsureNextSymbol(stream, str_date);
		EnsureMonth();

		stream >> day;
		EnsureDay();
	}
};

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		if (event == "") {
			return;
		}
		data[date].insert(event);
	}

	bool DeleteEvent(const Date& date, const string& event) {
		if (data.count(date) > 0) {
			if (data[date].count(event)) {
				data[date].erase(event);
				if (data[date].size() == 0) {
					DeleteDate(date);
				}
				return true;
			}
		}
		return false;
	}

	int  DeleteDate(const Date& date) {
		int n = 0;
		if (data.count(date) > 0) {
			n = data[date].size();
			data.erase(date);
		}
		return n;
	}

	set<string> Find(const Date& date) const {
		return data.at(date);
	}

	void Print() const {
		for (const auto& date : data) {
			for (const auto& event : date.second) {
				cout << date.first << " " << event << endl;
			}
		}
	}

private:
	map<Date, set<string>> data;
};

string ReadParameter(stringstream& stream) {
	string param = "";
	if (stream.peek() != '\n') {
		stream >> param;
	}
	return param;
}

void ProcessCommand (const string& command, Database& db) {
	string operation;
	string str_date;
	string event;

	stringstream stream(command);
	stream >> operation;

	if (operation == "Add") {
		str_date = ReadParameter(stream);
		Date date = Date(str_date);
		event = ReadParameter(stream);
		db.AddEvent(date, event);

	} else if (operation == "Del") {
		str_date = ReadParameter(stream);
		Date date = Date(str_date);
		event = ReadParameter(stream);

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
		str_date = ReadParameter(stream);
		Date date = Date(str_date);

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

int main() {
	Database db;
	string command;

	while (getline(cin, command)) {
		if (command == "") {
			continue;
		}

		try {
			ProcessCommand(command, db);
		} catch (invalid_argument& ex) {
			cout << ex.what() << endl;
		}
	}
	return 0;
}
