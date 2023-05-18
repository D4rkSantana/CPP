/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:41:50 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/23 19:54:25 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	std::cout << "++ The HumanA " << this->_name;
	std::cout << " was raised unarmed" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "-- The HumanA " << this->_name << " is destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << "** " << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}