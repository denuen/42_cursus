/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:41:21 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/14 10:41:22 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void	iter(T* arr, size_t len, void (*func)(T&)) {
	if (!arr)
		return ;
	for (size_t i = 0; i < len; i++) {
		func(arr[i]);
	}
}

template <typename T>
void	iter(T* arr, size_t len, void (*func)(const T&)) {
	if (!arr)
		return ;
	for (size_t i = 0; i < len; i++) {
		func(arr[i]);
	}
}

#endif
