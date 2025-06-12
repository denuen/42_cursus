/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:50:34 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/11 21:33:54 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	brain = new Brain;
}

Dog::Dog( const std::string& newName ) : Animal(newName) {
	std::cout << "Dog constructor with parameters called" << std::endl;
	type = "Dog";
	brain = new Brain;
}

Dog::Dog( const Dog& dog ) : Animal(dog) {
	std::cout << "Dog copy constructor called" << std::endl;
	type = "Dog";
	brain = new Brain(*dog.brain);
}

Dog&	Dog::operator=( const Dog& dog ) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &dog) {
		Animal::operator=(dog);
		delete brain;
		brain = new Brain(*dog.brain);
	}
	return (*this);
}

void	Dog::makeSound( void ) const {
	std::cout << "oooooOH...BAU" << std::endl;
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}
