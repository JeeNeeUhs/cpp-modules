#include <iostream>
#include "iter.hpp"

template<typename T>
void	addAndPrint(T & element) {
	element++;
	std::cout << element << std::endl;
}

template<typename T>
void	justPrint(const T & element) {
	std::cout << element << std::endl;
}

int main() {
	int			intArray[] = {1, 2, 3, 4, 5};
	char		charArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::string	strArray[] = {"hello", "world", "this", "is", "C++"};

	std::cout << "Original int array:" << std::endl;
	iter(intArray, 5, justPrint<int>);
	std::cout << "After adding 1 to each element:" << std::endl;
	iter(intArray, 5, addAndPrint<int>);

	std::cout << "\nOriginal char array:" << std::endl;
	iter(charArray, 5, justPrint<char>);
	std::cout << "After adding 1 to each element:" << std::endl;
	iter(charArray, 5, addAndPrint<char>);

	std::cout << "\nString array:" << std::endl;
	iter(strArray, 5, justPrint<std::string>);

	return 0;

}
