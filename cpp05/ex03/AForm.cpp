#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), signstatus(false), reqtosign(1), reqtoexec(1) {}

AForm::AForm(const std::string &name, int reqtosign, int reqtoexec) : name(name) {
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

AForm::AForm(const AForm &other) : name(other.name), signstatus(other.signstatus), reqtosign(other.reqtosign), reqtoexec(other.reqtoexec) {}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		this->reqtosign = other.reqtosign;
		this->reqtoexec = other.reqtoexec;
		this->signstatus = other.signstatus;
	}
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return name;
}

bool AForm::getSign() const {
	return signstatus;
}

int AForm::getReqToSign() const {
	return reqtosign;
}

int AForm::getReqtoexec() const {
	return reqtoexec;
}

void AForm::beSigned(const Bureaucrat &other) {
	if (other.getGrade() > reqtosign) {
		throw GradeTooLowException();
	}
	signstatus = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
	os << "Form Name: " << AForm.getName() << ", Signed: " << (AForm.getSign() ? "Yes" : "No") << ", Required grade to sign: " << AForm.getReqToSign() << ", Required grade to execute: " << AForm.getReqtoexec();
	return os;
}
