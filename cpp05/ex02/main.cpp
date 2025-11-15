#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	{
		std::cout << "Testing ShrubberyCreationForm" << std::endl;
		Bureaucrat bureaucrat("John Doe", 146);
		ShrubberyCreationForm form("Form");

		bureaucrat.signForm(form);

		try {
			while (bureaucrat.getGrade() > 144) {
				bureaucrat.incrementGrade();
			}
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);

		try {
			while (bureaucrat.getGrade() > 135) {
				bureaucrat.incrementGrade();
			}
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		
		bureaucrat.executeForm(form);
	}
	{
		std::cout << "\nTesting RobotomyRequestForm" << std::endl;
		Bureaucrat bureaucrat("John Doe", 73);
		RobotomyRequestForm form("Form");

		bureaucrat.signForm(form);

		try {
			while (bureaucrat.getGrade() > 71) {
				bureaucrat.incrementGrade();
			}
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);

		try {
			while (bureaucrat.getGrade() > 44) {
				bureaucrat.incrementGrade();
			}
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

			bureaucrat.executeForm(form);
	}
	{
		std::cout << "\nTesting PresidentialPardonForm" << std::endl;
		Bureaucrat bureaucrat("John Doe", 26);
		PresidentialPardonForm form("Form");

		bureaucrat.signForm(form);

		try {
			while (bureaucrat.getGrade() > 24) {
				bureaucrat.incrementGrade();
			}
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);

		try {
			while (bureaucrat.getGrade() > 4) {
				bureaucrat.incrementGrade();
			}
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		bureaucrat.executeForm(form);
	}
	return 0;
}
