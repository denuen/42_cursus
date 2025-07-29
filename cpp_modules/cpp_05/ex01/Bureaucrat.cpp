#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, const int grade) :
name(name), grade(grade) {

	if (grade < HIGHEST_GRADE_RATE) {
		throw GradeTooHighException();
	} else if (grade > LOWEST_GRADE_RATE) {
		throw GradeTooLowException();
	}

}

void	Bureaucrat::incrementGrade() {

	if ((grade - 1) < HIGHEST_GRADE_RATE) {
		throw GradeTooHighException();
	} else {
		grade -= 1;
	}

}

void	Bureaucrat::decrementGrade() {

	if ((grade + 1) > LOWEST_GRADE_RATE) {
		throw GradeTooLowException();
	} else {
		grade += 1;
	}

}

void	Bureaucrat::signForm(Form& f) {

	try {
		f.beSigned(*this);
		std::cout << name << " signed " << f.getName() << std::endl;
	} catch(const Form::GradeTooLowException& e) {
		std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}

}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {

	return ("Error: Bureaucrat: grade too low!");

}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {

	return ("Error: Bureaucrat: grade too high!");

}

Bureaucrat::~Bureaucrat() {

}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b) {

	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}

