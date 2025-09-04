/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:19:35 by apintaur          #+#    #+#             */
/*   Updated: 2025/09/04 09:56:03 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(const unsigned int N) : n(N) {

	if (n > 0) {
		vec.reserve(n);
	}
}

Span::Span(const Span& s) : n(s.n) {

	if (n > 0) {
		vec.reserve(n);
		vec = s.vec;
	}
}

Span& Span::operator=(const Span& s) {

	if (this != &s) {
		vec.clear();

		n = s.n;
		if (n > 0) {
			vec.reserve(n);
			vec = s.vec;
		}
	}
	return (*this);
}

void Span::addNumber(const int nbr) {

	if (vec.size() >= n) {
		throw SpanIsFull();
	} else {
		vec.push_back(nbr);
	}
}

void Span::addMultipleNumbers(unsigned int start, unsigned int end) {

	if (start > end) {
		throw BadRange();
	}
	while (start <= end) {
		if (vec.size() == n) {
			throw SpanIsFull();
		}
		vec.push_back(start);
		start++;
	}
}

int Span::shortestSpan() const {

	int diff = std::numeric_limits<int>::max();

	if (vec.size() <= 1) {
		throw SpanIsEmpty();
	} else {
		std::vector<int> tmp  = vec;
		int				 size = vec.size();

		std::sort(tmp.begin(), tmp.end());
		for (int i = 0; i < size - 1; i++) {
			if (tmp.at(i + 1) - tmp.at(i) < diff) {
				diff = tmp.at(i + 1) - tmp.at(i);
			}
		}
	}
	return (diff);
}

int Span::longestSpan() const {

	if (vec.size() <= 1) {
		throw SpanIsEmpty();
	} else {
		// std::vector<int>	tmp = vec;
		// std::sort(tmp.begin(), tmp.end());
		// return (tmp.back() - tmp.front());
		std::vector<int>::const_iterator minIt =
			std::min_element(vec.begin(), vec.end());
		std::vector<int>::const_iterator maxIt =
			std::max_element(vec.begin(), vec.end());
		return (*maxIt - *minIt);
	}
}

const char* Span::SpanIsFull::what() const throw() {
	return ("Span is full!");
}

const char* Span::SpanIsEmpty::what() const throw() {
	return ("Span is Empty!");
}

const char* Span::BadRange::what() const throw() {
	return ("Invalid numbers range!");
}

Span::~Span() {
}
