//
// Factorial function
//
#include <iostream>
using namespace std;
#include "factorial.h"

int factorial(int nTarget) {
	int nAccumulator = 1;
	for (int nValue = 1; nValue <= nTarget; nValue++) {
		nAccumulator *= nValue;
	}
	return nAccumulator;
}