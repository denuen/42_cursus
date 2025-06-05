/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:57:04 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/04 17:10:41 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

private:
	std::string	name;
	Weapon		weapon;

public:
	HumanA(const std::string& name = "null", const Weapon& newWeapon = Weapon("null"));

	const std::string&	getName( void ) const { return (name); }
	void				setName ( const std::string& newName ) { name = newName; }

	void				attack( void );

	~HumanA();

};

#endif
