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
	{
		const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 3;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 4;
		}
	}
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }


	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}



	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			cout << "Rational(3, 10) != 3/10" << endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			cout << "Rational(8, 12) != 2/3" << endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(-4, 6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(4, -6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			cout << "Rational(0, 15) != 0/1" << endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
			cout << "Rational() != 0/1" << endl;
			return 5;
		}
	}

	cout << "OK" << endl;
	return 0;
}
