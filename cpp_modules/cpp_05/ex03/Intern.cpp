/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:44:18 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/08 15:44:19 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

static AForm*	createShrubberyForm(const std::string& target) {
	return (new ShruberryCreationForm(target, target + "form"));
}

static AForm*	createRobotomyForm(const std::string& target) {
	return (new RobotomyRequestForm(target, target + "form"));
}

static AForm*	createPresidentialForm(const std::string& target) {
	return (new PresidentialPardonForm(target, target + "form"));
}

Intern::Intern() {

	forms[0] = {"shrubberry creation", &createShrubberyForm};
	forms[1] = {"robotomy request", &createRobotomyForm};
	forms[2] = {"presidential pardon", &createPresidentialForm};

}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) {

	for (int i = 0; i < NUM_FORMS; i++) {
		if (forms[i].name == name) {
			std::cout << "Intern creates " << name << std::endl;
			return (forms[i].create(target));
		}
	}
	std::cout << "Intern can't create form: " << name << std::endl;

	return (NULL);
}

Intern::~Intern() {

}
