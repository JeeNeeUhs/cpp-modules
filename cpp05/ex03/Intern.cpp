#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string formNames[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

AForm* (Intern::*formCreations[3])(const std::string&) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return ((*this).*(formCreations[i]))(target);
		}
	}

	std::cout << "Intern could not find the form: " << formName << std::endl;
	return nullptr;
}