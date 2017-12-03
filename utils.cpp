#include "utils.h"

int map(int value, int preLowerBound, int preUpperbound, int postLowerBound, int postUpperbound){
		return (value - preLowerBound) * (postUpperbound - postLowerBound) / (preUpperbound - preLowerBound) + postLowerBound;
}

int* getArgs(string input, string delim){
	int delimIndex = 0;
	int *args = new int [2];
	delimIndex = input.find(delim);
	args[0] = stoi(input.substr(0, delimIndex));
	args[1] = stoi(input.erase(0, delimIndex + delim.length()));
	return args;
}
