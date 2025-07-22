#include <string>
#include <iostream>
#include "HumanB.hpp"
#include "HumanA.hpp"

int main() {
	Weapon sword("Sword");

	HumanA armedguy("Armed Guy", sword);
	HumanB unarmedguy("Unarmed Guy");

	armedguy.attack();
	unarmedguy.attack();

	unarmedguy.setWeapon(&sword);
	unarmedguy.attack();
	sword.setType("Axe");
	armedguy.attack();
	unarmedguy.attack();
}
