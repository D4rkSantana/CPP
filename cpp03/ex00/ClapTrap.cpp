/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 15:18:47 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "The ClapTrap " << this->name << " is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& temp)
{
    *this = temp;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& temp)
{
    this->name = temp.getName();
    this->hit_points = temp.getHitPoints();
    this->energy_points = temp.getEnergyPoints();
    this->attack_damage = temp.getAttackDamage();
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "The ClapTrap " << this->name << " is destroed." << std::endl;
}

std::string ClapTrap::getName(void) const
{
    return (this->name);
}

int ClapTrap::getHitPoints(void) const
{
    return (this->hit_points);
}

int ClapTrap::getEnergyPoints(void) const
{

    return (this->energy_points);
}

int ClapTrap::getAttackDamage(void) const
{
    return (this->attack_damage);
}

void ClapTrap::attack(const std::string& target)
{
    if (!this->energy_points > 0 && !this->hit_points > 0)
        return ;
    this->energy_points--;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing ";
    std::cout << this->attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{

}
