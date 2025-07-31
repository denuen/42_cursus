#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target, const std::string& formName) :
AForm(formName, REQUIRED_SIGN_GRADE, REQUIRED_EXEC_GRADE), target(target), isTargetPresent(false){

	if (target.size() == 0) {
		throw std::invalid_argument ("Error: filename must be a non-null string.");
		return ;
	}

	std::ifstream	test;

	test.open(target);
	if (test.good()) {
		isTargetPresent = true;
	}
	test.close();

}

void	RobotomyRequestForm::execute(Bureaucrat const& b) const {

	if (!this->getIsSigned()) {
		throw NotSignedException();
	}
	if (b.getGrade() > REQUIRED_EXEC_GRADE) {
		throw GradeTooLowException();
	}

	std::cout << "*******ROBOTIMIZATION REQUESTED*******" << std::endl;

	if (isTargetPresent) {
		std::cout << "Target: " << target << " is being robotimized..." << std::endl;

		bool isRobotimized = std::rand() % 2;

		if (isRobotimized) {
			std::cerr << "Error: robotomization failed due to internal errors. Please retry." << std::endl;
		} else {
			std::cout << "Target: " << target << " has been successfully robotomized." << std::endl;
		}
	} else {
		std::cerr << "Error: target: " << target << " cannot be robotomized. Ensure the file exists." << std::endl;
	}
}

RobotomyRequestForm::~RobotomyRequestForm() {

}
