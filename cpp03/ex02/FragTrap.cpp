#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap " << name << " created with default constructor." << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap " << name << " created with parameterized constructor." << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap " << name << " created with copy constructor." << std::endl;
	*this = other;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " destroyed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "FragTrap " << name << " assigned from another FragTrap." << std::endl;
	}
	return *this;
}

void FragTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout << "FragTrap " << name << " attacks " << target 
				  << ", causing " << attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "FragTrap " << name << " cannot attack!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " requests high five!" << std::endl;
}
