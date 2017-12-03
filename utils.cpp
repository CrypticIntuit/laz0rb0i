#include "utils.h"

int map(int value, int preLowerBound, int preUpperbound, int postLowerBound, int postUpperbound){
		return (value - preLowerBound) * (postUpperbound - postLowerBound) / (preUpperbound - preLowerBound) + postLowerBound;
}
