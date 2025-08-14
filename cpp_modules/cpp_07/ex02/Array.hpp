/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:41:27 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/14 10:41:28 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {

	private:
		T*				buffer;
		unsigned int	n;

	public:
		Array();
		Array(const unsigned int n);
		Array(const Array& a);

		Array&		operator=(const Array& a);
		T&			operator[](unsigned int index);
		const T&	operator[](unsigned int index) const;

		inline unsigned int	size() const { return (n); }

		class	OutOfBounds : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		~Array();
};

#endif
