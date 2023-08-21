/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/19 15:30:15 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern was created" << std::endl;
}

Intern::Intern(const Intern& temp)
{
    (void)temp;
    std::cout << "Intern was copied" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern was destroyed" << std::endl;
}

AForm *Intern::makeShrubbery(std::string target)
{
    AForm *obj = new ShrubberyCreationForm(target);
    return obj;
}
    
AForm *Intern::makeRobotomy(std::string target)
{
    AForm *obj = new RobotomyRequestForm(target);
    return obj;
}

AForm *Intern::makePardon(std::string target)
{
    AForm *obj = new PresidentialPardonForm(target);
    return obj;
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    int index = 0;
    std::string titles[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm* (Intern::*members[3])(std::string) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePardon};
    
    while (index < 3)
    {
        if (!titles[index].compare(form))
            break ;
        index++;
    }

    if (index == 3)
        throw Intern::FormNotFound();

    AForm *obj = (this->*members[index])(target);
    std::cout << "Intern creates " << form << std::endl;
    return (obj);
}

Intern &Intern::operator=(const Intern& temp)
{
    (void)temp;
    std::cout << "Intern has been assigned" << std::endl;
    return (*this);
}

const char* Intern::FormNotFound::what() const throw()
{
    return ("Form not found");
}

std::ostream&   operator<<( std::ostream &out, const Intern &ref)
{
    (void)ref;
    out << "Intern.";
    return (out);
}