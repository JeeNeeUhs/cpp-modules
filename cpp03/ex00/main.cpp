#include <iostream>
#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap1;
	ClapTrap claptrap2("CL4P");
	ClapTrap claptrap3(claptrap2);
	ClapTrap claptrap4;
	claptrap4 = claptrap1;
	std::cout << "-------------------------------------------" << std::endl;

	claptrap1.attack("target");
	claptrap2.takeDamage(1000);
	claptrap2.attack("target2");
	claptrap3.beRepaired(50);
	claptrap4.takeDamage(5);
	std::cout << "-------------------------------------------" << std::endl;

	for (int i = 0; i < 10; ++i) {
		claptrap1.attack("targetloop");
	}
	std::cout << "-------------------------------------------" << std::endl;

	return 0;
}