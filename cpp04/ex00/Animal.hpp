#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& other);

		~Animal();

		Animal& operator=(const Animal& other);

		virtual void makeSound() const;
};

#endif