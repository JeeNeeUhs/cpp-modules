#include <iostream>
#include "Zombie.hpp"

int main() {
	Zombie* zombie1;
	Zombie* zombie2;

	zombie1 = newZombie("Zombilal");
	zombie2 = newZombie("Zombob");

	zombie1->announce();
	zombie2->announce();

	randomChump("Zombihan");

	delete zombie1;
	delete zombie2;

	return 0;
}