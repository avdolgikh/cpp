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

	Person(const string& firstName, const string& lastName, int year) {
		fullNames.push_back({ firstName, lastName, year });
		yearOfBirth = year;
	}

	void ChangeFirstName(int year, const string& firstName) {
	  if (year < yearOfBirth) {
		  return;
	  }

	  bool exists = false;
	  for (auto& name : fullNames) {
		  if (name.year == year)
		  {
			  name.firstName = firstName;
			  exists = true;
			  break;
		  }
	  }
	  if (!exists) {
		  fullNames.push_back({ firstName, "", year });
	  }
	}

	void ChangeLastName(int year, const string& lastName) {
	  if (year < yearOfBirth) {
		  return;
	  }

	  bool exists = false;
	  for (auto& name : fullNames) {
		  if (name.year == year)
		  {
			  name.lastName = lastName;
			  exists = true;
			  break;
		  }
	  }
	  if (!exists) {
		  fullNames.push_back({ "", lastName, year });
	  }
	}

	string GetFullName(int year) {
	  if (year < yearOfBirth) {
		  return "No person";
	  }

	  sort( begin(fullNames), end(fullNames), Compare );

	  string firstName = "";
	  string lastName = "";
	  for (auto& name : fullNames) {
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

	string GetFullNameWithHistory(int year) {
	  if (year < yearOfBirth) {
		  return "No person";
	  }

	  sort( begin(fullNames), end(fullNames), Compare );

	  vector<string> firstNames;
	  vector<string> lastNames;
	  for (auto& name : fullNames) {
		  if (name.year > year)
		  {
			  break;
		  }
		  if (name.firstName != "") {
			  firstNames.push_back(name.firstName);
		  }
		  if (name.lastName != "") {
			  lastNames.push_back(name.lastName);
		  }
	  }

	  if (firstNames.size() == 0 && lastNames.size() == 0) {
		  return "Incognito";
	  }
	  if (firstNames.size() == 0) {
		  return CombineName(lastNames) + " with unknown first name";
	  }
	  if (lastNames.size() == 0) {
		  return CombineName(firstNames) + " with unknown last name";
	  }

	  return CombineName(firstNames) + " " + CombineName(lastNames);
  }

private:
	int yearOfBirth;
	vector<PersonName> fullNames;

	static string CombineName(const vector<string>& names) {
		string result = "";
		if (names.size() > 0) {
			string current_name = names[names.size()-1];
			result += current_name;
			if (count_if(begin(names), end(names), [current_name](string s) { return s != current_name; }) > 0) {
				result += " (";
				string delim = "";
				for (int i = names.size()-2; i >= 0; --i) {
					if (names[i] != names[i+1]) {
						result += delim + names[i];
						delim = ", ";
					}
				}
				result += ")";
			}
		}
		return result;
	}
};


int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
