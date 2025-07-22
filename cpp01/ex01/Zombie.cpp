#include <iostream>
#include "Zombie.hpp"

Zombie::~Zombie() {
	std::cout << "Zombie named by " << name << " is destroyed." << std::endl;
}

void Zombie::announce() const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name) {
	this->name = name;
}

std::string Zombie::getName() const {
	return name;
}