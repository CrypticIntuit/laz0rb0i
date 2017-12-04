int map(int value, int preLowerBound, int preUpperbound, int postLowerBound, int postUpperbound){
	return (value - preLowerBound) * (postUpperbound - postLowerBound) / (preUpperbound - preLowerBound) + postLowerBound;
}

string* getArgs(string input, string delim){
	int delimIndex = 0;
	string *args = new string [2];
	delimIndex = input.find(delim);
	args[0] = input.substr(0, delimIndex);
	args[1] = input.erase(0, delimIndex + delim.length());
	return args;
}

char* stoch(string x){
	char* array = new char[x.length() + 1];
	for (int i =0; i<x.length(); i++)
		array[i] = x[i];
	array[x.length()] = '\0';
	return array;
}

enum STATE {START, DIGIT, TERMINAL};
int stoint(string x){
	char* input = stoch(x);
	int output = 0;

	STATE state = START;
	char in;
    cout << endl;
	for (int i = 0; state != TERMINAL; i++){
		in = input[i];

		switch (state){
		case START:
			if (in >= '0' && in <= '9'){
				output = (int) (in - '0');
				state = DIGIT;
			}
			else
				return -1;
			break;
		case DIGIT:
			if (in >= '0' && in <= '9')
				output = output * 10 + (int) (in - '0');
			else if (in == '\0')
				return output;
			else
				return -1;
			break;
		}
	}
}
