/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:19:38 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/14 12:19:39 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {

	private:
		std::vector<int>	vec;
		unsigned int		n;

	public:
		Span(const unsigned int N);
		Span(const Span& s);
		Span&	operator=(const Span& s);

		void	addNumber(const int nbr);
		void	addMultipleNumbers(unsigned int start, unsigned int end);
		int		shortestSpan() const;
		int		longestSpan() const;

		class SpanIsFull : public std::exception {
			public:
				const char*	what() const throw();
		};

		class SpanIsEmpty : public std::exception {
			public:
				const char*	what() const throw();
		};

		class BadRange : public std::exception {
			public:
				const char* what() const throw();
		};

		~Span();
};

#endif
