#include <iostream>
#include "FragTrap.hpp"

int main() {
	FragTrap fragtrap1;
	FragTrap fragtrap2("FLAG");
	FragTrap fragtrap3(fragtrap2);
	FragTrap fragtrap4;
	fragtrap4 = fragtrap1;
	std::cout << "------------------------" << std::endl;

	fragtrap1.attack("target");
	fragtrap2.takeDamage(1000);
	fragtrap2.attack("target2");
	fragtrap3.beRepaired(50);
	fragtrap4.takeDamage(5);
	fragtrap1.highFivesGuys();
	std::cout << "------------------------" << std::endl;

	for (int i = 0; i < 100; ++i) {
		fragtrap1.attack("targetloop");
	}
	std::cout << "------------------------" << std::endl;
	
	return 0;
}