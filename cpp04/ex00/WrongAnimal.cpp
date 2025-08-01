#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type) {
	std::cout << "WrongAnimal parameterized constructor called with type: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

const std::string &WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Random wrong animal sound" << std::endl;
}

