/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:48:35 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/26 20:53:38 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# define CREATION_MSG "By combining the upgrade parts of ScavTrap and FragTrap, a new "
# define DESTRUCTION_MSG "The Fragile rubber band that held "

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
		std::string	_formatName(void) const override;

	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();
		DiamondTrap &operator =(const DiamondTrap &other);

		void	whoAmI(void);
};

#endif