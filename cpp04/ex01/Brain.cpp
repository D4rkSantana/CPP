/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 15:09:25 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    this->ideias = new std::string[100];
    std::cout << "Brain was created" << std::endl;
}

Brain::Brain(const Brain& temp)
{
    this->ideias = temp.getIdeias();
    std::cout << "Brain was copied" << std::endl;
}

Brain &Brain::operator=(const Brain& temp)
{   
    this->ideias = temp.getIdeias();
    std::cout << "Brain has been assigned" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    delete [] (this->ideias);
    std::cout << "Brain was destroyed" << std::endl;
}

std::string *Brain::getIdeias(void) const
{
    return(this->ideias);
}
