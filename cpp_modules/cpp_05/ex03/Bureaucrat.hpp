#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

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
		inline int			getHighestGradeRate() const { return (HIGHEST_GRADE_RATE); }
		inline int			getLowestGradeRate() const { return (LOWEST_GRADE_RATE); }

		void				incrementGrade();
		void				decrementGrade();

		void				signForm(AForm& f);

		class GradeTooHighException : public std::exception {

			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {

			public:
				virtual const char* what() const throw();
		};

		void	executeForm(AForm const & form) const;
		
		~Bureaucrat();
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif
