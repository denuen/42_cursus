/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:43:45 by apintaur          #+#    #+#             */
/*   Updated: 2025/09/02 09:30:10 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(std::string target, const std::string& formName) :
AForm(formName, REQUIRED_SIGN_GRADE, REQUIRED_EXEC_GRADE), target(target) {

	if (target.size() == 0) {
		throw std::invalid_argument ("Error: filename must be a non-null string.");
		return ;
	}
	
}

void	RobotomyRequestForm::execute(Bureaucrat const& b) const {

	if (!this->getIsSigned()) {
		throw NotSignedException();
	}
	if (b.getGrade() > REQUIRED_EXEC_GRADE) {
		throw GradeTooLowException();
	}

	std::cout << "*******ROBOTIMIZATION REQUESTED*******" << std::endl;

	std::ifstream	test;
	bool			isTargetPresent = false;
	
	test.open(target.c_str());
	if (test.good()) {
		isTargetPresent = true;
	}
	test.close();

	if (isTargetPresent) {
		std::cout << "Target: " << target << " is being robotimized..." << std::endl;

		bool isRobotimized = std::rand() % 2;

		if (isRobotimized) {
			std::cerr << "Error: robotomization failed due to internal errors. Please retry." << std::endl;
		} else {
			std::cout << "Target: " << target << " has been successfully robotomized." << std::endl;
		}
	} else {
		std::cerr << "Error: target: " << target << " cannot be robotomized. Ensure the file exists." << std::endl;
	}
}

RobotomyRequestForm::~RobotomyRequestForm() {

}
