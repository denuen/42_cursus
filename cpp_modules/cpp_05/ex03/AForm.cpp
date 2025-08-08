/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:44:11 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/08 15:44:12 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, const int signGrade, const int executeGrade) :
	name(name), isSigned(false), requiredSignGrade(signGrade), requiredExecuteGrade(executeGrade) {

	if (name.size() == 0) {
		throw std::invalid_argument("Error: formName must be a non-null string");
	}
	if (signGrade < 1 || executeGrade < 1) {
		throw GradeTooHighException();
	}
	if (signGrade > 150 || executeGrade > 150) {
		throw GradeTooLowException();
	}

}

void	AForm::beSigned(const Bureaucrat& b) {

	if (b.getGrade() > requiredSignGrade) {
		throw GradeTooLowException();
	}
	isSigned = true;

}

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("grade is too high!");
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("grade is too low!");
}

const char*	AForm::NotSignedException::what() const throw() {
	return ("form is not signed!");
}

void	AForm::safeExecute(Bureaucrat const& b) {

	if (!isSigned) {
		throw NotSignedException();
	}
	if (b.getGrade() > requiredExecuteGrade) {
		throw GradeTooLowException();
	}
	this->execute(b);

}

AForm::~AForm() {

}

std::ostream&	operator<<(std::ostream& os, const AForm& f) {

	std::string	status;

	if (f.getIsSigned()){
		status = "yes";
	} else {
		status = "no";
	}

	os << "AForm " << f.getName() << ", signed: " << status
		<< ", required sign grade: " << f.getRequiredSignGrade()
		<< ", required execute grade: " << f.getRequiredExecuteGrade();

	return (os);
}
