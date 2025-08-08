/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:44:30 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/08 15:44:31 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	private:
		const std::string			target;

		bool						isTargetPresent;

		static const int			REQUIRED_SIGN_GRADE = 72;
		static const int			REQUIRED_EXEC_GRADE = 45;

		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& r);

	public:
		RobotomyRequestForm(const std::string& target, const std::string& formName);

		inline int		getRequiredSignGrade() const { return (REQUIRED_SIGN_GRADE); }
		inline int		getRequiredExecGrade() const { return(REQUIRED_EXEC_GRADE); }

		virtual void	execute(Bureaucrat const& b) const;

		~RobotomyRequestForm();
};


#endif
