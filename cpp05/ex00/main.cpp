#include "Bureaucrat.hpp"

int main() {
	{
		std::cout << "----------test1----------" << std::endl;
		Bureaucrat bureaucrat("John Doe", 50);
		std::cout << bureaucrat << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "----------test2----------" << std::endl;
		try {
			Bureaucrat bureaucrat("Jane Doe", 0);
		} catch (const Bureaucrat::HighGrade &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "----------test3----------" << std::endl;
		try {
			Bureaucrat bureaucrat("Jim Doe", 151);
		} catch (const Bureaucrat::LowGrade &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "----------test4----------" << std::endl;
		Bureaucrat bureaucrat("Jake Doe", 1);
		std::cout << bureaucrat << std::endl;
		try {
			bureaucrat.incrementGrade();
		} catch (const Bureaucrat::HighGrade &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << bureaucrat << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "----------test5----------" << std::endl;
		Bureaucrat bureaucrat("Joey Doe", 150);
		std::cout << bureaucrat << std::endl;
		try {
			bureaucrat.decrementGrade();
		} catch (const Bureaucrat::LowGrade &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << bureaucrat << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "----------test6----------" << std::endl;
		Bureaucrat bureaucrat("Jack Doe", 75);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "----------test7----------" << std::endl;
		Bureaucrat bureaucrat("Judy Doe", 100);
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		std::cout << std::endl;
	}
	return 0;
}