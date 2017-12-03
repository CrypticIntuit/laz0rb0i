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

char* stoch(string x){
    char* array = new char[x.length() + 1];
    for (int i =0; i<x.length();i++)
        array[i] = x[i];
    array[x.length()] = '\0';
    return array;
}
