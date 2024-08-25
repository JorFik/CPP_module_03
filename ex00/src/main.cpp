/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:28:19 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/25 18:41:23 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	claptrap("Claptrap");

	for (int i = 0; i < 6; i++)
		claptrap.attack("Bandit");
	std::cout << std::endl;
	claptrap.takeDamage(5);
	for (int i = 0; i < 6; i++)
		claptrap.beRepaired(5);
	std::cout << std::endl;
	claptrap.takeDamage(5);
	claptrap.attack("Bandit");
	std::cout << std::endl;
	claptrap.takeDamage(5);
	claptrap.beRepaired(5);
	std::cout << std::endl;
	return (0);
}