/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:43:50 by apintaur          #+#    #+#             */
/*   Updated: 2025/09/02 09:22:29 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget, const std::string& formName) :
AForm(formName, REQUIRED_SIGN_GRADE, REQUIRED_EXEC_GRADE), target(newTarget), isTargetPresent(false) {

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

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const {

	if (!this->getIsSigned()) {
		throw NotSignedException();
	}
	if (executor.getGrade() > REQUIRED_EXEC_GRADE) {
		throw GradeTooLowException();
	}

	try {

		std::ofstream	output;

		output.open((target + "_shrubbery").c_str(), std::ios::app);

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
		
		output.close();
	} catch (const AForm::NotSignedException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}
