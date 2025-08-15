/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:16:33 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/14 13:16:34 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() :
std::stack<T>() {

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& m) :
std::stack<T>(m) {

}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& m) {

	std::stack<T>::operator=(m);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {

}
