#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Intern randomIntern;
	AForm *form1;
	AForm *form2;
	AForm *form3;
	AForm *form4;
	try {
		form1 = randomIntern.makeForm("ShrubberyCreationForm", "halil");
		form2 = randomIntern.makeForm("RobotomyRequestForm", "ahmet");
		form3 = randomIntern.makeForm("PresidentialPardonForm", "mehmet");
		form4 = randomIntern.makeForm("UnknownForm", "unknown");
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete form1;
	delete form2;
	delete form3;
	delete form4;
	return 0;
}