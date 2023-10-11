/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/29 00:25:47 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Template.hpp"

Template::Template()
{
    std::cout << "Template was created" << std::endl;
}

Template::Template(const Template& temp)
{
    *this = temp;
    std::cout << "Template was copied" << std::endl;
}

Template &Template::operator=(const Template& temp)
{
    std::cout << "Template has been assigned" << std::endl;
    return (*this);
}

Template::~Template()
{
    std::cout << "Template was destroyed" << std::endl;
}

std::ostream&   operator<<( std::ostream &out, const Template &ref)
{
	(void)ref;
    out << "Template ";
    return (out);
}