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


string AskTimeServer() {
	// network issue => throw system_error(error_code());
	//throw system_error(error_code());

	// other problems => other exceptions;
	//throw runtime_error("Another issue.");

	// call a remote server, asking current time;
	// if the responce is success => return current time as a string;
	return "15:14:02";
}

class TimeServer {
public:
	string GetCurrentTime() {
		try {
			// call AskTimeServer
			string serverTime = AskTimeServer();
			// put a value into lastFetchedTime
			lastFetchedTime = serverTime;
			// return the value
			return serverTime;
		}
		// if system_error => catch and return lastFetchedTime
		catch (system_error&) {
			return lastFetchedTime;
		}
		// ignore other exceptions
	}

private:
	string lastFetchedTime = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
