#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
	private:
		static const int minGrade = 1;
		static const int maxGrade = 150;

		const std::string name;
		int grade;

	public:
		Bureaucrat();	
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);

		Bureaucrat &operator=(const Bureaucrat &other);

		~Bureaucrat();

		const std::string &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		class HighGrade : public std::exception {
			public:
				const char *what() const throw() {
					return "Grade too high";
				}
		};
		class LowGrade : public std::exception {
			public:
				const char *what() const throw() {
					return "Grade too low";
				}
		};
		
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif