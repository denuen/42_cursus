/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:41:24 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/14 10:41:25 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void	printElement(const T& element) {
	std::cout << element << " ";
}

template <typename T>
void	increment(T& element) {
	++element;
}

int	main() {
	const int SIZE = 10;

	// Testing int array
	int* intArr = new int[SIZE];
	for (int i = 0; i < SIZE; ++i)
		intArr[i] = i * 2;

	std::cout << "--- Testing int array ---" << std::endl;
	std::cout << "Original values: ";
	iter(intArr, SIZE, printElement);
	std::cout << std::endl;

	iter(intArr, SIZE, increment<int>);
	std::cout << "After increment: ";
	iter(intArr, SIZE, printElement);
	std::cout << std::endl << "------------------------" << std::endl;

	// Testing char array
	char* charArr = new char[SIZE];
	for (int i = 0; i < SIZE; ++i)
		charArr[i] = 'A' + i;

	std::cout << "--- Testing char array ---" << std::endl;
	std::cout << "Original values: ";
	iter(charArr, SIZE, printElement);
	std::cout << std::endl;

	iter(charArr, SIZE, increment<char>);
	std::cout << "After increment: ";
	iter(charArr, SIZE, printElement);
	std::cout << std::endl << "------------------------" << std::endl;

	std::string* strArr = new std::string[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		strArr[i] = "Item" + std::to_string(i+1);
	}

	std::cout << "--- Testing string array ---" << std::endl;
	std::cout << "Original values: ";
	iter(strArr, SIZE, printElement);
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++) {
		iter(const_cast<char*>(strArr[i].c_str()), SIZE, increment<char>);
	}
	std::cout << "After increment: ";
	iter(strArr, SIZE, printElement);
	std::cout << std::endl << "------------------------" << std::endl;

	delete[] intArr;
	delete[] charArr;
	delete[] strArr;

	return (0);
}
