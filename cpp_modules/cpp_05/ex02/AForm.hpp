#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {

	private:
		const std::string	name;
		bool				isSigned;
		const int			requiredSignGrade;
		const int			requiredExecuteGrade;

		AForm();
		AForm(const AForm& f);
		AForm&	operator=(const AForm& f);

	public:
		AForm(const std::string& name, const int signGrade, const int executeGrade);

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

		class NotSignedException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		virtual void	execute(Bureaucrat const & executor) const = 0;
		void			safeExecute(Bureaucrat const& executor);

		virtual	~AForm();
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif
