/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:43:11 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/08 15:43:12 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {

	private:
		const std::string	name;
		bool				isSigned;
		const int			requiredSignGrade;
		const int			requiredExecuteGrade;

		Form();
		Form(const Form& f);
		Form&	operator=(const Form& f);
	public:
		Form(const std::string& name, const int signGrade, const int executeGrade);

		inline std::string	getName() const { return (name); }
		inline bool			getIsSigned() const { return (isSigned); }
		inline int			getRequiredSignGrade() const { return (requiredSignGrade); }
		inline int			getRequiredExecuteGrade() const { return (requiredExecuteGrade); }

		void				beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		~Form();
};

std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif
