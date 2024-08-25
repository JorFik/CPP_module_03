/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:29:13 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/25 18:41:02 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <sstream>
#include <iostream>
#include <string>

ClapTrap::ClapTrap():
	_name("NPC"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
	{};

ClapTrap::ClapTrap(std::string name): ClapTrap()
{
	this->_name = name;
	std::cout << this->_formatName() << " is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_formatName() << " is scavenged for scrap." << std::endl;
}

ClapTrap &ClapTrap::operator =(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

std::string	ClapTrap::_formatName(void)
{
	std::stringstream	ss;

	ss << "ClapTrap " << this->_name;
	return (ss.str());
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_hitPoints == 0)
		return (this->_deadMessage(ATTACK));
	if (this->_energyPoints == 0)
		return (this->_noEnergyMessage(ATTACK));

	this->_energyPoints--;
	std::cout << this->_formatName() << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!";
	std::cout << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
		return (this->_deadMessage(TAKE_DAMAGE));

	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << this->_formatName();
	std::cout << " takes " << amount << " points of damage!" << std::endl;
	if (this->_hitPoints != 0)
		return ;
	std::cout << this->_formatName() << " is dead!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	const unsigned int	max_repair = 10 - this->_hitPoints;
	const unsigned int	repair = amount > max_repair ? max_repair : amount;

	if (this->_hitPoints == 0)
		return (this->_deadMessage(REPAIR));
	if (this->_energyPoints == 0)
		return (this->_noEnergyMessage(REPAIR));

	std::cout << this->_formatName();
	std::cout << " repaired itself, it recovered " << repair << " hit points!";
	std::cout << std::endl;
	this->_hitPoints += repair;
	this->_energyPoints--;
}

void	ClapTrap::_deadMessage(enum ClapTrapActions action)
{
	std::string	actions[] = {"attack", "repair itself", "take damage"};

	std::cout << this->_formatName() << " can't " << actions[action];
	std::cout << ", it's already dead!" << std::endl;
}

void	ClapTrap::_noEnergyMessage(enum ClapTrapActions action)
{
	std::string	actions[] = {"attack", "repair itself"};

	std::cout << this->_formatName() << " can't " << actions[action];
	std::cout << ", it doesn't have enough energy!" << std::endl;
}
