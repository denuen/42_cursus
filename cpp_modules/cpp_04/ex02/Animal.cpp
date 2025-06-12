/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:44:16 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/11 15:43:10 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : name("(null)") , type("(null)") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( const std::string& newName ) : name(newName == "" ? "(null)" : newName), type("(null)") {
	std::cout << "Animal constructor with parameters called" << std::endl;

}

Animal::Animal( const Animal& animal ) {
	std::cout << "Animal copy constructor called" << std::endl;
	name = animal.name;
	type = animal.type;
}

Animal&	Animal::operator=( const Animal& animal ) {
	std::cout << "Animal copy assignment constructor called" << std::endl;
	if (this != &animal) {
		name = animal.name;
		type = animal.type;
	}
	return (*this);
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
}
