/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:44:22 by apintaur          #+#    #+#             */
/*   Updated: 2025/09/02 09:35:06 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int	main() {

	srand(std::time(0));

	try {
		ShrubberyCreationForm	invalidFilename("prova", "");
	} catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-----------------------------" << std::endl;

	try {
		ShrubberyCreationForm	invalidFilename("", "prova");
	} catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-----------------------------" << std::endl;

	try {
		ShrubberyCreationForm	s("prova", "bombocrat");
		RobotomyRequestForm		r("prova_shrubbery", "bombocrat");
		Bureaucrat				b("Filippo", 45);

		s.beSigned(b);
		r.beSigned(b);
		s.execute(b);
		r.execute(b);
	} catch(const std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
			return (1);
	} catch(const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-----------------------------" << std::endl;

	Intern	randomIntern;

	AForm*	shrub = randomIntern.makeForm("shrubberry creation", "Giorgio");
	if (shrub)
		std::cout << *shrub << std::endl;

	std::cout << "-----------------------------" << std::endl;

	AForm*	robot = randomIntern.makeForm("robotomy request", "Arturo");
	if (robot)
		std::cout << *robot << std::endl;

	std::cout << "-----------------------------" << std::endl;

	AForm*	pardon = randomIntern.makeForm("presidential pardon", "Carl");
	if (pardon)
		std::cout << *pardon << std::endl;

	std::cout << "-----------------------------" << std::endl;

	AForm*	unknown = randomIntern.makeForm("invalid", "Nobody");
	if (!unknown)
		std::cout << "Unknown form creation correctly failed." << std::endl;

	if (shrub)
		delete shrub;
	if (robot)
		delete robot;
	if (pardon)
		delete pardon;

	return 0;
}
