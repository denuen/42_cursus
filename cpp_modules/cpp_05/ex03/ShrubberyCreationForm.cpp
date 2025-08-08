/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:44:31 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/08 15:44:32 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShruberryCreationForm::ShruberryCreationForm(const std::string& newTarget, const std::string& formName) :
AForm(formName, REQUIRED_SIGN_GRADE, REQUIRED_EXEC_GRADE), target(newTarget), isTargetPresent(false) {

	if (target.size() == 0) {
		throw std::invalid_argument ("Error: filename must be a non-null string.");
		return ;
	}

	std::ifstream	test;

	test.open(target);
	if (test.good()) {
		isTargetPresent = true;
	}
	test.close();

}

void	ShruberryCreationForm::execute(Bureaucrat const& executor) const {

	if (!this->getIsSigned()) {
		throw NotSignedException();
	}
	if (executor.getGrade() > REQUIRED_EXEC_GRADE) {
		throw GradeTooLowException();
	}

	try {

		std::ofstream	output;

		output.open(target + "_shrubbery", std::ios::app);

		output << "      *        " << std::endl;
		output << "     ***       " << std::endl;
		output << "    *****      " << std::endl;
		output << "   *******     " << std::endl;
		output << "  *********    " << std::endl;
		output << " ***********   " << std::endl;
		output << "*************  " << std::endl;
		output << "      *        " << std::endl;
		output << "     ***       " << std::endl;
		output << "    *****      " << std::endl;
		output << "               " << std::endl;
	} catch (const AForm::NotSignedException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}

}

ShruberryCreationForm::~ShruberryCreationForm() {

}
