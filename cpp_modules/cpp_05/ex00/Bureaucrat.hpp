/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:41:57 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/08 15:41:58 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {

	private:
		const std::string	name;
		int					grade;

		static const int	HIGHEST_GRADE_RATE = 1;
		static const int	LOWEST_GRADE_RATE = 150;

		Bureaucrat();
		Bureaucrat(const Bureaucrat&);
		Bureaucrat&	operator=(const Bureaucrat&);

	public:
		Bureaucrat(const std::string& name, const int grade);

		inline std::string	getName() const { return (name); }
		inline int			getGrade() const { return(grade); }

		void						incrementGrade();
		void						decrementGrade();

		class GradeTooHighException : public std::exception {

			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {

			public:
				virtual const char* what() const throw();
		};

		~Bureaucrat();
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif
