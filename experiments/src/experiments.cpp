#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;



struct Duration {
	int hour;
	int min;

	Duration (int h = 0, int m = 0) {
		int total = h * 60 + m;
		hour = total / 60;
		min = total % 60;
	}
};

istream& operator >> (istream& stream, Duration& duration) {
	stream >> duration.hour;
	stream.ignore(1);
	stream >> duration.min;
	return stream;
}

ostream& operator << (ostream& stream, const Duration& duration) {
	stream << setfill('0');
	stream << setw(2) << duration.hour << ':'
		   << setw(2) << duration.min;
	return stream;
}

Duration operator + (const Duration& lhs, const Duration& rhs) {
	return Duration ( lhs.hour + rhs.hour, lhs.min + rhs.min );
}

bool operator < (const Duration& lhs, const Duration& rhs) {
	int lhs_total = lhs.hour * 60 + lhs.min;
	int rhs_total = rhs.hour * 60 + rhs.min;
	return lhs_total < rhs_total;
}

void PrintVector(const vector<Duration>& dur) {
	for (const auto& d : dur) {
		cout << d << ' ';
	}
	cout << endl;
}


struct Date {
	int year;
	int month;
	int day;
};

void EnsureNextSymbol (stringstream& stream) {
	if (stream.peek() != '/') {
		stringstream ss;
		ss << "expected /, but has: " << char(stream.peek());
		throw runtime_error(ss.str());
	}
	stream.ignore(1);
}

Date ParseDate (const string& s) {
	stringstream stream(s);
	Date date;
	stream >> date.year;
	EnsureNextSymbol(stream);
	stream >> date.month;
	EnsureNextSymbol(stream);
	stream >> date.day;
	return date;
}

int main() {
	string date_str = "2017/01b25";

	try {
		Date date = ParseDate(date_str);
		cout << setw(2) << setfill('0') << date.day << '.'
		 << setw(2) << setfill('0') << date.month << '.'
		 << date.year << endl;
	} catch (exception& ex) {
		cout << "Exception: " << ex.what();
	}



//	stringstream dur_ss("02:50");
//	Duration dur1;
//	dur_ss >> dur1;
//	Duration dur2 = { 0, 35 };
//	Duration dur3 = dur1 + dur2;
//
//	vector<Duration> v {
//		dur3, dur1, dur2
//	};
//
//	PrintVector(v);
//	sort(begin(v), end(v));
//	PrintVector(v);
	return 0;
}
