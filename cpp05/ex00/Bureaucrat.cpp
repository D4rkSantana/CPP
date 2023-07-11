/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/19 15:30:15 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat was created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& temp)
{
    *this = temp;
    std::cout << "Bureaucrat was copied" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& temp)
{
    std::cout << "Bureaucrat has been assigned" << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat was destroyed" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
    return (this->name);
}

int         Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

void        Bureaucrat::incrementGrade(void)
{
    
}

void        Bureaucrat::decrementGrade(void)
{

}
