#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);

		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& other);

		void guardGate();
		void attack(const std::string& target);
};

#endif
