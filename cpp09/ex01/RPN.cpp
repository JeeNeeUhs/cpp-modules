#include "RPN.hpp"
#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN &copy) {
	this->numbers = copy.numbers;
	this->str = copy.str;
}

RPN::RPN(std::string str) : str(str) {}

RPN &RPN::operator=(const RPN &copy) {
	if (this != &copy) {
		this->numbers = copy.numbers;
		this->str = copy.str;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::calc() {
	std::stack<int>& numbers = this->numbers;
	std::string& str = this->str;

	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			continue;
		if (str[i] >= '0' && str[i] <= '9')
			numbers.push(str[i] - '0');
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			if (numbers.size() < 2) {
				std::cerr << "Not enough operands" << std::endl;
				return;
			}
			int a = numbers.top();
			numbers.pop();
			int b = numbers.top();
			numbers.pop();
			int result;
			switch (str[i]) {
				case '+':
					result = b + a;
					break;
				case '-':
					result = b - a;
					break;
				case '*':
					result = b * a;
					break;
				case '/':
					if (a == 0) {
						std::cerr << "Can not divide by zero" << std::endl;
						return;
					}
					result = b / a;
					break;
				}
			numbers.push(result);
		}
	}
	std::cout << numbers.top() << std::endl;
}
