#include <iostream>
#include <string>
using namespace std;

int main() {
	//initialize output states
	// system('fast-gpio set-output 0');
	// system('fast-gpio set-output 1');
	// system('fast-gpio set-output 2');
	// system('fast-gpio set-output 3');
	// system('fast-gpio set-output 11');
	// system('fast-gpio set-output 18');
	// system('fast-gpio set-output 19');
	// system('fast-gpio set 0 0');
	// system('fast-gpio set 1 1');
	// system('fast-gpio set 2 0');
	// system('fast-gpio set 3 0');
	// system('fast-gpio set 11 1');
	// system('fast-gpio set 19 1');
	// system('fast-gpio set 18 0');
	// 0 = CW, 1 = CCW
	int dirA = 0;
	int dirB = 0;
	string input;
	string delimiter = " ";
	size_t pos = 0;
	cout << "Type 'help' for usage information." << endl;
	while (true) {
		cout << ">";
		cin >> input;
		pos = input.find(delimiter);
		string token = input.substr(0, pos);
		input.erase(0, pos + delimiter.length());
		if (input == "quit") {
			// system('fast-gpio set 2 0');
			// system('fast-gpio set 3 0');
			break;
		}
		if (input == "help") {
			cout << "[+] run <motor_number> //starts motor number indicated" << endl;
			cout << "[+] reverse <motor_number> //reverses motor number indicated" << endl;
			cout << "[+] stop <motor_number> //stops motor number indicated" << endl;
			cout << "[+] quit //quits program, stops motors if running" << endl;
			continue;
		}
		if (token == "run") {
			string arg = input.substr(0, pos);
			if (arg == "1") {
				cout << "Ran 1" << endl;
				// system('fast-gpio set 2 1');
				continue;
			} else if (arg == "2") {
				// system('fast-gpio set 3 1');
				continue;
			} else if (arg == "3") {
				// system('fast-gpio set 2 1');
				// system('fast-gpio set 3 1');
				continue;
			} else {
				cout << "Usage: run <motor_number>" << endl;
				continue;
			}
		}
		if (token == "reverse") {
			string arg = input.substr(1, input.find(' '));
			if (arg == "1") {
				cout << "Yay!" << endl;
				if (dirA == 0) {
					// system('fast-gpio set 0 1');
					// system('fast-gpio set 1 0');
					dirA = 1;
					continue;
				} else {
					// system('fast-gpio set 0 0');
					// system('fast-gpio set 1 1');
					dirA = 0;
					continue;
				}
			} else if (arg == "2") {
				if (dirB == 0) {
					// system('fast-gpio set 19 0');
					// system('fast-gpio set 18 1');
					dirB = 1;
					continue;
				} else {
					// system('fast-gpio set 19 1');
					// system('fast-gpio set 18 0');
					dirB = 0;
					continue;
				}
			} else if (arg == "3") {
				// system('fast-gpio set 2 1');
				// system('fast-gpio set 3 1');
				continue;
			} else {
				cout << "Usage: reverse <motor_number>" << endl;
				continue;
			}
		}
		if (token == "stop") {
			string arg = input.substr(1, input.find(' '));
			if (arg == "1") {
				// system('fast-gpio set 2 0');
				continue;
			} else if (arg == "2") {
				// system('fast-gpio set 3 0');
				continue;
			} else if (arg == "3") {
				// system('fast-gpio set 2 0');
				// system('fast-gpio set 3 0');
				continue;
			} else {
				cout << "Usage: stop <motor_number>" << endl;
				continue;
			}
		}
	}
}
