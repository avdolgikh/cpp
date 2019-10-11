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
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}
