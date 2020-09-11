//
// Contact
//
#include <iostream>
using namespace std;
#include "Contact.h"

Contact createContact() {
	Contact contact;

	cout << "First name: ";
	cin >> contact.firstName;

	cout << "Last name: ";
	cin >> contact.lastName;

	cout << "Phone number: ";
	cin >> contact.phoneNumber;

	return contact;
}

int getContacts(Contact contacts[], int nMaxSize) {
	int index;
	for (index = 0; index < nMaxSize; index++) {
		char cAnswer;
		cout << "Enter another Contact? [Y/N]";
		cin >> cAnswer;

		if (cAnswer != 'Y' && cAnswer != 'y') {
			break;
		}

		contacts[index] = createContact();
	}
	return index;
}

void showContact(Contact contact) {
	cout << "First name: " << contact.firstName << endl;
	cout << "Last name: " << contact.lastName << endl;
	cout << "Phone number: " << contact.phoneNumber << endl;
}

void showAllContacts(Contact contacts[], int nCount) {
	for (int index = 0; index < nCount; index++) {
		showContact(contacts[index]);
	}
}

void sortContacts(Contact contacts[], int nCount) {
	// Loop
	int nSwaps = 1;
	while (nSwaps != 0) {
		nSwaps = 0;

		// Iterate contacts
		for (int n = 0; n < (nCount - 1); n++) {
			// Compare
			if (contacts[n].firstName > contacts[n + 1].firstName) {
				// Swap
				Contact temp = contacts[n + 1];
				contacts[n + 1] = contacts[n];
				contacts[n] = temp;
				// Make loop repeat
				nSwaps++;
			}
		}
	}
}