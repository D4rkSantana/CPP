/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:58:15 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/21 23:58:15 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
#include "AForm.hpp"
# include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	public:
        RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		~RobotomyRequestForm();

        std::string getTarget(void) const;
        void execute(Bureaucrat const &executor) const;

		RobotomyRequestForm &operator=(RobotomyRequestForm const & rhs);

	private:
        std::string _target;

};

std::ostream &operator<<(std::ostream & o, RobotomyRequestForm const & ref);

#endif /* ******************************************* RobotomyRequestFORM_H */