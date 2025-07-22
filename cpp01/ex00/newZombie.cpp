#include "Zombie.hpp"
#include <iostream>

Zombie::~Zombie() {
	std::cout << "Zombie named by " << name << " is destroyed." << std::endl;
}

Zombie* newZombie(const std::string& name) {
	Zombie* zombie = new Zombie();
	zombie->setName(name);
	return zombie;
}
