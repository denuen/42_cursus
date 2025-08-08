/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:41:53 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/08 15:41:54 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, const int grade) :
name(name), grade(grade) {

	if (grade < HIGHEST_GRADE_RATE) {
		throw GradeTooHighException();
	} else if (grade > LOWEST_GRADE_RATE) {
		throw GradeTooLowException();
	}

}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {

	return ("Error: Bureaucrat: grade too low!");

}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {

	return ("Error: Bureaucrat: grade too high!");

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

Bureaucrat::~Bureaucrat() {

}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b) {

	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}

