/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:41:19 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/14 10:41:20 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T& a, T& b) {
	T	tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
T	min(const T& a, const T& b) {
	if (a == b)
		return (b);
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T	max(const T& a, const T& b) {
	if (a == b)
		return (b);
	if (a > b)
		return (a);
	return (b);
}

#endif
