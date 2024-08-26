/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:32:42 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/26 17:32:48 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

std::string	ScavTrap::_formatName(void) const
{
	std::string	_formatedName;

	_formatedName = "ScavTrap " + this->_name;
	return (_formatedName);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_maxHitPoints = 100;
	this->_hitPoints = this->_maxHitPoints;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << this->ClapTrap::_formatName() << " was upgraded to ";
	std::cout << this->_formatName() + "." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << this->ClapTrap::_formatName() << " was upgraded to ";
	std::cout << this->_formatName() + "." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->_formatName() << " was downgraded to ";
	std::cout << this->ClapTrap::_formatName() + "." << std::endl;
}

void	ScavTrap::_deadMessage(enum ScavTrapActions action) const
{
	std::string	actions[] = {"attack", "guard the gate"};

	std::cout << this->_formatName() << " can't " << actions[action];
	std::cout << ", it's already dead!" << std::endl;
}

void	ScavTrap::_noEnergyMessage(enum ScavTrapActions action) const
{
	std::string	actions[] = {"attack", "guard the gate"};

	std::cout << this->_formatName() << " can't " << actions[action];
	std::cout << ", it doesn't have enough energy!" << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_hitPoints == 0)
		return (this->_deadMessage(SCAV_ATTACK));
	if (this->_energyPoints == 0)
		return (this->_noEnergyMessage(SCAV_ATTACK));

	this->_energyPoints--;
	std::cout << this->_formatName() << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!";
	std::cout << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints == 0)
		return (this->_deadMessage(GUARD_GATE));
	if (this->_energyPoints == 0)
		return (this->_noEnergyMessage(GUARD_GATE));

	this->_energyPoints--;
	std::cout << this->_formatName() << " entered in gate keeper mode, ";
	std::cout << "it will guard the gate with his life!";
	std::cout << std::endl;
}
