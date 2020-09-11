//
// C++ConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
// My first console application learning to code C++
//

// Package headers to include
#include <iostream>
#include <string>
#include <cstring> // <string> prefered, but VS code asks for use of strcpy_s

// Namespace to use for all in/outputs
using namespace std;

// Application headers to include
#include "factorial.h"
#include "passByReference.h"
#include "concatenateInHeap.h"
#include "Contact.h"

string greeting = "Hello Universe!\n";

int main()
{
    // Print greeting from global scope
    cout << greeting << endl;

    // Calculate factorial using method in other sourcefile
    cout << "Calculating factorials, enter a negative value to quit..." << endl;
    for (;;) {
        int nValue;

        cout << "Enter number: ";
        cin >> nValue;

        if (nValue < 0) {
            break;
        }

        int nFactorial = factorial(nValue);
        cout << nValue << " factorial is " << nFactorial << endl;
    }

    // Initiate and display 2 values
    int nValue1 = 1;
    int nValue2 = 2;
    cout << "nValue1 initialised to " << nValue1 << endl;
    cout << "nValue2 initialised to " << nValue2 << endl;

    // Compare passing arguments to functions by value and by reference
    cout << "Passed arguments by value:" << endl;
    passByValue(nValue1, nValue2);
    cout << "The value of the arguments = " << nValue1 << " and " << nValue2 << endl;

    cout << "Passed arguments by reference:" << endl;
    passByReference(&nValue1, &nValue2);
    cout << "The value of the arguments = " << nValue1 << " and " << nValue2 << endl;

    // Create copy of string in heap memory
    char cTest[] = "test";
    int nLength = strlen(cTest) + 1;
    char* pCopy = new char[nLength];
    strcpy_s(pCopy, nLength, cTest); // _s: safe version from microsoft's <string> will compile in VS-code, but not with MinGW
    cout << "Printing " << pCopy << " from the heap" << endl;

    // Cleaning up heap memory !!!
    delete[] pCopy;
    pCopy = NULL;
    cout << "Returned memory to heap!" << endl;

    // Create and input 2 strings
    cout << "Concatenating 2 strings for you:" << endl;
    char szString1[256], szString2[256];
    
    cin.ignore();   // because of mixed usage with: cin >> nValue;
    cin.clear();    // ignore() & clear() solves bugs with mixed usage
    cout << "Enter first string: " << endl;
    cin.getline(szString1,256);
    
    
    cin.clear();
    cout << "Enter second string: " << endl;
    cin.getline(szString2,256);

    // Concatenate strings
    char* pszT = concatenateString(szString1, szString2);
    cout << "Result by incrementing array integer: " << pszT << endl;

    // Concatenate strings
    pszT = concatenateIncrementingPointer(szString1, szString2);
    cout << "Result by incrementing pointer: " << pszT << endl;

    // Cleaning up heap memory
    delete[] pszT;
    pszT = NULL;
    cout << "Returned memory to heap!" << endl;

    // Make room for Contact class to create objects
    Contact contacts[128];

    // Create some contacts
    cout << "Input your contacts:" << endl;
    int nCount = getContacts(contacts, 128);

    // Sorts only integers apparantly - fix at some later time
    sortContacts(contacts, nCount);

    cout << "Your sorted contacts:" << endl;
    showAllContacts(contacts, nCount);

    // Pause to see results
    system("PAUSE");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
