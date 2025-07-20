#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int contactCount;
	int contactOverwrite;

public:
	PhoneBook();

	void addContact(const Contact& contact);
	void displayContacts() const;
	void displayContact(int index) const;
	int getContactCount() const;
};

#endif