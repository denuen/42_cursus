/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:43:41 by apintaur          #+#    #+#             */
/*   Updated: 2025/09/02 09:14:48 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string target, const std::string& formName) :
AForm(formName, REQUIRED_SIGN_GRADE, REQUIRED_EXEC_GRADE), target(target), isTargetPresent(false) {

	if (target.size() == 0) {
		throw std::invalid_argument ("Error: filename must be a non-null string.");
		return ;
	}

	std::ifstream	test;

	test.open(target.c_str());
	if (test.good()) {
		isTargetPresent = true;
	}
	test.close();

}

void	PresidentialPardonForm::execute(Bureaucrat const& b) const {

	if (!this->getIsSigned()) {
		throw NotSignedException();
	}
	if (b.getGrade() > REQUIRED_EXEC_GRADE) {
		throw GradeTooLowException();
	}

	try {
		std::cout << target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
	} catch(const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	} catch(const AForm::NotSignedException& e) {
		std::cerr << e.what() << std::endl;
	}

}


PresidentialPardonForm::~PresidentialPardonForm() {

}



