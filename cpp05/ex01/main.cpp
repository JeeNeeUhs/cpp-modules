#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat john("John", 50);
	Form taxForm("Tax Form", 45, 30);
	std::cout << john << std::endl;
	std::cout << taxForm << std::endl;
	john.signForm(taxForm);
	return 0;
}