#include "Bureaucrat.hpp"


int	main() {

	// valid
	try {
		Bureaucrat	validArgs("John", 12);
		std::cout << validArgs << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	// invalid
	try {
		Bureaucrat	invalidArgs("John", 151);
		std::cout << invalidArgs << std::endl;
	} catch(const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
	}

	// invalid
	try {
		Bureaucrat	invalidArgs2("Jane", 0);
		std::cout << invalidArgs2 << std::endl;
	} catch(const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
	}

}
