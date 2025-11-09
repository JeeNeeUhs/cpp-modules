#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Intern randomIntern;
	AForm* form1 = randomIntern.makeForm("ShrubberyCreationForm", "halil");
	AForm* form2 = randomIntern.makeForm("RobotomyRequestForm", "mehmet");
	AForm* form3 = randomIntern.makeForm("PresidentialPardonForm", "ahmet");
	AForm* form4 = randomIntern.makeForm("UnknownForm", "Target");
	delete form1;
	delete form2;
	delete form3;
	delete form4;
	return 0;
}