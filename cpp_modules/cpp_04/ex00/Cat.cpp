/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:05:43 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/11 15:16:30 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat( const std::string& newName ): Animal(newName) {
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat( const Cat& cat ) : Animal(cat) {
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat&	Cat::operator=( const Cat& cat ) {
	std::cout << "Cat default constructor called" << std::endl;
	if (this != &cat) {
		Animal::operator=(cat);
	}
	return (*this);
}

void	Cat::makeSound( void ) const {
	std::cout << "oooooOH...MIAO" << std::endl;
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
}
