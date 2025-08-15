/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:42:41 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/15 07:42:45 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "easyfind.tpp"
#include <vector>
#include <list>
#include <iostream>
#include <iomanip>

template <typename T>
std::vector<T>	getInitVector(unsigned int start, unsigned int end, unsigned int factor) {
	std::vector<T>	vec;

	if (factor > end) {
		factor = end / 5;
	}
	if (start > end) {
		start = end - (factor * 5);
	}
	while (start <= end) {
		vec.push_back(start);
		start += factor;
	}
	return (vec);
}

void	testContainer()
{
	std::vector<int>	v = getInitVector<int>(10, 50, 10);
	const std::vector<int>	const_v = getInitVector<int>(1, 5, 1);

	std::cout << "=== Testing mutable vector ===" << std::endl;
	try {
		std::vector<int>::iterator	it = easyfind(v, 30);
		std::cout << "Found value 30 at index: " << std::distance(v.begin(), it) << std::endl;
	} catch (const ValueNotFound& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator	it = easyfind(v, 100);
		std::cout << "Found value 100 at index: " << std::distance(v.begin(), it) << std::endl;
	} catch (const ValueNotFound& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing const vector ===" << std::endl;
	try {
		std::vector<int>::const_iterator	it = easyfind(const_v, 3);
		std::cout << "Found value 3 at index: " << std::distance(const_v.begin(), it) << std::endl;
	} catch (const ValueNotFound& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::const_iterator	it = easyfind(const_v, 42);
		std::cout << "Found value 42 at index: " << std::distance(const_v.begin(), it) << std::endl;
	} catch (const ValueNotFound& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void	testList()
{
	std::list<int>	l(getInitVector<int>(5, 20, 5).begin(), getInitVector<int>(5, 20, 5).end());

	std::cout << "\n=== Testing list ===" << std::endl;
	try {
		std::list<int>::iterator	it = easyfind(l, 15);
		std::cout << "Found value 15 at index: " << std::distance(l.begin(), it) << std::endl;
	} catch (const ValueNotFound& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator	it = easyfind(l, 100);
		std::cout << "Found value 100 at index: " << std::distance(l.begin(), it) << std::endl;
	} catch (const ValueNotFound& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int	main()
{
	std::cout << std::boolalpha;

	testContainer();
	testList();

	return 0;
}
