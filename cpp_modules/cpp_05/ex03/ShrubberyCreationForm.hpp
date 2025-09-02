/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:44:33 by apintaur          #+#    #+#             */
/*   Updated: 2025/09/02 09:21:56 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	private:
		std::string			target;

		bool				isTargetPresent;

		static const int	REQUIRED_SIGN_GRADE = 145;
		static const int	REQUIRED_EXEC_GRADE = 137;

		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& s);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& s);
	public:
		ShrubberyCreationForm(std::string target, const std::string& formName);

		inline int			getRequiredSignGrade() const { return (REQUIRED_SIGN_GRADE); }
		inline int			getRequiredExecGrade() const { return(REQUIRED_EXEC_GRADE); }
		inline std::string	getFilename() const { return (target); }
		inline void			setFilename(const std::string& newTarget) { target = newTarget; }

		virtual void		execute(Bureaucrat const & executor) const;

		~ShrubberyCreationForm();
};



#endif
