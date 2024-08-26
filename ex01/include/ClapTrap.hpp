/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:29:20 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/26 17:31:46 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

enum ClapTrapActions
{
	ATTACK,
	REPAIR,
	TAKE_DAMAGE,
};

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		int			_maxHitPoints;
		virtual std::string	_formatName(void) const;

	private:
		ClapTrap();
		void		_deadMessage(enum ClapTrapActions action) const;
		void		_noEnergyMessage(enum ClapTrapActions action) const;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();
		ClapTrap &operator =(const ClapTrap &other);

		virtual void	attack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif