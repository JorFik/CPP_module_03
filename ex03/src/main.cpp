/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:28:19 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/26 21:11:38 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	DiamondTrap	diamondTrap("Star_Platinum");
	std::cout << std::endl;
	FragTrap	fragTrap("Killer_Queen");
	std::cout << std::endl;

	diamondTrap = DiamondTrap("Crazy_Diamond");
	std::cout << std::endl;
	diamondTrap.whoAmI();
	std::cout << std::endl;
	diamondTrap.attack("Killer_Queen");
	fragTrap.attack("Crazy_Diamond");
	std::cout << std::endl;
	diamondTrap.guardGate();
	std::cout << std::endl;
	diamondTrap.takeDamage(50);
	std::cout << std::endl;
	diamondTrap.beRepaired(1000);
	std::cout << std::endl;
	diamondTrap.highFivesGuys();
	std::cout << std::endl;
	for (int i = 0; i < 50; i++)
		diamondTrap.attack("Killer_Queen");
	std::cout << std::endl;
	diamondTrap.takeDamage(99);
	std::cout << std::endl;
	diamondTrap.takeDamage(1);
	std::cout << std::endl;
	return (0);
}
