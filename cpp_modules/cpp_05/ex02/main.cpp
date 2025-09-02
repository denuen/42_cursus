/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:43:39 by apintaur          #+#    #+#             */
/*   Updated: 2025/09/02 09:31:47 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

int	main() {

	srand(std::time(0));

	try {
		ShrubberyCreationForm	invalidFilename("prova", "");
	} catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		ShrubberyCreationForm	invalidFilename("", "prova");
	} catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}

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

	return (0);
}
