/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 14:29:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
#define Intern_HPP

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
    public:
        Intern();
        Intern(const Intern& temp);
        Intern& operator=(const Intern& temp);
        ~Intern();

        AForm *makeShrubbery(std::string target);
        AForm *makeRobotomy(std::string target);
        AForm *makePardon(std::string target);

        AForm *makeForm(std::string, std::string);

        class FormNotFound : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream&   operator<<( std::ostream &out, const Intern &ref);

#endif /*Intern_HPP*/