/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:22:51 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/19 17:38:51 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->name = " ";
	this->last_name = " ";
	this->nickname = " ";
	this->number_phone = " ";
	this->in_use = 0;
}

Contact::~Contact()
{
	std::cout << "Contact destroyd" << std::endl;
}

std::string	Contact::get_name(void)
{
    return (this->name);
}

std::string	Contact::get_number(void)
{
    return (this->number_phone);
}

int			Contact::get_status(void)
{
    return (this->in_use);
}

void        Contact::edit(std::string vec[4])
{
    this->name = vec[0];
    this->last_name = vec[1];
    this->nickname = vec[2];
    this->number_phone = vec[3];
    this->in_use = 1;
}