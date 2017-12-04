#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <cmath>
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
			string *iargs = getArgs(args, delim);
			arg = iargs[0];
			arg2 = iargs[1];
		}


		// HELP
		if (command == "help") {
			cout << "[+] run <motor_number> // Starts motor number indicated" << endl;
			cout << "[+] reverse <motor_number> // Reverses motor number indicated" << endl;
			cout << "[+] speed <motor_number> <speed> // Runs motor at a speed between 0 and 100" << endl;
			cout << "[+] string // Initiates a request to input a string to be visualized";
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
				if (dirB == 0) {
					system("fast-gpio set 0 1");
					system("fast-gpio set 1 0");
					dirB = 1;
				} else {
					system("fast-gpio set 0 0");
					system("fast-gpio set 1 1");
					dirB = 0;
				}
			} else if (arg == "2") {
				if (dirA == 0) {
					system("fast-gpio set 19 0");
					system("fast-gpio set 18 1");
					dirA = 1;
				} else {
					system("fast-gpio set 19 1");
					system("fast-gpio set 18 0");
					dirA = 0;
				}
			} else if (arg == "all") {
				if (dirB == 0) {
					system("fast-gpio set 0 1");
					system("fast-gpio set 1 0");
					dirB = 1;
				} else {
					system("fast-gpio set 0 0");
					system("fast-gpio set 1 1");
					dirB = 0;
				}
				if (dirA == 0) {
					system("fast-gpio set 19 0");
					system("fast-gpio set 18 1");
					dirA = 1;
				} else {
					system("fast-gpio set 19 1");
					system("fast-gpio set 18 0");
					dirA = 0;
				}
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
			cout << "Please input a string: ";
			string userIn;
			getline(cin, userIn);
			char* charArray = stoch(userIn);
			if (!isValid(charArray)){
				cout << "String entered is invalid. Make sure it only includes alphabetical characters and spaces." << endl;
				continue;
			}
			int index = 0;
			int speedA;
			int speedB;
			string strArgA;
			stringstream convertA;
			string strArgB;
			stringstream convertB;
			while (charArray[index + 1] != '\0') {
				dirA = getDir(charArray[index]);
				speedA = getSpeed(charArray[index]);
				dirB = getDir(charArray[index + 1]);
				speedB = getSpeed(charArray[index + 1]);
				convertA << speedA;
				strArgA = convertA.str();
				convertB << speedB;
				strArgB = convertB.str();
				if (dirA == 0) {
					system("fast-gpio set 0 1");
					system("fast-gpio set 1 0");
					dirA = 1;
				} else {
					system("fast-gpio set 0 0");
					system("fast-gpio set 1 1");
					dirA = 0;
				}
				if (dirB == 0) {
					system("fast-gpio set 19 0");
					system("fast-gpio set 18 1");
					dirB = 1;
				} else {
					system("fast-gpio set 19 1");
					system("fast-gpio set 18 0");
					dirB = 0;
				}
				string pwm_commandA = "fast-gpio pwm 3 6000 " + strArgA;
				cout << "Setting speed of motor 1 to " << speedA << endl;
				const char *c_commandA = pwm_commandA.c_str();
				system(c_commandA);
				string pwm_commandB = "fast-gpio pwm 2 6000 " + strArgB;
				cout << "Setting speed of motor 1 to " << speedB << endl;
				const char *c_commandB = pwm_commandB.c_str();
				system(c_commandB);
				usleep(2000000);
				index++;
			}
		}

		// SINUSOID
		else if (command == "sinusoid") {
			string amp1str;
			string amp2str;
			int amp1;
			int amp2;

			int index = 0;
			int speedA;
			int speedB;
			string strArgA;
			stringstream convertA;
			string strArgB;
			stringstream convertB;

			do{
				cout << "Please input an integer amplitude: ";
				cin >> amp1str;
				amp1 = stoint(amp1str);

				if (amp1 == -1)
					cout << "Invalid amplitude. Make sure its an integer and only includes digits." << endl;
			}while (amp1 == -1);

			do{
				cout << "Please input another integer amplitude: ";
				cin >> amp2str;
				amp2 = stoint(amp2str);

				if (amp2 == -1)
					cout << "Invalid amplitude. Make sure its an integer and only includes digits.";
			}while (amp2 == -1);

			for (int i = 0; i < 9999999; i++) {
				speedA = amp1 * sin(0.1 * i);
				speedB = -amp2 * cos(0.2 * i);
				if (speedA < 0){
					speedA = abs(speedA);
					dirA = 0;
				}
				else
					dirA = 1;
				if (speedB < 0){
					speedB = abs(speedB);
					dirB = 0;
				}
				else
					dirB = 1;

				speedA = map(speedA, 0, amp1, 10, 100);
				speedB = map(speedB, 0, amp2, 10, 100);

				convertA << speedA;
				strArgA = convertA.str();
				convertB << speedB;
				strArgB = convertB.str();

				if (dirA == 0) {
					system("fast-gpio set 1 0");
				} else {
					system("fast-gpio set 1 1");
				}
				if (dirB == 0) {
					system("fast-gpio set 19 0");
				} else {
					system("fast-gpio set 19 1");
				}

				string pwm_commandA = "fast-gpio pwm 3 14000 " + strArgA;
				cout << "Setting speed of motor 1 to " << speedA << endl;
				const char *c_commandA = pwm_commandA.c_str();
				system(c_commandA);
				string pwm_commandB = "fast-gpio pwm 2 14000 " + strArgB;
				cout << "Setting speed of motor 1 to " << speedB << endl;
				const char *c_commandB = pwm_commandB.c_str();
				system(c_commandB);
				usleep(500000);

				system("fast-gpio pwm 2 14000 0");
				system("fast-gpio pwm 3 14000 0");
				usleep(500000);
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
