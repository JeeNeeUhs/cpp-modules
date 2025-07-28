#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ScavTrap {
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& other);
	
	~FragTrap();

	FragTrap& operator=(const FragTrap& other);

	void highFivesGuys(void);
};

#endif