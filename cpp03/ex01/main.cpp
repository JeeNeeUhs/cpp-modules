#include <iostream>
#include "ScavTrap.hpp"

int main() {
	ScavTrap scavtrap1;
	ScavTrap scavtrap2("SC4V");
	ScavTrap scavtrap3(scavtrap2);
	ScavTrap scavtrap4;
	scavtrap4 = scavtrap1;
	std::cout << "------------------------" << std::endl;

	scavtrap1.attack("target1");
	scavtrap1.takeDamage(3);
	scavtrap1.beRepaired(5);
	scavtrap1.guardGate();
	std::cout << "------------------------" << std::endl;

	scavtrap2.attack("target2");
	scavtrap2.takeDamage(3);
	scavtrap2.beRepaired(5);
	scavtrap2.guardGate();
	std::cout << "------------------------" << std::endl;

	scavtrap3.attack("target3");
	scavtrap3.takeDamage(5);
	scavtrap3.beRepaired(2);
	scavtrap3.guardGate();
	std::cout << "------------------------" << std::endl;

	scavtrap4.attack("target4");
	scavtrap4.takeDamage(10);
	scavtrap4.beRepaired(3);
	scavtrap4.guardGate();
	std::cout << "------------------------" << std::endl;

	return 0;
}