/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:28:19 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/26 17:30:53 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	claptrap("Clapy");
	std::cout << std::endl;
	ScavTrap	scavtrap("Scavy");
	std::cout << std::endl;
	ScavTrap	scavtrap2(ScavTrap("Scaver"));
	std::cout << std::endl;

	scavtrap2 = ScavTrap("Scavy Jr");
	std::cout << std::endl;
	scavtrap2.guardGate();
	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
	{
		claptrap.attack("Bandit");
		scavtrap.attack("Bandit");
	}
	std::cout << std::endl;

	claptrap.takeDamage(5);
	scavtrap.takeDamage(50);
	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
	{
		claptrap.beRepaired(2);
		scavtrap.beRepaired(20);
	}
	std::cout << std::endl;

	claptrap.takeDamage(50);
	scavtrap.takeDamage(50);
	std::cout << std::endl;
	claptrap.attack("Bandit");
	scavtrap.attack("Bandit");
	std::cout << std::endl;

	for (int i = 0; i < 40; i++)
		scavtrap.attack("Boss Bandit Joe");
	scavtrap.guardGate();
	std::cout << std::endl;
	claptrap.takeDamage(5);
	scavtrap.takeDamage(50);
	std::cout << std::endl;
	claptrap.beRepaired(5);
	scavtrap.beRepaired(50);
	std::cout << std::endl;
	return (0);
}
