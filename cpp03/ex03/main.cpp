#include <iostream>
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap d1("D1");

	d1.attack("d2");
	d1.guardGate();
	d1.highFivesGuys();
	d1.whoAmI();
	d1.beRepaired(10);
}