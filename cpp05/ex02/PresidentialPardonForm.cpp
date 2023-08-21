/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:56:47 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/21 23:56:50 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
    this->_target = "default";
    std::cout << "PresidentialPardonForm Creation Form Default was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
    this->_target = target;
    std::cout << "PresidentialPardonForm Creation Form was created" << std::endl;    
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : AForm("PresidentialPardonForm", 25, 5)
{
    this->_target = src.getTarget();
    std::cout << "PresidentialPardonForm was copied" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm was destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
    {
        std::cout << "PresidentialPardonForm has been assigned" << std::endl;
        this->_target = rhs.getTarget();
    }
	return *this;
}

std::ostream &operator<<(std::ostream & o, PresidentialPardonForm const & ref)
{
	o << ref.getName() << ", target is " << ref.getTarget() << ", grade to signed " << ref.getGradeSigned() <<  ", grade to execute " << ref.getGradeExec() << ", is  signed? " << ref.getSigned() <<"." ;
	return o;
}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    this->checkExecute(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;                            
}


/*
** --------------------------------- METHODS ----------------------------------



*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

/* ************************************************************************** */