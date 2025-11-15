#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	{
		Bureaucrat bureaucrat("John Doe", 42);
		Form form("Form", 50, 75);
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		try {
			bureaucrat.signForm(form);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << form << std::endl;
	}
	{
		Bureaucrat bureaucrat("Jane Doe", 100);
		Form form("orm", 90, 120);
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		try {
			bureaucrat.signForm(form);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << form << std::endl;
	}
	return 0;
}