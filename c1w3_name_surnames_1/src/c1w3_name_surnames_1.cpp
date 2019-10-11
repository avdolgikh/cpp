#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct PersonName {
	string firstName;
	string lastName;
	int year;
};

bool Compare (const PersonName& i, const PersonName& j) {
	return i.year < j.year;
}

class Person {
public:
  void ChangeFirstName(int year, const string& firstName) {
	  bool exists = false;
	  for (auto& name : names) {
		  if (name.year == year)
		  {
			  name.firstName = firstName;
			  exists = true;
			  break;
		  }
	  }
	  if (!exists) {
		  names.push_back({ firstName, "", year });
	  }
  }

  void ChangeLastName(int year, const string& lastName) {
	  bool exists = false;
	  for (auto& name : names) {
		  if (name.year == year)
		  {
			  name.lastName = lastName;
			  exists = true;
			  break;
		  }
	  }
	  if (!exists) {
		  names.push_back({ "", lastName, year });
	  }
  }

  string GetFullName(int year) {
	  sort( begin(names), end(names), Compare );

	  string firstName = "";
	  string lastName = "";
	  for (auto& name : names) {
		  if (name.year > year)
		  {
			  break;
		  }
		  firstName = name.firstName != "" ? name.firstName : firstName;
		  lastName = name.lastName != "" ? name.lastName : lastName;
	  }

	  if (firstName == "" && lastName == "") {
		  return "Incognito";
	  }
	  if (firstName == "") {
		  return lastName + " with unknown first name";
	  }
	  if (lastName == "") {
		  return firstName + " with unknown last name";
	  }
	  return firstName + " " + lastName;
}

private:
	vector<PersonName> names;
};


int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
