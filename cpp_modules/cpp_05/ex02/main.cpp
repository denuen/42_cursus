#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>

int	main() {

	std::srand(std::time(0));

	try {
		ShruberryCreationForm	invalidFilename("prova", "");
	} catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		ShruberryCreationForm	invalidFilename("", "prova");
	} catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		ShruberryCreationForm	s("prova", "bombocrat");
		RobotomyRequestForm		r("prova", "bombocrat");
		Bureaucrat				b("Filippo", 170);

		s.beSigned(b);
		r.beSigned(b);
		s.execute(b);
		r.execute(b);
	} catch(const std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
			return (1);
	} catch(const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
