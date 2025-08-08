/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:44:20 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/08 15:44:21 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const int	NUM_FORMS = 3;

class Intern{

	private:
		struct FormEntry {
			std::string name;
			AForm* (*create)(const std::string& target);
		};

		FormEntry	forms[NUM_FORMS];

	public:
		Intern();

		AForm*	makeForm(const std::string& name, const std::string& target);

		~Intern();

};


#endif
