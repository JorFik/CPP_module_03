/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:32:03 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/28 13:23:12 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

enum ScavTrapActions
{
	SCAV_ATTACK,
	GUARD_GATE,
};

class	ScavTrap : public ClapTrap
{
	private:
		std::string	_formatName(void) const override;
		void		_deadMessage(enum ScavTrapActions action) const;
		void		_noEnergyMessage(enum ScavTrapActions action) const;

	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &other) = default;

		void	attack(std::string const &target) override;
		void	guardGate(void);
};

#endif