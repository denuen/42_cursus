#include "header.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void) {

	int	rnd = rand() % 3;
	Base* gen;

	if (rnd == 0) {
		gen = new A;
	} else if (rnd == 1) {
		gen = new B;
	} else {
		gen = new C;
	}

	return (gen);
}

void identify(Base* p) {

	if (dynamic_cast<A*>(p)) {
		std::cout << "Ptr identified as class A." << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "Ptr identified as class B." << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "Ptr identified as class C." << std::endl;
	}

}

void identify(Base& p) {

	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Ptr identified as class A." << std::endl;
		return ;
	} catch (const std::bad_cast& e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Ptr identified as class B." << std::endl;
		return ;
	} catch (const std::bad_cast& e) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Ptr identified as class C." << std::endl;
		return ;
	} catch (const std::bad_cast& e) {}

}
