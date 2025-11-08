#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool signstatus;
		int reqtosign;
		int reqtoexec;

		static const int minGrade = 1;
		static const int maxGrade = 150;

	public:

		Form();
		Form(const std::string &name, int reqtosign, int reqtoexec);
		Form(const Form &other);

		Form &operator=(const Form &other);

		~Form();

		std::string getName() const;
		bool getSign() const;
		int getReqToSign() const;
		int getReqtoexec() const;
		void beSigned(const Bureaucrat &other);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() {
					return "Grade too high";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() {
					return "Grade too low";
				}
		};
};

std::ostream &operator<<(std::ostream &os, const Form &Form);

#endif
