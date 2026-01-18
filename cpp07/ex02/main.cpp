#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

int main() {
	Array<int> intArray(5);
	for (unsigned int i = 0; i < intArray.size(); i++) {
		intArray[i] = i * 100;
	}

	std::cout << "Integer Array:" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << std::endl;
	}

	Array<std::string> strArray(5);
	strArray[0] = "deneme";
	strArray[1] = "1";
	strArray[2] = "2";
	strArray[3] = "deneme2";
	strArray[4] = "deneme3";

	std::cout << "String Array:" << std::endl;
	for (unsigned int i = 0; i < strArray.size(); i++) {
		std::cout << strArray[i] << std::endl;
	}

	try {
		std::cout << intArray[10] << std::endl;
	} catch (const std::out_of_range& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}