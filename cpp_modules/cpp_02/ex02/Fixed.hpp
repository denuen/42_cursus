/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:44:02 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/06 15:51:46 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_POINT_HPP
#define FIXED_POINT_HPP

#include <iostream>

class Fixed {

private:
	int					rawBits;
	static const int	fractionalBits = 8;

public:
	Fixed();
	Fixed( int nbr );
	Fixed( float nbr );
	Fixed( const Fixed& fixedPoint );

	Fixed&	operator=( const Fixed& fixedPoint );

	inline bool	operator>( const Fixed& fixedPoint ) const { return (this->getRawBits() > fixedPoint.getRawBits()); }
	inline bool	operator<( const Fixed& fixedPoint ) const { return (this->getRawBits() < fixedPoint.getRawBits()); }
	inline bool	operator>=( const Fixed& fixedPoint ) const { return (this->getRawBits() >= fixedPoint.getRawBits()); }
	inline bool	operator<=( const Fixed& fixedPoint ) const { return (this->getRawBits() <= fixedPoint.getRawBits()); }
	inline bool	operator==( const Fixed& fixedPoint ) const { return (this->getRawBits() == fixedPoint.getRawBits()); }
	inline bool	operator!=( const Fixed& fixedPoint ) const { return (this->getRawBits() != fixedPoint.getRawBits()); }

	Fixed		operator+( const Fixed& fixedPoint ) const;
	Fixed		operator-( const Fixed& fixedPoint ) const;
	Fixed		operator*( const Fixed& fixedPoint ) const;
	Fixed		operator/( const Fixed& fixedPoint ) const;

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	~Fixed();
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixedPoint);

#endif
