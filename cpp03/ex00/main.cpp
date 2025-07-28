#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap1;
	ClapTrap claptrap2("CL4P");
	ClapTrap claptrap3(claptrap2);
	ClapTrap claptrap4;
	claptrap4 = claptrap1;

	claptrap1.attack("target1");
	claptrap1.takeDamage(3);
	claptrap1.beRepaired(5);
	
	claptrap2.attack("target2");
	claptrap2.takeDamage(3);
	claptrap2.beRepaired(5);
	
	claptrap3.attack("target3");
	claptrap3.takeDamage(5);
	claptrap3.beRepaired(2);
	
	claptrap4.attack("target4");
	claptrap4.takeDamage(10);
	claptrap4.beRepaired(3);
}