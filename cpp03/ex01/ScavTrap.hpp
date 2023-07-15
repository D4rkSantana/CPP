/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 14:29:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& temp);
        ScavTrap& operator=(const ScavTrap& temp);
        ~ScavTrap();
        void        attack(const std::string& target);
        void        gardGate(void);

};

#endif /*SCAVTRAP_HPP*/