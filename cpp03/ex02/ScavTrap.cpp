#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap " << name << " created with default constructor." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << name << " created with parameterized constructor." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap " << name << " created with copy constructor." << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " destroyed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap " << name << " assigned from another ScavTrap." << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate Keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout << "ScavTrap " << name << " attacks " << target 
				  << ", causing " << attackDamage << " points of damage!" << std::endl;
		hitPoints -= attackDamage;
	} else {
		std::cout << "ScavTrap " << name << " cannot attack!" << std::endl;
	}
}



