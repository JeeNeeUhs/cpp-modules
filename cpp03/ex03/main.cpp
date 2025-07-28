#include <iostream>
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap dt1("Diamond1");
	DiamondTrap dt2("Diamond2");

	dt1.whoAmI();
	dt2.whoAmI();

	dt1.attack("target1");
	dt2.takeDamage(5);
	dt2.beRepaired(3);
	dt2.highFivesGuys();

	return 0;
}