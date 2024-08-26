/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:39:49 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/26 19:33:24 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


std::string	FragTrap::_formatName(void) const
{
	std::string	_formatedName;

	_formatedName = "FragTrap " + this->_name;
	return (_formatedName);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_maxHitPoints = 100;
	this->_hitPoints = this->_maxHitPoints;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << this->ClapTrap::_formatName() << " was upgraded to ";
	std::cout << this->_formatName() + "." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << this->ClapTrap::_formatName() << " was upgraded to ";
	std::cout << this->_formatName() + "." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << this->_formatName() << " was downgraded to ";
	std::cout << this->ClapTrap::_formatName() + "." << std::endl;
}

void	FragTrap::_deadMessage(void) const
{
	std::cout << this->_formatName() << " can't ask for High Fives";
	std::cout << ", it's already dead!" << std::endl;
}

void	FragTrap::_noEnergyMessage(void) const
{
	std::cout << this->_formatName() << " can't ask for High Fives";
	std::cout << ", it doesn't have enough energy!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints == 0)
		return (this->_deadMessage());
	if (this->_energyPoints == 0)
		return (this->_noEnergyMessage());

	this->_energyPoints -= 1;
	std::cout << this->_formatName() << " asked for High Fives!" << std::endl;
	std::cout << "High Fives for everyone!" << std::endl;
}
