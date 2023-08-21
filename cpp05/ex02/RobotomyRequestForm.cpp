/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:57:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/21 23:57:01 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    this->_target = "default";
    std::cout << "RobotomyRequestForm Creation Form Default was created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    this->_target = target;
    std::cout << "RobotomyRequestForm Creation Form was created" << std::endl;    
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : AForm("RobotomyRequestForm", 72, 45)
{
    this->_target = src.getTarget();
    std::cout << "RobotomyRequestForm was copied" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm was destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
    {
        std::cout << "RobotomyRequestForm has been assigned" << std::endl;
        this->_target = rhs.getTarget();
    }
	return *this;
}

std::ostream &operator<<(std::ostream & o, RobotomyRequestForm const & ref)
{
	o << ref.getName() << ", target is " << ref.getTarget() << ", grade to signed " << ref.getGradeSigned() <<  ", grade to execute " << ref.getGradeExec() << ", is  signed? " << ref.getSigned() <<"." ;
	return o;
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    this->checkExecute(executor);
	std::srand(std::time(0));
	std::cout << "Drilling noises..." << std::endl;
	if(rand() % 2)
		std::cout <<  this->getTarget() <<" has been robotomized successfully " << std::endl;
	else 
		std::cout <<  this->getTarget() <<" fail to be robotized" << std::endl;
                                  
}


/*
** --------------------------------- METHODS ----------------------------------



*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string  RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

/* ************************************************************************** */