#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#include "utils.cpp"
#include "lazorboi.cpp"

const int DIR_CW = 0;
const int DIR_CCW = 1;
const int FREQ = 6000;
const string delim = " ";

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

	string input;
	int delimIndex = 0;
	int start = 0;
	int end;
	int dirA = DIR_CW;
	int dirB = DIR_CW;

	cout << "Welcome to" << endl;
	cout << ".__                                   ___.    _______   .__ " << endl;
	cout << "|  |  _____   ________  ____  _______ \\_ |__  \\   _  \\  |__|" << endl;
	cout << "|  |  \\__  \\  \\___   / /  _ \\ \\_  __ \\ | __ \\ /  /_\\  \\ |  |" << endl;
	cout << "|  |__ / __ \\_ /    / (  <_> ) |  | \\/ | \\_\\ \\\\  \\_/   \\|  |" << endl;
	cout << "|____/(____  //_____ \\ \\____/  |__|    |___  / \\_____  /|__|" << endl;
	cout << "           \\/       \\/                     \\/        \\/     " << endl;
	cout << "Type 'help' for usage information." << endl;

	// Command-line tool
	while (true) {
		cout << endl;
		cout << "> ";
		getline(cin, input);

		delimIndex = input.find(delim);
		string command = input.substr(0, delimIndex);
		string arg;
		string arg2;
		if (command.length() == input.length()) {
			arg = "\0";
			arg2 = "\0";
		} else {
			string args = input.erase(0, delimIndex + delim.length());
			int *iargs = getArgs(args, delim);
			arg = iargs[0];
			arg2 = iargs[1];
		}


		// HELP
		if (command == "help") {
			cout << "[+] run <motor_number> // Starts motor number indicated" << endl;
			cout << "[+] reverse <motor_number> // Reverses motor number indicated" << endl;
			cout << "[+] speed <motor_number> <speed> // Runs motor at a speed between 0 and 100" << endl;
			cout << "[+] stop <motor_number> // Stops motor number indicated" << endl;
			cout << "[+] quit // Quits program and stops motors if running" << endl;
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
			} else if (arg == "all") {
				system("fast-gpio set 2 1");
				system("fast-gpio set 3 1");
			} else {
				cout << "Usage: reverse <motor_number>" << endl;
			}
		}

		// SPEED
		else if (command == "speed") {
			string strArg;
			stringstream convert;
			convert << arg2;
			strArg = convert.str();

			if (arg == "1") {
				string pwm_command = "fast-gpio pwm 2 6000 " + strArg;
				cout << "Setting speed of motor 1 to " << arg2 << endl;
				const char *c_command = pwm_command.c_str();
				system(c_command);
			} else if (arg == "2") {
				string pwm_command = "fast-gpio pwm 3 6000 " + arg2;
				cout << "Setting speed of motor 2 to " << arg2 << endl;
				const char *c_command = pwm_command.c_str();
				system(c_command);
			} else if (arg == "all") {
				cout << "Setting all motor speeds to " << arg2 << endl;
				string pwm_command1 = "fast-gpio pwm 2 6000 " + arg2;
				string pwm_command2 = "fast-gpio pwm 3 6000 " + arg2;
				const char *c_command1 = pwm_command1.c_str();
				const char *c_command2 = pwm_command2.c_str();
				system(c_command1);
				system(c_command2);
			} else {
				cout << "Usage: speed <motor_number> <speed>" << endl;
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

		// STRING
		else if (command == "string") {
			//call function
			cout << "Not working yet" << endl;
		}

		// QUIT
		else if (command == "quit") {
			system("fast-gpio set 2 0");
			system("fast-gpio set 3 0");
			break;
		}
	}
}
