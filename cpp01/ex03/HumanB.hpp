#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon* weapon;
	public:
		HumanB(std::string name);
		void setWeapon(Weapon& weapon);
		std::string getName() const;
		void attack() const;
};

#endif