#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), name("Default") {
	std::cout << "DiamondTrap " << name << " created with default constructor." << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), name(name) {
	std::cout << "DiamondTrap " << this->name << " created with parameterized constructor." << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other.ClapTrap::name), FragTrap(other), ScavTrap(other), name(other.name) {
	std::cout << "DiamondTrap " << name << " created with copy constructor." << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name << " destroyed." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		name = other.name;
		std::cout << "DiamondTrap " << name << " assigned from another DiamondTrap." << std::endl;
	}
	return *this;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << "." << std::endl;
}
