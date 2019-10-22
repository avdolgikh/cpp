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
	  ApplyGCD();
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
	rational.ApplyGCD();
	return stream;
  }

private:
	int numerator, denominator;
	void ApplyGCD() {
		int a = numerator, b = denominator, prev_a = 0;
		while (a % b != 0) {
			prev_a = a;
			a = b;
			b = prev_a % b;
		}
		numerator /= b;
		denominator /= b;
	}
};





int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
