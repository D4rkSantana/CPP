/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 14:29:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExe;

    public:
        Form();
        Form(std::string name, int gradeSign, int gradeExe);
        Form(const Form& temp);
        ~Form();

        Form& operator=(const Form& temp);
        
        std::string getName(void) const;
        bool        getSign(void) const;
        int         getGradeSign(void) const;
        int         getGradeExe(void) const;

        void        beSigned(const Bureaucrat& ref);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream&   operator<<( std::ostream &out, const Form &ref);

#endif /* FORM_HPP */