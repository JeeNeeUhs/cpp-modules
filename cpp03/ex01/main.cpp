#include <iostream>
#include "ScavTrap.hpp"

int main() {
	ScavTrap scavtrap1;
	ScavTrap scavtrap2("CL4P");
	ScavTrap scavtrap3(scavtrap2);
	ScavTrap scavtrap4;
	scavtrap4 = scavtrap1;
	std::cout << "-------------------------------------------" << std::endl;

	scavtrap1.attack("target");
	scavtrap2.takeDamage(1000);
	scavtrap2.attack("target2");
	scavtrap3.beRepaired(50);
	scavtrap4.takeDamage(5);
	scavtrap1.guardGate();
	std::cout << "-------------------------------------------" << std::endl;

	for (int i = 0; i < 50; ++i) {
		scavtrap1.attack("targetloop");
	}
	std::cout << "-------------------------------------------" << std::endl;

	return 0;
}
