/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:48:30 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/26 21:15:42 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

std::string	DiamondTrap::_formatName(void) const
{
	return ("DiamondTrap " + this->_name);
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_scav_name"),
	FragTrap(name + "_frag_name")
{
	this->_name = name;
	this->_energyPoints = ScavTrap::_maxEnergyPoints;
	std::cout << CREATION_MSG << this->_formatName() << " was created.";
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other):
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other)
{
	this->_name = other._name;
	std::cout << CREATION_MSG << this->_formatName() << " was created.";
	std::cout << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << DESTRUCTION_MSG << this->_formatName() << " together, snapped.";
	std::cout << std::endl;
	std::cout << this->_formatName() << " consciousness was lost.";
	std::cout << std::endl;
}

DiamondTrap	&DiamondTrap::operator =(const DiamondTrap &other)
{
	if (this == &other)
		return (*this);
	this->ClapTrap::operator =(other);
	this->_name = other._name;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << this->_formatName() << " had a existential crisis.";
	std::cout << std::endl << "\t";
	std::cout << this->_formatName() + ": \"Who am I?\"" << std::endl << "\t";
	std::cout << this->_formatName() + ": \"I am more than the sum of my parts, ";
	std::cout << "I am " << this->_name;
	std::cout << ", but also " << this->FragTrap::_name + ".\"" << std::endl;
	if (this->FragTrap::_name != this->ScavTrap::_name)
	{
		std::cout << "\t" << this->_formatName() + ": \"Wait! but I am also ";
		std::cout << this->ScavTrap::_name + ".\"" << std::endl;
		std::cout << this->_formatName() << " had a mental breakdown.";
		return ;
	}
	std::cout << this->_formatName() << " achieved self-awareness!";
	std::cout << std::endl;
}
