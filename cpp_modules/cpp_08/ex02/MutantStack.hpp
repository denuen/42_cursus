/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:16:30 by apintaur          #+#    #+#             */
/*   Updated: 2025/08/14 13:16:31 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>{

	public:
		typedef typename std::stack<T>::container_type	container_type;
		typedef typename container_type::iterator		iterator;
		typedef typename container_type::const_iterator	const_iterator;

		MutantStack();
		MutantStack(const MutantStack& m);
		MutantStack&			operator=(const MutantStack& m);

		inline const_iterator	begin() const { return (this->c.begin()); }
		inline const_iterator	end() const { return (this->c.end()); }

		inline iterator			begin() { return (this->c.begin()); }
		inline iterator			end() { return (this->c.end()); }

		~MutantStack();
};

#endif
