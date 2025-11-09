#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!getSign()) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getReqtoexec()) {
		throw AForm::GradeTooLowException();
	}
	std::ofstream outfile(target + "_shrubbery");
	outfile << "       /\\" << std::endl;
	outfile << "      /  \\" << std::endl;
	outfile << "     /    \\" << std::endl;
	outfile << "    /      \\" << std::endl;
	outfile << "   /        \\" << std::endl;
	outfile << "       ||" << std::endl;
	outfile << "       ||" << std::endl;
	outfile << "       ||" << std::endl;
	outfile << "       /\\" << std::endl;
	outfile.close();
}
