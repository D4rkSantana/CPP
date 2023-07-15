/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 14:29:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap& temp);
        FragTrap& operator=(const FragTrap& temp);
        ~FragTrap();
        void    attack(const std::string& target);
        void    highFivesGuys(void);

};

#endif /*FRAGTRAP_HPP*/