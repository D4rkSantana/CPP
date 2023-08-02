/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/19 15:30:15 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeSign(150), _gradeExe(150)
{
    std::cout << "Form Default was created" << std::endl;
}

Form::Form(const std::string name, int gradeSign, int gradeExe) : _name(name), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
    if (gradeSign < 1 || gradeExe < 1)
        throw Form::GradeTooHighException();
    if (gradeSign > 150 || gradeExe > 150)
        throw Form::GradeTooLowException();
    this->_signed = false;
    std::cout << "Form " << name << " was created" << std::endl;
}

Form::Form(const Form &temp) : _name(temp.getName()), _gradeSign(temp.getGradeSign()), _gradeExe(temp.getGradeExe())
{
    this->_signed = temp.getSign();
    std::cout << "Form was copied" << std::endl;
}

Form::~Form()
{
    std::cout << "Form was destroyed" << std::endl;
}

Form &Form::operator=(const Form& temp)
{
    std::cout << "Form has been assigned" << std::endl;
    this->_signed = temp.getSign();
    return (*this);
}

std::string Form::getName(void) const
{
    return (this->_name);
}

bool         Form::getSign(void) const
{
    return (this->_signed);
}

int         Form::getGradeSign(void) const
{
    return (this->_gradeSign);
}

int         Form::getGradeExe(void) const
{
    return (this->_gradeExe);
}

void        Form::beSigned(const Bureaucrat &ref)
{
    if (ref.getGrade() <= this->_gradeSign)
        this->_signed = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Graduation too high, graduation must be between 1 and 150");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Graduation too low, graduation must be between 1 and 150");
}

std::ostream&   operator<<( std::ostream &out, const Form &ref)
{
    out << ref.getName() << " Form need " << ref.getGradeSign() << " grade to be signed and " << ref.getGradeExe() << " to execute.";
    return (out);
}