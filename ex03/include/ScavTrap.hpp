/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:32:03 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/26 20:54:06 by JFikents         ###   ########.fr       */
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

class	ScavTrap : virtual public ClapTrap
{
	private:
		std::string	_formatName(void) const override;
		void		_deadMessage(enum ScavTrapActions action) const;
		void		_noEnergyMessage(enum ScavTrapActions action) const;

	protected:
		static const int	_maxEnergyPoints = 50;

	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();

		void	attack(std::string const &target) override;
		void	guardGate(void);
};

#endif