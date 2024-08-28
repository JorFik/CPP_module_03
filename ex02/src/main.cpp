/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:28:19 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/28 13:27:21 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	ScavTrap	scavtrap("Scavy");
	std::cout << std::endl;
	FragTrap	fragtrap("Fraggy");
	std::cout << std::endl;

	FragTrap	fragtrap2(fragtrap);
	std::cout << std::endl;
	fragtrap2 = FragTrap("Fraggy Jr");
	std::cout << std::endl;
	fragtrap2.highFivesGuys();
	std::cout << std::endl;
	for (int i = 0; i < 25; i++)
	{
		fragtrap.attack("Bandit");
		scavtrap.attack("Bandit");
	}
	std::cout << std::endl;

	fragtrap.takeDamage(50);
	scavtrap.takeDamage(50);
	std::cout << std::endl;
	for (int i = 0; i < 25; i++)
	{
		fragtrap.beRepaired(20);
		scavtrap.beRepaired(20);
	}
	std::cout << std::endl;

	fragtrap.takeDamage(50);
	scavtrap.takeDamage(50);
	std::cout << std::endl;
	fragtrap.attack("Bandit");
	scavtrap.attack("Bandit");
	std::cout << std::endl;

	for (int i = 0; i < 55; i++)
		fragtrap.highFivesGuys();
	std::cout << std::endl;
	fragtrap.takeDamage(50);
	scavtrap.takeDamage(50);
	std::cout << std::endl;
	fragtrap.beRepaired(500);
	scavtrap.beRepaired(500);
	std::cout << std::endl;
	return (0);
}
