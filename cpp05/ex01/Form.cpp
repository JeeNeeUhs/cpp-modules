#include <Form.hpp>
#include <Bureaucrat.hpp>

Form::Form() : name("Default"), reqtosign(1), reqtoexec(1), signstatus(false) {}

Form::Form(const std::string &name, int reqtosign, int reqtoexec) : name(name) {
	if (reqtosign < minGrade) {
		throw GradeTooHighException();
	} else if (reqtosign > maxGrade) {
		throw GradeTooLowException();
	} else if (reqtoexec < minGrade) {
		throw GradeTooHighException();
	} else if (reqtoexec > maxGrade) {
		throw GradeTooLowException();
	}
	this->reqtosign = reqtosign;
	this->reqtoexec = reqtoexec;
}

Form::Form(const Form &other) : name(other.name), reqtosign(other.reqtosign), reqtoexec(other.reqtoexec), signstatus(other.signstatus) {}

Form &Form::operator=(const Form &other) {
	if (this != &other) {
		this->reqtosign = other.reqtosign;
		this->reqtoexec = other.reqtoexec;
		this->signstatus = other.signstatus;
	}
	return *this;
}

Form::~Form() {}

std::string Form::getName() const {
	return name;
}

bool Form::getSign() const {
	return signstatus;
}

int Form::getReqToSign() const {
	return reqtosign;
}

int Form::getReqtoexec() const {
	return reqtoexec;
}

void Form::beSigned(const Bureaucrat &other) {
	if (other.getGrade() > reqtosign) {
		throw GradeTooLowException();
	}
	signstatus = true;
}

std::ostream &operator<<(std::ostream &os, const Form &Form) {

}