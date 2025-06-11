/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:49:27 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/11 14:01:37 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : FragTrap(), ScavTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->name = "(null)";
	ClapTrap::name = this->name + "_clap_name";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap( const std::string newName ) :\
	FragTrap(newName + "_clap_name"), ScavTrap(), name(newName == "" ? "(null)" : newName) {
	std::cout << "DiamondTrap constructor with parameters called" << std::endl;
	ClapTrap::name = this->name + "_clap_name";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap( const DiamondTrap& diamondTrap ) :\
	FragTrap(diamondTrap), ScavTrap(diamondTrap), name(diamondTrap.name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	ClapTrap::name = diamondTrap.ClapTrap::name;
	this->hitPoints = diamondTrap.hitPoints;
	this->energyPoints = diamondTrap.energyPoints;
	this->attackDamage = diamondTrap.attackDamage;
}

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& diamondTrap ) {
	std::cout << "DiamondTrap copy assignment constructor called" << std::endl;
	if (this != &diamondTrap) {
		FragTrap::operator=(diamondTrap);
		ScavTrap::operator=(diamondTrap);
		this->name = diamondTrap.name;
		this->energyPoints = diamondTrap.energyPoints;
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap here!\nMy full name is " << name << " " << FragTrap::ClapTrap::name << " junior, sir!\n" \
				"Here to help!" << std::endl;
}

void	DiamondTrap::attack( const std::string& target ) {
	if (energyPoints > 0 && hitPoints > 0) {
		std::cout << "DiamondTrap " << name << " attacks " << target << ", causing " \
					<< attackDamage << " points of damage!";
		std::cout << std::endl;
		energyPoints -= 1;
	} else if (energyPoints == 0) {
		std::cout << "DiamondTrap " << name << " attack failed!\n";
		std::cout << "DiamondTrap " << name << " has no more energy points left.";
		std::cout << std::endl;
	}
	else {
		std::cout << "DiamondTrap " << name << " attack failed!\n";
		std::cout << "DiamondTrap " << name << " has no more hit points left.";
	}
	std::cout << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}
