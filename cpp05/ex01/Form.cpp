/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:55:51 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/21 23:55:54 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Frank"), _gradeExec(150), _gradeSigned(100)
{
    std::cout << "Form was created" << std::endl;
	this->_signed = false;
}

Form::Form(const std::string name, int gradeSigned, int gradeExec) : _name(name), _gradeExec(gradeExec), _gradeSigned(gradeSigned)
{
	
    if (gradeExec < 1 || gradeSigned < 1)
        throw Form::GradeTooHighException();
    if (gradeExec > 150 || gradeSigned > 150)
		throw Form::GradeTooLowException();

	
    std::cout << "Form was created" << std::endl;
	this->_signed = false;
}
//duvida: signed eh falso?
Form::Form(const Form& temp) : _name(temp.getName()), _gradeExec(temp.getGradeExec()), _gradeSigned(temp.getGradeSigned())
{
	this->_signed = temp.getSigned();
    std::cout << "Form was copied" << std::endl;
}

Form::~Form()
{
    std::cout << "Form was destroyed" << std::endl;
}

//Duvida: tem que ter outros get? 
Form &Form::operator=(const Form& temp)
{
    std::cout << "Form has been assigned" << std::endl;
    this->_signed = temp.getSigned();
    return (*this);
}

std::string Form::getName(void) const
{
    return (this->_name);
}

int       Form::getGradeExec(void) const
{
    return (this->_gradeExec);
}

int   Form::getGradeSigned(void) const
{
    return (this->_gradeSigned);
}

bool   Form::getSigned(void) const
{
    return (this->_signed);
}


void Form::beSigned(Bureaucrat &bureaucrat)
{
	
	if (bureaucrat.getGrade() <= this->getGradeSigned())
	{
		this->_signed = true;
	}
	else
		throw Form::GradeTooLowException();

} 



const char* Form::GradeTooHighException::what() const throw()
{
    return ("Graduation too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Graduation too low");
}

std::ostream&   operator<<( std::ostream &out, const Form &ref)
{
    out << ref.getName() << ", Form grade to signed " << ref.getGradeSigned() <<  ", Form grade to execute " << ref.getGradeExec() << ", Form is  signed? " << ref.getSigned() <<"." ;

    return (out);
}