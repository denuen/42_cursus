/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:43:43 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/08 15:43:44 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {

	private:
		std::string			target;

		bool				isTargetPresent;

		static const int	REQUIRED_SIGN_GRADE = 25;
		static const int	REQUIRED_EXEC_GRADE = 5;

		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& p);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& p);
	public:
		PresidentialPardonForm(const std::string& target, const std::string& formName);

		inline int		getRequiredSignGrade() const { return (REQUIRED_SIGN_GRADE); }
		inline int		getRequiredExecGrade() const { return(REQUIRED_EXEC_GRADE); }

		virtual void	execute(Bureaucrat const& b) const;

		~PresidentialPardonForm();
};


#endif
