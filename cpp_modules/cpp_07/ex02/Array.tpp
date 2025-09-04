/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:41:29 by apintaur          #+#    #+#             */
/*   Updated: 2025/09/04 09:45:57 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>

template <typename T>
Array<T>::Array() :
n(0) {

	buffer = NULL;

}

template <typename T>
Array<T>::Array(const unsigned int n) :
n(n) {

	if (n > 0) {
		buffer = new T[n]();
	} else {
		buffer = NULL;
	}

}

template <typename T>
Array<T>::Array(const Array<T>& a) :
n(a.n) {

	if (n > 0) {
		buffer = new T[n];
		for (unsigned int i = 0; i < n; i++) {
			buffer[i] = a.buffer[i];
		}
	} else {
		buffer = NULL;
	}

}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& a) {

	if (this != &a) {

		if (buffer) {
			delete[] buffer;
		}

		n = a.n;

		if (n > 0) {
			buffer = new T[a.n];
			for (unsigned int i = 0; i < n; i++) {
				buffer[i] = a.buffer[i];
			}
		} else {
			buffer = NULL;
		}

	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int index) {

	if (index >= n) {
		throw OutOfBounds();
	} else {
		return (buffer[index]);
	}

}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const {

	if (index >= n) {
		throw OutOfBounds();
	} else {
		return (buffer[index]);
	}

}

template <typename T>
const char*	Array<T>::OutOfBounds::what() const throw() {
	return ("Invalid index");
}

template <typename T>
Array<T>::~Array() {

	if (buffer) {
		delete[] buffer;
	}

}
