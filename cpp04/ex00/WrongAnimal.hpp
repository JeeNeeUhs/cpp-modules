#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &other);

		WrongAnimal &operator=(const WrongAnimal &other);

		~WrongAnimal();

		const std::string &getType() const;
		void makeSound() const;
};

#endif