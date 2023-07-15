/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/15 16:29:43 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void    line(std::string str)
{
    if (str.compare("") == 0)
        std::cout << "---------------------" << std::endl;
    else if (str.compare("=") == 0)
        std::cout << "=====================" << std::endl;
    else
        std::cout << std::endl << "======" << str << "======" << std::endl << std::endl;
}

void    clap(ClapTrap &obj)
{
    line("Init Clap");
    obj.status();
    line("");
    obj.attack("trapton");
    obj.takeDamage(3);
    obj.beRepaired(6);
    line("");
    obj.status();
    line("End  Clap");
}

int main()
{
    ClapTrap clapton("marx");

    clap(clapton);
    return(0);
}
