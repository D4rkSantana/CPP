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

Bureaucrat::Bureaucrat() : _name("Frank"), _grade(150)
{
    std::cout << "Bureaucrat was created" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat was created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& temp)
{
    std::cout << "Bureaucrat was copied" << std::endl;
    this->_grade = temp.getGrade();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat was destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& temp)
{
    std::cout << "Bureaucrat has been assigned" << std::endl;
    this->_grade = temp.getGrade();
    return (*this);
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int         Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void        Bureaucrat::incrementGrade(void)
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void        Bureaucrat::decrementGrade(void)
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Graduation too high, graduation must be between 1 and 150");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Graduation too low, graduation must be between 1 and 150");
}

std::ostream&   operator<<( std::ostream &out, const Bureaucrat &ref)
{
    out << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".\n";
    return (out);
}