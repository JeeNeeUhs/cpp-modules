#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(const std::string& name) {
	Zombie* zombie = new Zombie();
	zombie->setName(name);
	return zombie;
}
