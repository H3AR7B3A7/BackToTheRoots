//
// Concatenate 2 strings in heap memory
//
#include <iostream>

using namespace std;
#include "concatenateInHeap.h"

// By incrementing array integer
char* concatenateString(const char szSrc1[], const char szSrc2[]) {
	// Allocate adaptable sized array in heap at runtime
	int nTargetSize = strlen(szSrc1) + strlen(szSrc2) + 2; // +1 -> +2: longer strings removed endl after call
	char* pszTarget = new char[nTargetSize];

	// szSrc1 to target
	int nT;
	for (nT = 0; szSrc1[nT] != '\0'; nT++) {
		pszTarget[nT] = szSrc1[nT];
	}

	// szSrc2 to target
	for (int nS = 0; szSrc2[nS] != '\0'; nT++, nS++) {
		pszTarget[nT] = szSrc2[nS];
	}

	// Add terminator to target
	pszTarget[nT] = '\0';

	// Return concatenated strings
	return pszTarget;

}

// By incrementing pointer
char* concatenateIncrementingPointer(const char* pszSrc1, const char* pszSrc2) {
	// Allocate adaptable sized array in heap at runtime
	int nTargetSize = strlen(pszSrc1) + strlen(pszSrc2) + 1;
	char* pszTarget = new char[nTargetSize];

	// *pszSrc1 to target pointer
	char* pszT = pszTarget;
	for (; *pszSrc1 != '\0'; pszT++, pszSrc1++) {
		*pszT = *pszSrc1;
	}

	// *pszSrc2 to target pointer
	for (; *pszSrc2 != '\0'; pszT++, pszSrc2++) {
		*pszT = *pszSrc2;
	}

	*pszT = '\0'; // No warnings using pointer increment

	// Return concatenated strings
	return pszTarget;
}