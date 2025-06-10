/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:24:44 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/10 12:28:14 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

const int	HIT_POINTS = 10;
const int	ENERGY_POINTS = 10;
const int	ATTACK_DAMAGE = 0;

class ClapTrap {

	private:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;

	public:
		ClapTrap();
		ClapTrap( const std::string& newName );
		ClapTrap( const ClapTrap& clapTrap );

		ClapTrap&							operator=( const ClapTrap& clapTrap );

		inline const std::string&			getName( void ) const { return (name); }
		inline const unsigned int&			getHitPoints( void ) const { return (hitPoints); }
		inline const unsigned int&			getEnergyPoints( void ) const { return (energyPoints); }
		inline const unsigned int&			getAttackDamage( void ) const { return (attackDamage); }

		inline void							setName( const std::string& newName ) { name = newName; }
		inline void							setHitPoints( const unsigned int& newHitPoints ) { hitPoints = newHitPoints; }
		inline void							setEnergyPoints( const unsigned int& newEnergyPoints ) { energyPoints = newEnergyPoints; }
		inline void							setAttackDamage( const unsigned int& newAttackDamage ) { attackDamage = newAttackDamage; }

		void								attack( const std::string& target );
		void								takeDamage( unsigned int amount );
		void								beRepaired( unsigned int amount );

		~ClapTrap();
};

#endif
