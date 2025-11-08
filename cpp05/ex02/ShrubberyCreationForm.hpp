#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;

	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		~ShrubberyCreationForm();

		void execute(const Bureaucrat &executor) const;
};

#endif
