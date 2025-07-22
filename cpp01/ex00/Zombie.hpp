#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
	private:
		std::string name;
	public:
		~Zombie();

		void setName(const std::string& name);

		std::string getName() const;

		void announce() const;
};

Zombie* newZombie(const std::string& name);
void randomChump(const std::string& name);

#endif