#include <iostream>
#include "FragTrap.hpp"

int main() {
	FragTrap fragtrap1;
	FragTrap fragtrap2("FLAG");
	FragTrap fragtrap3(fragtrap2);
	FragTrap fragtrap4;
	fragtrap4 = fragtrap1;
	std::cout << "------------------------" << std::endl;

	fragtrap1.attack("target1");
	fragtrap1.takeDamage(3);
	fragtrap1.beRepaired(5);
	fragtrap1.highFivesGuys();
	std::cout << "------------------------" << std::endl;

	fragtrap2.attack("target2");
	fragtrap2.takeDamage(3);
	fragtrap2.beRepaired(5);
	fragtrap2.highFivesGuys();
	std::cout << "------------------------" << std::endl;

	fragtrap3.attack("target3");
	fragtrap3.takeDamage(5);
	fragtrap3.beRepaired(2);
	fragtrap3.highFivesGuys();
	std::cout << "------------------------" << std::endl;

	fragtrap4.attack("target4");
	fragtrap4.takeDamage(10);
	fragtrap4.beRepaired(3);
	fragtrap4.highFivesGuys();
	std::cout << "------------------------" << std::endl;

	return 0;
}