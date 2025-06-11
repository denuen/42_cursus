/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:37:37 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/11 15:43:19 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {

	protected:
		std::string	name;
		std::string	type;

	public:
		Animal();
		Animal( const std::string& newName );
		Animal ( const Animal& animal );

		Animal&	operator=( const Animal& animal );

		inline const std::string&	getName( void ) const { return (name); }
		inline const std::string&	getType( void ) const { return (type); }
		inline void					setName( const std::string& newName ) { name = (newName == "") ? name : newName; }
		inline void 				setType( const std::string& newType ) { type = (newType == "") ? type: newType; }

		virtual void	makeSound( void ) const {};

		virtual ~Animal();
};

#endif
