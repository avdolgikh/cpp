#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class Rational {
public:
  Rational() {
	  numerator = 0;
	  denominator = 1;
  }

  Rational(int new_numerator, int new_denominator) {
	  if (new_denominator == 0) {
		  throw invalid_argument("Denominator is zero.");
	  }
	  numerator = new_numerator;
	  denominator = new_denominator;
	  Preprocess();
  }

  int Numerator() const {
	  return numerator;
  }
  int Denominator() const {
	  return denominator;
  }

  bool operator == (const Rational& rational) {
	return rational.numerator == numerator && rational.denominator == denominator;
  }

  Rational operator + (const Rational& rational) {
	  return Rational (	numerator * rational.denominator + rational.numerator * denominator,
			  	  	  	denominator * rational.denominator);
  }

  Rational operator - (const Rational& rational) {
	  return Rational (	numerator * rational.denominator - rational.numerator * denominator,
						denominator * rational.denominator);
  }

  Rational operator * (const Rational& rational) {
	  return Rational (	numerator * rational.numerator,
						denominator * rational.denominator);
  }

  Rational operator / (const Rational& rational) {
	  if (denominator * rational.numerator == 0) {
		  throw domain_error("Division by zero.");
	  }
	  return Rational (	numerator * rational.denominator,
			  	  	  	denominator * rational.numerator );
  }


  friend Rational operator + (const Rational& lhs, const Rational& rhs) {
	  return Rational (	lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator,
			  	  	  	lhs.denominator * rhs.denominator);
  }

  friend Rational operator - (const Rational& lhs, const Rational& rhs) {
	  return Rational (	lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator,
			  	  	  	lhs.denominator * rhs.denominator);
  }

  friend Rational operator * (const Rational& lhs, const Rational& rhs) {
	  return Rational (	lhs.numerator * rhs.numerator,
			  	  	  	lhs.denominator * rhs.denominator);
  }

  friend Rational operator / (const Rational& lhs, const Rational& rhs) {
	  if (lhs.denominator * rhs.numerator == 0) {
		  throw domain_error("Division by zero.");
	  }
	  return Rational (	lhs.numerator * rhs.denominator,
			  	  	  	lhs.denominator * rhs.numerator );
  }


  bool operator < (const Rational& rational) {
	  return numerator * rational.denominator < rational.numerator * denominator;
  }


  friend bool operator == (const Rational& lhs, const Rational& rhs) {
	  return rhs.numerator == lhs.numerator && rhs.denominator == lhs.denominator;
  }

  friend bool operator < (const Rational& lhs, const Rational& rhs) {
	  return lhs.numerator * rhs.denominator < rhs.numerator * lhs.denominator;
  }


  friend ostream& operator << (ostream& stream, const Rational& rational) {
  	stream << rational.numerator << "/" << rational.denominator;
  	return stream;
  }

  friend istream& operator >> (istream& stream, Rational& rational) {
	stream >> rational.numerator;
	stream.ignore(1);
	stream >> rational.denominator;

	if (rational.denominator == 0) {
		  throw invalid_argument("Denominator is zero.");
	  }

	rational.Preprocess();
	return stream;
  }

private:
	int numerator, denominator;

	void Preprocess () {
		int a = numerator, b = denominator, prev_a = 0;
		while (a % b != 0) {
			prev_a = a;
			a = b;
			b = prev_a % b;
		}
		numerator /= b;
		denominator /= b;

		if (denominator < 0) {
			numerator *= -1;
			denominator *= -1;
		}
	}
};


class Calculator {
public:
	Calculator () {}

	friend istream& operator >> (istream& stream, Calculator& calculator) {
		stream >> calculator.rational_lhs;
		stream.ignore(1);
		stream >> calculator.operation;
		stream.ignore(1);
		stream >> calculator.rational_rhs;
		return stream;
	  }

	friend ostream& operator << (ostream& stream, const Calculator& calculator) {
		Rational result;
		if (calculator.operation == '+') {
			result = calculator.rational_lhs + calculator.rational_rhs;
		} else if (calculator.operation == '-') {
			result = calculator.rational_lhs - calculator.rational_rhs;
		} else if (calculator.operation == '*') {
			result = calculator.rational_lhs * calculator.rational_rhs;
		} else if (calculator.operation == '/') {
			result = calculator.rational_lhs / calculator.rational_rhs;
		}
//		if (result.Numerator() == 0) {
//			stream << 0;
//		} else {
//			stream << result;
//		}
		stream << result;
		return stream;
	}

private:
	Rational rational_lhs;
	Rational rational_rhs;
	char operation;
};


void Run (string expression) {
	stringstream str_stream(expression);
	Calculator calculator;
	try {
		str_stream >> calculator;
		//cin >> calculator;
		cout << calculator;
	} catch (invalid_argument&) {
		cout << "Invalid argument";
	} catch (domain_error&) {
		cout << "Division by zero";
	}
}


int main() {
	map<string, string> ss {
			{ "1/2 / 1/3", "3/2" },
			{ "1/2 + 5/0", "Invalid argument" },
			{ "4/5 / 0/8", "Division by zero" },
			{ "0/189999 - 56/8", "-7/1" },
			{ "0/189999 * 56/8", "0/1" },
			{ "-2/3 - 4/6", "-4/3" },
			{ "-2/-3 + -4/-6", "4/3" },
			{ "-2/-3 + -4/-6", "4/3" },
		};

	for (const auto& s : ss) {
		Run(s.first);
		cout << " --- " << s.second;
		cout << endl;
	}

//	Calculator calculator;
//	try {
//		cin >> calculator;
//		cout << calculator;
//	} catch (invalid_argument&) {
//		cout << "Invalid argument";
//	} catch (domain_error&) {
//		cout << "Division by zero";
//	}

	return 0;
}
