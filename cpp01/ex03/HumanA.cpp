/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:41:55 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/23 19:54:35 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << "++ The HumanA " << this->_name << " was created ";
	std::cout << "and armed with " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "-- The HumanA " << this->_name << " is destroyed" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << "** " << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}