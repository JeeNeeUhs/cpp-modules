#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits>

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
	if (input.length() == 1 && !isdigit(input[0]) && isprint(input[0]))
		return CHAR; 
	if (input.find_first_not_of("0123456789+-.f") == std::string::npos && keyDedect(input, '.') && !input.empty() && 
		getLastIndexOfChar(input) == 'f' && stringCounter(input, 'f') == 1 && stringCounter(input, '.') == 1 &&
		input[input.length() - 2] != '.')
		return FLOAT;
	if (input.find_first_not_of("0123456789+-.") == std::string::npos && keyDedect(input, '.') && !input.empty() && 
		stringCounter(input, '.') == 1 && getLastIndexOfChar(input) != '.')
		return DOUBLE;
	if (input.find_first_not_of("0123456789+-") == std::string::npos)
		return INT;
	return INVALID;
}

static void printChar(char c) {
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void printNumber(int num, int overflow) {
	// print char
	if (num < 0 || num > 127 || overflow)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(num)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;

	// print int
	if (overflow)
		std::cout << "int: impossible" << std::endl;
	else 
		std::cout << "int: " << num << std::endl;

	// print float
	if (overflow)
		std::cout << "float: logicly wrong" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;

	// print double
	if (overflow)
		std::cout << "double: logicly wrong" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

static void printNumber(float num, int overflow) {
	// print char
	if (num < 0 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(num)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;

	// print int
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else 
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	// print float
	if (num < -std::numeric_limits<float>::max())
		std::cout << "float: -inff" << std::endl;
	else if (num > std::numeric_limits<float>::max())
		std::cout << "float: +inff" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;

	// print double
	if (overflow)
		std::cout << "double: logicly wrong" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

static void printNumber(double num) {
	// print char
	if (num < 0 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(num)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;

	// print int
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else 
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	// print float
	if (num < -std::numeric_limits<float>::max())
		std::cout << "float: -inff" << std::endl;
	else if (num > std::numeric_limits<float>::max())
		std::cout << "float: +inff" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;

	// print double
	if (num < -std::numeric_limits<double>::max())
		std::cout << "double: -inf" << std::endl;
	else if (num > std::numeric_limits<double>::max())
		std::cout << "double: +inf" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << num << std::endl;
}

static void printPesudo(std::string input) {
	// print char
	std::cout << "char: impossible" << std::endl;

	// print int
	std::cout << "int: impossible" << std::endl;

	// print float
	if (input == "nan" || input == "nanf")
		std::cout << "float: nanf" << std::endl;
	else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
		std::cout << "float: +inff" << std::endl;
	else if (input == "-inf" || input == "-inff")
		std::cout << "float: -inff" << std::endl;

	// print double
	if (input == "nan" || input == "nanf")
		std::cout << "double: nan" << std::endl;
	else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
		std::cout << "double: +inf" << std::endl;
	else if (input == "-inf" || input == "-inff")
		std::cout << "double: -inf" << std::endl;
}

void ScalarConverter::convert(const std::string input) {
	int type = getType(input);
	int overflow;
	long templ;
	long double templd;

	switch (type) {
		case CHAR:
			printChar(input[0]);
			break;
		case INT:
			templ = strtol(input.c_str(), NULL, 10);
			if (templ < std::numeric_limits<int>::min() || templ > std::numeric_limits<int>::max())
				overflow = 1;
			else
				overflow = 0;
			printNumber(atoi(input.c_str()), overflow);
			break;
		case FLOAT:
			templd = strtold(input.c_str(), NULL);
			if (templd < -std::numeric_limits<float>::max() || templd > std::numeric_limits<float>::max())
				overflow = 1;
			else
				overflow = 0;
			printNumber(strtof(input.c_str(), NULL), overflow);
			break;
		case DOUBLE:
			printNumber(strtod(input.c_str(), NULL));
			break;
		case PSEUDO:
			printPesudo(input);
			break;
		default:
			std::cout << "Error: Invalid input" << std::endl;
	}
}
