/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/15 16:45:55 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "The FragTrap " << this->name << " was created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& temp) : ClapTrap(temp.name)
{
    *this = temp;
    std::cout << "The FragTrap " << this->name << " has been cloned." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& temp)
{
    this->name = temp.name;
    this->hit_points = temp.hit_points;
    this->energy_points = temp.energy_points;
    this->attack_damage = temp.attack_damage;
    std::cout << "The FragTrap " << this->name << " was assigned." << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "The FragTrap " << this->name << " is destroyed." << std::endl;
}

//metodos

void    FragTrap::attack(const std::string& target)
{
    if (this->energy_points < 1 || this->hit_points < 1)
        return ;
    this->energy_points--;
    std::cout << "FragTrap " << this->name << " attacks " << target << ", causing ";
    std::cout << this->attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Hi Guys" << std::endl;
}
