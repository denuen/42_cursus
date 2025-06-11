/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:50:34 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/11 15:16:37 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal(), type("dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( const std::string& newName ) : Animal(newName), type("dog") {
	std::cout << "Dog constructor with parameters called" << std::endl;

}

Dog::Dog( const Dog& dog ) : Animal(dog) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog&	Dog::operator=( const Dog& dog ) {
	std::cout << "Dog copy assignment constructor called" << std::endl;
	if (this != &dog) {
		Animal::operator=(dog);
	}
	return (*this);
}

void	Dog::makeSound( void ) const {
	std::cout << "oooooOH...BAU" << std::endl;
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
}
