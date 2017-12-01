#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

const int DIR_CW = 0;
const int DIR_CCW = 1;

int main() {

	// Initialize output states
	system("fast-gpio set-output 0");
	system("fast-gpio set-output 1");
	system("fast-gpio set-output 2");
	system("fast-gpio set-output 3");
	system("fast-gpio set-output 11");
	system("fast-gpio set-output 18");
	system("fast-gpio set-output 19");
	system("fast-gpio set 0 0");
	system("fast-gpio set 1 1");
	system("fast-gpio set 2 0");
	system("fast-gpio set 3 0");
	system("fast-gpio set 11 1");
	system("fast-gpio set 19 1");
	system("fast-gpio set 18 0");

	int dirA = DIR_CW;
	int dirB = DIR_CW;

	string input;
	string delim = " ";
	int delimIndex = 0;

	cout << "## L A Z O R B 0 I ##" << endl;
	cout << "Type 'help' for usage information." << endl;

	// Command-line tool
	while (true) {
		cout << endl;
		cout << "> ";
		getline(cin, input);

		delimIndex = input.find(delim);
		string command = input.substr(0, delimIndex);
		string arg = input.erase(0, delimIndex + delim.length());

		// HELP
		if (command == "help") {
			cout << "[+] run <motor_number> // Starts motor number indicated" << endl;
			cout << "[+] reverse <motor_number> // Reverses motor number indicated" << endl;
			cout << "[+] stop <motor_number> // Stops motor number indicated" << endl;
			cout << "[+] quit //quits program and stops motors if running" << endl;
		}

		// RUN
		else if (command == "run") {
			if (arg == "1") {
				cout << "Ran 1" << endl;
				system("fast-gpio set 2 1");
			} else if (arg == "2") {
				cout << "Ran 2" << endl;
				system("fast-gpio set 3 1");
			} else if (arg == "all") {
				cout << "Ran all" << endl;
				system("fast-gpio set 2 1");
				system("fast-gpio set 3 1");
			} else {
				cout << "Usage: run <motor_number>" << endl;
			}
		}

		// REVERSE
		else if (command == "reverse") {
			if (arg == "1") {
				if (dirA == 0) {
					system("fast-gpio set 0 1");
					system("fast-gpio set 1 0");
					dirA = 1;
				} else {
					system("fast-gpio set 0 0");
					system("fast-gpio set 1 1");
					dirA = 0;
				}
			} else if (arg == "2") {
				if (dirB == 0) {
					system("fast-gpio set 19 0");
					system("fast-gpio set 18 1");
					dirB = 1;
				} else {
					system("fast-gpio set 19 1");
					system("fast-gpio set 18 0");
					dirB = 0;
				}
			} else if (arg == "3") {
				system("fast-gpio set 2 1");
				system("fast-gpio set 3 1");
			} else {
				cout << "Usage: reverse <motor_number>" << endl;
			}
		}

		// STOP
		else if (command == "stop") {
			if (arg == "1") {
				cout << "Stopped 1" << endl;
				system("fast-gpio set 2 0");
			} else if (arg == "2") {
				cout << "Stopped 2" << endl;
				system("fast-gpio set 3 0");
			} else if (arg == "all") {
				cout << "Stopped all" << endl;
				system("fast-gpio set 2 0");
				system("fast-gpio set 3 0");
			} else {
				cout << "Usage: stop <motor_number>" << endl;
			}
		}

		// QUIT
		else if (command == "quit") {
			system("fast-gpio set 2 0");
			system("fast-gpio set 3 0");
			break;
		}
	}
}
