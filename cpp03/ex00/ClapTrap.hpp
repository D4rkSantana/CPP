/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 14:29:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class  ClapTrap
{
    private:
    public:
         ClapTrap();
         ClapTrap(const  ClapTrap& temp);
         ClapTrap& operator=(const  ClapTrap& temp);
        ~ ClapTrap();
};

#endif /*CLAPTRAP_HPP*/