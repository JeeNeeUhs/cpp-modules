#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
	
	return 0;
}