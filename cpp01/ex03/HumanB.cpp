/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:41:50 by esilva-s          #+#    #+#             */
/*   Updated: 2023/06/06 20:45:30 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	this->is_armed = 0;
	std::cout << "The HumanA " << this->_name;
	std::cout << " was raised unarmed" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "The HumanA " << this->_name << " is destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->is_armed = 1;
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (this->is_armed)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their fists" << std::endl;
}