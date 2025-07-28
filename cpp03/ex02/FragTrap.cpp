#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ScavTrap("Default FragTrap") {
	std::cout << "FragTrap " << name << " created with default constructor." << std::endl;
}
FragTrap::FragTrap(std::string name) : ScavTrap(name) {
	std::cout << "FragTrap " << name << " created with parameterized constructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ScavTrap(other) {
	std::cout << "FragTrap " << name << " created with copy constructor." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " destroyed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ScavTrap::operator=(other);
		std::cout << "FragTrap " << name << " assigned from another FragTrap." << std::endl;
	}
	return *this;
}


void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " requests high five!" << std::endl;
}