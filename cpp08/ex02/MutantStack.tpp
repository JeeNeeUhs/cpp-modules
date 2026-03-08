#include "MutantStack.hpp"
#include <iostream>

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T>& mutantStack) {
	os << "MutantStack (bottom to top): " << std::endl;
	for (typename MutantStack<T>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
		os << *it << std::endl;
	}
	return os;
}
