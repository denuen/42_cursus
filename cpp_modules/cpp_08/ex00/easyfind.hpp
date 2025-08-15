/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:42:37 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/14 10:42:38 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class ValueNotFound : public std::exception {
	public:
		virtual const char* what() const throw();
};

template <typename T>
typename T::iterator	easyfind(T& container, int nbr);

template <typename T>
const typename T::const_iterator	easyfind(const T& container, int nbr);

#endif
