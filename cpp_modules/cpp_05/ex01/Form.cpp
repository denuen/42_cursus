#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, const int signGrade, const int executeGrade) :
	name(name), isSigned(false), requiredSignGrade(signGrade), requiredExecuteGrade(executeGrade) {

	if (signGrade < 1 || executeGrade < 1) {
		throw GradeTooHighException();
	}
	if (signGrade > 150 || executeGrade > 150) {
		throw GradeTooLowException();
	}

}

void	Form::beSigned(const Bureaucrat& b) {

	if (b.getGrade() > requiredSignGrade) {
		throw GradeTooLowException();
	}
	isSigned = true;

}

const char*	Form::GradeTooHighException::what() const throw() {
	return ("grade is too high!");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("grade is too low!");
}

Form::~Form() {

}

std::ostream&	operator<<(std::ostream& os, const Form& f) {

	std::string	status;

	if (f.getIsSigned()){
		status = "yes";
	} else {
		status = "no";
	}

	os << "Form " << f.getName() << ", signed: " << status
		<< ", required sign grade: " << f.getRequiredSignGrade()
		<< ", required execute grade: " << f.getRequiredExecuteGrade();

	return (os);
}
