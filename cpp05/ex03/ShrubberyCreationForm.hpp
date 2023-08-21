/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:58:31 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/21 23:58:34 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
        ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm();

        std::string getTarget(void) const;
        void execute(Bureaucrat const &executor) const;

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const & rhs);

	private:
        std::string _target;

};

std::ostream &operator<<(std::ostream & o, ShrubberyCreationForm const & ref);

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */