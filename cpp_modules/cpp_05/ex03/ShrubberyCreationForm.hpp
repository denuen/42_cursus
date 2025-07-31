#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"

class ShruberryCreationForm : public AForm {

	private:
		std::string			target;

		bool				isTargetPresent;

		static const int	REQUIRED_SIGN_GRADE = 145;
		static const int	REQUIRED_EXEC_GRADE = 137;

		ShruberryCreationForm();
		ShruberryCreationForm(const ShruberryCreationForm& s);
		ShruberryCreationForm&	operator=(const ShruberryCreationForm& s);
	public:
		ShruberryCreationForm(const std::string& target, const std::string& formName);

		inline int			getRequiredSignGrade() const { return (REQUIRED_SIGN_GRADE); }
		inline int			getRequiredExecGrade() const { return(REQUIRED_EXEC_GRADE); }
		inline std::string	getFilename() const { return (target); }
		inline void			setFilename(const std::string& newTarget) { target = newTarget; }

		virtual void		execute(Bureaucrat const & executor) const;

		~ShruberryCreationForm();
};



#endif
