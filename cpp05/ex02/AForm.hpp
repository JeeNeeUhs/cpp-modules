#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool signstatus;
		int reqtosign;
		int reqtoexec;

		static const int minGrade = 1;
		static const int maxGrade = 150;

	public:
		AForm();
		AForm(const std::string &name, int reqtosign, int reqtoexec);
		AForm(const AForm &other);

		AForm &operator=(const AForm &other);

		virtual ~AForm();

		std::string getName() const;
		bool getSign() const;
		int getReqToSign() const;
		int getReqtoexec() const;
		void beSigned(const Bureaucrat &other);

		virtual void execute(const Bureaucrat &executor) const = 0;

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
		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw() {
					return "Form not signed";
				}
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif
