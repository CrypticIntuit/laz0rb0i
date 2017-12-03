#include <cmath>

bool isValid(string input){
    for (int i = 0; i < input.length(); i++){
        char temp = toupper(input[i]);
        cout << "uppered: " << temp << endl;
        if (!(temp >= 'A' && temp <= 'Z') ^ temp == ' ')
            return false;
    }
    return true;
}

int getDir(char input){
    int value = (int) input;
    int count = 0;
    while(value){
        count += value & 1;
        value >>= 1;
    }

    int dir = count % 2;
    return dir;
}

int getSpeed(char input){
    int value = toupper(input);
    int posInAlphabet = abs(value - 64);

    int speed = (int) ((value * posInAlphabet) / (3.14159 * 26));

    int lowerBound = (int) ((65 * 1) / (3.14159 * 26));
    int upperBound = (int) ((90 * 26) / (3.14159 * 26));

    speed = map(speed, lowerBound, upperBound, 20, 95);
    return speed;
}
