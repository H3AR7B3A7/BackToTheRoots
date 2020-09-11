//
// Passing arguments by reference compared to by value
//
#include <iostream>
using namespace std;
#include "passByReference.h"

void passByValue(int nArg1, int nArg2) {
	nArg1 = 10;
	nArg2 = 20;
}

void passByReference(int* pnArg1, int* pnArg2) {
	*pnArg1 = 10;
	*pnArg2 = 20;
}