#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string target;

	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		~RobotomyRequestForm();

		void execute(const Bureaucrat &executor) const;
};

#endif
