#include "Zombie.hpp"

void randomChump(const std::string& name) {
	Zombie zombie;
	zombie.setName(name);
	zombie.announce();
}
