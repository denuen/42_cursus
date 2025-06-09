/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:15:51 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/09 15:10:03 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( ) : x(0.0f), y(0.0f) {

}

Point::Point( const float& xRaw, const float& yRaw ) : x(xRaw), y(yRaw) {

}

Point::Point( const Point& point ) : x(point.x), y(point.y) {

}

Point&	Point::operator=( const Point& point ) {
	(void) point;
	
	return (*this);
}

Point::~Point() {

}
