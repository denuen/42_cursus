/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:35:38 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/06 15:14:36 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	rawBits = 0;
}

Fixed::Fixed( int nbr ) {
	std::cout << "Int constructor called" << std::endl;
	rawBits = static_cast<int>(roundf(nbr * (1 << fractionalBits)));;
}

Fixed::Fixed( float nbr ) {
	std::cout << "Float constructor called" << std::endl;
	rawBits = nbr * pow(2, fractionalBits);
}

Fixed::Fixed(const Fixed& Fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	rawBits = Fixed.rawBits;
}

Fixed& Fixed::operator=(const Fixed& Fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &Fixed) {
		rawBits = Fixed.rawBits;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedPoint) {
	out << fixedPoint.toFloat();
	return out;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (rawBits);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	rawBits = raw;
}

float	Fixed::toFloat( void ) const {
	return (static_cast<float>(rawBits) / (1 << fractionalBits));
}

int		Fixed::toInt( void ) const {
	return (rawBits >> fractionalBits);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
