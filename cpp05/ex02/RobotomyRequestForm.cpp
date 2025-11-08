#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!getSign()) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getReqtoexec()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << "Bzzzzzz... Drilling noises..." << std::endl;
	if (rand() % 2) {
		std::cout << target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "The robotomy failed on " << target << "." << std::endl;
	}
}