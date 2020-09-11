#pragma once
class Contact {
public:
	char firstName[128];
	char lastName[128];
	char phoneNumber[128];
};
Contact createContact();
int getContacts(Contact contacts[], int nMaxSize);
void showContact(Contact contact);
void showAllContacts(Contact contacts[], int nCount);
void sortContacts(Contact contacts[], int nCount);