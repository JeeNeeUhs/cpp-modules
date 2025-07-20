#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command)) {
			return 1;
		}

		if (command == "ADD") {
			Contact contact;
			std::string input;

			std::cout << "First Name: ";
			while (true) {
				if (!std::getline(std::cin, input)) {
					return 1;
				}
				if (!input.empty()) {
					contact.setFirstName(input);
					break;
				}
				std::cout << "First Name cannot be empty. Try again: ";
			}

			std::cout << "Last Name: ";
			while (true) {
				if (!std::getline(std::cin, input)) {
					return 1;
				}
				if (!input.empty()) {
					contact.setLastName(input);
					break;
				}
				std::cout << "Last Name cannot be empty. Try again: ";
			}

			std::cout << "Nickname: ";
			while (true) {
				if (!std::getline(std::cin, input)) {
					return 1;
				}
				if (!input.empty()) {
					contact.setNickName(input);
					break;
				}
				std::cout << "Nickname cannot be empty. Try again: ";
			}

			std::cout << "Phone Number: ";
			while (true) {
				if (!std::getline(std::cin, input)) {
					return 1;
				}
				if (!input.empty()) {
					contact.setPhoneNumber(input);
					break;
				}
				std::cout << "Phone Number cannot be empty. Try again: ";
			}

			std::cout << "Darkest Secret: ";
			while (true) {
				if (!std::getline(std::cin, input)) {
					return 1;
				}
				if (!input.empty()) {
					contact.setDarkestSecret(input);
					break;
				}
				std::cout << "Darkest Secret cannot be empty. Try again: ";
			}

			phoneBook.addContact(contact);
		} else if (command == "SEARCH") {
			if (phoneBook.getContactCount() == 0) {
				std::cout << "Contacts Not Found" << std::endl;
				continue;
			}

			phoneBook.displayContacts();

			std::cout << "Enter index to view details: ";
			int index;
			std::cin >> index;

			// Giriş başarısızsa (harf, boşluk vs. girilirse)
			if (std::cin.fail()) {
				std::cin.clear(); // error durumunu sıfırla
				std::cin.ignore(); // tamponu temizle
				std::cout << "Invalid index" << std::endl;
				continue;
			}

			std::cin.ignore(); // \n karakterini temizle

			// Geçerli index mi kontrol et
			if (index < 0 || index >= phoneBook.getContactCount()) {
				std::cout << "Invalid index" << std::endl;
				continue;
			}

			phoneBook.displayContact(index);
		} else if (command == "EXIT") {
			break;
		} else if (command.empty()) {
			continue;
		} else {
			std::cout << "Unknown command." << std::endl;
		}
	}
	return 0;
}
