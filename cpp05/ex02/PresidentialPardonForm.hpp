/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:56:54 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/21 23:56:55 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
#include "AForm.hpp"
# include <cstdlib>

#include <ctime>

class PresidentialPardonForm : public AForm
{
	public:
        PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		~PresidentialPardonForm();

        std::string getTarget(void) const;
        void execute(Bureaucrat const &executor) const;

		PresidentialPardonForm &operator=(PresidentialPardonForm const & rhs);

	private:
        std::string _target;

};

std::ostream &operator<<(std::ostream & o, PresidentialPardonForm const & ref);

#endif /* ******************************************* PresidentialPardonFORM_H */