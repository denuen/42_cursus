#include "Bureaucrat.hpp"


int	main() {

	try {
		Bureaucrat	validArgs("John", 12);
		Bureaucrat	invalidArgs("John", 151);

		std::cout << validArgs;
		std::cout << invalidArgs;
	} catch(const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
	}

}
