/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:42:39 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/14 10:42:40 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T& container, int nbr) {

	typename T::iterator	it = std::find(container.begin(), container.end(), nbr);

	if (it == container.end()) {
		throw ValueNotFound();
	}
	return (it);
}

template <typename T>
const typename T::const_iterator	easyfind(const T& container, int nbr) {

	typename T::const_iterator	it = std::find(container.begin(), container.end(), nbr);

	if (it == container.end()) {
		throw ValueNotFound();
	}
	return (it);
}

const char*	ValueNotFound::what() const throw() {
	return ("Value not found!");
}
