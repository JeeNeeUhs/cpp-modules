#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat johndoe("John Doe", 1);
	{
		ShrubberyCreationForm formshrub("target1");
		johndoe.signForm(formshrub);
		try {
			formshrub.execute(johndoe);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		RobotomyRequestForm formrobo("target2");
		johndoe.signForm(formrobo);
		try {
			formrobo.execute(johndoe);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		PresidentialPardonForm formpres("target3");
		johndoe.signForm(formpres);
		try {
			formpres.execute(johndoe);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Bureaucrat janedoe("Jane Doe", 150);
		ShrubberyCreationForm formshrub("target4");
		janedoe.signForm(formshrub);
		try {
			formshrub.execute(janedoe);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}