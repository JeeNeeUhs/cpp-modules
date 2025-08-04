#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog(*static_cast<Dog*>(animals[0]));
	animals[3] = new Cat(*static_cast<Cat*>(animals[1]));
	std::cout << "----------------------------------------------------------" << std::endl;

	for (int i = 0; i < 4; ++i) {
		std::cout << "Animal type: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}
	std::cout << "----------------------------------------------------------" << std::endl;

	for (int i = 0; i < 4; ++i) {
		delete animals[i];
	}
	std::cout << "----------------------------------------------------------" << std::endl;

	Dog dog;

	dog.makeSound();
	dog.getBrain()->setIdea(0, "Fetch the ball");
	std::cout << "Dog's first idea: " << dog.getBrain()->getIdea(0) << std::endl;

	return 0;
}
