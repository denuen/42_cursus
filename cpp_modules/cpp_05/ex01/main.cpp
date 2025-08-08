/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:43:13 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/08 15:43:14 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {

	try {
		Bureaucrat	alice("Alice", 1);
		Bureaucrat	bob("Bob", 150);
		Bureaucrat	charlie("Charlie", 75);

		Form	taxForm("Tax Declaration", 50, 30);
		Form	leaveForm("Leave Request", 150, 100);
		Form	secretForm("Top Secret", 1, 1);

		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << charlie << std::endl;
		std::cout << std::endl;

		std::cout << taxForm << std::endl;
		std::cout << leaveForm << std::endl;
		std::cout << secretForm << std::endl;
		std::cout << std::endl;

		alice.signForm(secretForm);		// valid
		std::cout << secretForm << std::endl;
		std::cout << std::endl;

		bob.signForm(leaveForm);		// vaild
		std::cout << leaveForm << std::endl;
		std::cout << std::endl;

		bob.signForm(taxForm);			// invalid
		std::cout << taxForm << std::endl;
		std::cout << std::endl;

		charlie.signForm(taxForm);		// invalid
		std::cout << taxForm << std::endl;
		std::cout << std::endl;

		charlie.signForm(secretForm);	// invalid
		std::cout << secretForm << std::endl;
		std::cout << std::endl;

		try {
			Form	invalidForm1("Invalid High", 0, 50);
		} catch (const Form::GradeTooHighException& e) {
			std::cout << "Caught exception for grade 0: " << e.what() << std::endl;
		}

		try {
			Form	invalidForm2("Invalid Low", 50, 151);
		} catch (const Form::GradeTooLowException& e) {
			std::cout << "Caught exception for grade 151: " << e.what() << std::endl;
		}

		// It catches the first caught exception
		try {
			Form	invalidForm3("Invalid Form", 0, 151);
		} catch (const Form::GradeTooHighException& e) {
			std::cout << "Caught exception for grade 0: " << e.what() << std::endl;
		}
		 catch (const Form::GradeTooLowException& e) {
			std::cout << "Caught exception for grade 151: " << e.what() << std::endl;
		}

	}
	catch (const Form::GradeTooHighException& e) {
		std::cout << "Caught exception for grade 0: " << e.what() << std::endl;
	}
	 catch (const Form::GradeTooLowException& e) {
		std::cout << "Caught exception for grade 151: " << e.what() << std::endl;
	}

	return 0;
}
