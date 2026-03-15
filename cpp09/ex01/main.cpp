#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2 || std::string(argv[1]).empty()) {
		std::cerr << "Invalid argument" << std::endl;
		return 1;
	}
	
	RPN rpn(argv[1]);
	rpn.calc();

	return 0;
}