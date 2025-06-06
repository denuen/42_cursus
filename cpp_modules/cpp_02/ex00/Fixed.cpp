/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:02:10 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/06 12:02:11 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed& Fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	value = Fixed.value;
}

Fixed& Fixed::operator=(const Fixed& Fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &Fixed) {
		value = Fixed.value;
	}
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
