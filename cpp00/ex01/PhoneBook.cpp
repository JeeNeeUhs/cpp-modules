#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : contactCount(0), contactOverwrite(0) {}

void PhoneBook::addContact(const Contact& contact) {
	if (contactCount < 8) {
		contacts[contactCount] = contact;
		contactCount++;
	} else {
		contacts[contactOverwrite] = contact;
		contactOverwrite = (contactOverwrite + 1) % 8;
	}
}

static std::string formatField(const std::string& field) {
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void PhoneBook::displayContacts() const {
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < contactCount; ++i) {
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
				  << std::setw(10) << formatField(contacts[i].getNickName()) << std::endl;
	}
}

void PhoneBook::displayContact(int index) const {
	if (index < 0 || index >= contactCount) {
		std::cout << "Invalid index." << std::endl;
		return;
	}

	const Contact& contact = contacts[index];
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickName() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

int PhoneBook::getContactCount() const {
	return contactCount;
}