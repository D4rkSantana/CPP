/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s < esilva-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:38:30 by esilva-s          #+#    #+#             */
/*   Updated: 2023/06/10 17:13:28 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-";
    std::cout << "cheese-triple-pickle-specialketchup burger. ";
    std::cout << "I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn’t put enough bacon in my burger! ";
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. ";
    std::cout << "I’ve been coming for years whereas you started ";
    std::cout << "working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! ";
    std::cout << "I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{

}

Harl::~Harl()
{

}

void    Harl::complain(std::string level)
{
    int index = 0;
    std::string flags[4] = {"debug", "info", "warning", "error"};
    void (Harl::*members[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    while (index < 4 && level.compare(flags[index]))
        index++;
    if (index < 4)
        (this->*members[index])();
}
