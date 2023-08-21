/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:57:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/21 23:57:29 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSigned;
		const int			_gradeExec;

	public:
		AForm();
		AForm(const std::string name, int gradeSigned, int gradeExec);
		AForm(const	AForm& temp);
		AForm& operator=(const	AForm& temp);
		virtual ~AForm() = 0;

		std::string getName(void) const;
		int getGradeExec(void) const;
		int getGradeSigned(void) const;
		bool getSigned(void) const;

		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
		void	checkExecute(Bureaucrat const &executor) const;

        class GradeTooHighException : public std::exception
        {
            public:
               virtual  const char* what() const throw();
        };

        class GradeTooLowException :    public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

		class FormNotSignedException :    public std::exception
        {
            public:
                virtual const char* what() const throw();
        };



};

std::ostream&   operator<<( std::ostream &out, const AForm &ref);

#endif