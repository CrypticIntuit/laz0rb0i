#include <iostream>
#include <stdlib.h>
#include "lib/portaudio.h"

using namespace std;
typedef int PaStreamCallback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData){

}
int main() {
    err = Pa_Initialize();

    err = Pa_Terminate();
    return 0;
}
