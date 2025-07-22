#include <sstream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, const std::string& name) {
	std::stringstream ss;
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		ss << name << " " << (i + 1);
		horde[i].setName(ss.str());
		ss.str("");
		ss.clear();
	}
	return horde;

}