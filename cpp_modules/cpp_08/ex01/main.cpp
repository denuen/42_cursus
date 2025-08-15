/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:19:30 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/14 12:19:31 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
	try
	{
		std::cout << "=== Basic test ===" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::cout << "\n=== Overflow test ===" << std::endl;
		try {
			sp.addNumber(42);
		} catch (const std::exception &e) {
			std::cerr << "Expected exception: " << e.what() << std::endl;
		}

		std::cout << "\n=== Not enough numbers test ===" << std::endl;
		try {
			Span small(1);
			small.addNumber(10);
			std::cout << small.shortestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "Expected exception: " << e.what() << std::endl;
		}

		std::cout << "\n=== Large range fill ===" << std::endl;
		Span big(10000);
		big.addMultipleNumbers(1, 10000);
		std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
		std::cout << "Longest span: " << big.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}
	return 0;
}
