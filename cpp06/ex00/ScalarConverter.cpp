#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static int keyDedect(std::string input, char key) {
	if (input.find(key) != std::string::npos)
		return 1;
	return 0;
}

static int isPesudoLiteral(std::string input) {
	if (input == "nan" || input == "+inf" || input == "-inf" ||
		input == "nanf" || input == "+inff" || input == "-inff")
		return 1;
	return 0;
}

static int getType(std::string input) {
	if (isPesudoLiteral(input))
		return 5; // double for pesudo literals
	if (input.length() == 1 && !isdigit(input[0]))
		return 1; // char
	if (keyDedect(input, '.') && !input.empty() && input[input.length() - 1] == 'f' && input.find('.') != input.length() - 1)
		return 3; // float
	if (keyDedect(input, '.') && input.find('.') != input.length() - 1)
		return 4; // double
	if (input.find_first_not_of("0123456789+-") == std::string::npos)
		return 2; // int
	return 0; // unknown
}

void ScalarConverter::convert(const std::string input) {
	int type = getType(input);
	if (type == 0) {
		std::cout << "Error: Unknown type" << std::endl;
		return;
	}
	if (type == 5) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (input[input.length() - 1] == 'f') {
			std::cout << "float: " << input << std::endl;
			std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
		} else {
			std::cout << "float: " << input << "f" << std::endl;
			std::cout << "double: " << input << std::endl;
		}
		return;
	}
	if (type == 1) {
		char c = input[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	} else if (type == 2) {
		int i = std::atoi(input.c_str());
		if (i >= 32 && i <= 126)
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	} else if (type == 3) {
		float f = std::atof(input.c_str());
		if (f >= 32 && f <= 126)
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	} else if (type == 4) {
		double d = std::atof(input.c_str());
		if (d >= 32 && d <= 126)
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	
	
}