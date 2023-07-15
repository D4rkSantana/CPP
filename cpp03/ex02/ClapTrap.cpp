/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/15 16:40:02 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "The ClapTrap " << this->name << " was created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& temp)
{
    *this = temp;
    std::cout << "The ClapTrap " << this->name << " has been cloned." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& temp)
{
    this->name = temp.name;
    this->hit_points = temp.hit_points;
    this->energy_points = temp.energy_points;
    this->attack_damage = temp.attack_damage;
    std::cout << "The ClapTrap " << this->name << " was assigned." << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "The ClapTrap " << this->name << " is destroyed." << std::endl;
}

//metodos

void ClapTrap::status(void) const
{
    std::cout << "Name       : " << this->name << std::endl;
    std::cout << "Hit Pts    : " << this->hit_points << std::endl;
    std::cout << "Energy Pts : " << this->energy_points << std::endl;
    std::cout << "Attack Dmg : " << this->attack_damage << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energy_points < 1 || this->hit_points < 1)
        return ;
    this->energy_points--;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing ";
    std::cout << this->attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points < 1)
        return ;
    this->hit_points -= amount;
    std::cout << this->name << " take " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_points < 1 || this->hit_points < 1)
        return ;
    this->energy_points--;
    this->hit_points += amount;
    std::cout << this->name << " has be repaired " << amount << " hit points" << std::endl;
}
