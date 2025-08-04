#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& other);

		virtual ~Animal();

		Animal& operator=(const Animal& other);
		
		const std::string& getType() const;
		virtual void makeSound() const = 0;
};

#endif