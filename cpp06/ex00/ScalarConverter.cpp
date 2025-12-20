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
	if (input == "nan" || input == "+inf" || input == "-inf" || input == "inf" ||
		input == "nanf" || input == "+inff" || input == "-inff" || input == "inff")
		return 1;
	return 0;
}

static int stringCounter(std::string input, char key) {
	int count = 0;
	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] == key)
			count++;
	}
	return count;
}

static char getLastIndexOfChar(std::string input) {
	return input[input.length() - 1];
}
	

static int getType(std::string input) {
	if (isPesudoLiteral(input))
		return PSEUDO;
	if (input.length() == 1 && !isdigit(input[0]))
		return CHAR; 
	if (input.find_first_not_of("0123456789+-.f")  && keyDedect(input, '.') && !input.empty() && 
		getLastIndexOfChar(input) == 'f' && stringCounter(input, 'f') == 1 && stringCounter(input, '.') == 1 &&
		input[input.length() - 2] != '.')
		return FLOAT;
	if (input.find_first_not_of("0123456789+-.")  && keyDedect(input, '.') && !input.empty() && 
		stringCounter(input, '.') == 1 && getLastIndexOfChar(input) != '.')
		return DOUBLE;
	if (input.find_first_not_of("0123456789+-") == std::string::npos)
		return INT;
	return INVALID;
}

void ScalarConverter::convert(const std::string input) {
	int type = getType(input);
	if (type == INVALID) {
		std::cout << "Error: Unknown type" << std::endl;
		return;
	}
	if (type == PSEUDO) {
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
	if (type == CHAR) {
		char c = input[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	} else if (type == INT) {
		long i = std::atol(input.c_str());
		if (i >= 32 && i <= 126)
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		else if (i >= 0 && i < 256)
			std::cout << "char: Non displayable" << std::endl;
		else 
			std::cout << "char: impossible" << std::endl;
		if (i < INT32_MIN || i > INT32_MAX)
			std::cout << "int: impossible" << std::endl;
		else 
			std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	} else if (type == FLOAT) {
		float f = std::atof(input.c_str());
		if (f >= 32 && f <= 126)
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		else if (f >= 0 && f < 256)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	} else if (type == DOUBLE) {
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
