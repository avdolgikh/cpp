#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
	  strings.push_back(s);
  }
  vector<string> GetSortedStrings() {
	  Sort();
	  return strings;
  }
private:
  vector<string> strings;
  void Sort() {
	  sort(begin(strings), end(strings));
  }
};

// Compile error: b"/tmp/submissionc1s7kc1t/c1w3_sorted_strings.cpp:
// In function 'void PrintSortedStrings(SortedStrings&)':\n/tmp/submissionc1s7kc1t/c1w3_sorted_strings.cpp:51:6:
// error: redefinition of 'void PrintSortedStrings(SortedStrings&)'\n void PrintSortedStrings(SortedStrings& strings)
// {\n      ^~~~~~~~~~~~~~~~~~\ncompilation terminated due to -Wfatal-errors.\n"

//void PrintSortedStrings(SortedStrings& strings) {
//  for (const string& s : strings.GetSortedStrings()) {
//    cout << s << " ";
//  }
//  cout << endl;
//}

//int main() {
//  SortedStrings strings;
//  strings.AddString("first");
//  strings.AddString("third");
//  strings.AddString("second");
//  PrintSortedStrings(strings);
//  strings.AddString("second");
//  PrintSortedStrings(strings);
//  return 0;
//}

