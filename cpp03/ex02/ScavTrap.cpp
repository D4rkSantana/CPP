/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/15 16:40:06 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "The ScavTrap " << this->name << " was created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& temp) : ClapTrap(temp.name)
{
    *this = temp;
    std::cout << "The ScavTrap " << this->name << " has been cloned." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& temp)
{
    this->name = temp.name;
    this->hit_points = temp.hit_points;
    this->energy_points = temp.energy_points;
    this->attack_damage = temp.attack_damage;
    std::cout << "The ScavTrap " << this->name << " was assigned." << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "The ScavTrap " << this->name << " is destroyed." << std::endl;
}

//metodos

void    ScavTrap::attack(const std::string& target)
{
    if (this->energy_points < 1 || this->hit_points < 1)
        return ;
    this->energy_points--;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing ";
    std::cout << this->attack_damage << " points of damage!" << std::endl;
}

void    ScavTrap::gardGate(void)
{
    std::cout << this->name << " was in Gatekeeper mode." << std::endl;
}
