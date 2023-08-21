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

Bureaucrat::Bureaucrat(const Bureaucrat& temp) : _name(temp.getName())
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

void Bureaucrat::signForm(AForm &form)
{

	if(form.getSigned())
	{
		std::cout << this->getName() << " couldn'd " << form.getName() << " because was signed" << std::endl;
		return; 
	}
	try 
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() <<std::endl;
	}
	catch (std::exception &e)
	{

		// <bureaucrat> couldn’t sign <Aform> because <reason>.
		std::cout << this->getName() << " couldn'd " << form.getName() << " because " << e.what() <<std::endl;

	}
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " did not execute the " << form.getName() << " because " << e.what() <<std::endl;
    }
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Graduation too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Graduation too low");
}

std::ostream&   operator<<( std::ostream &out, const Bureaucrat &ref)
{
    out << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
    return (out);
}