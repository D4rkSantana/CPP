/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:22:51 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/26 19:11:03 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact()
{
	this->first_name = " ";
	this->last_name = " ";
	this->nickname = " ";
	this->number_phone = " ";
    this->dark_secret = " ";
	this->in_use = 0;
}

Contact::~Contact()
{
	std::cout << "Contact destroyd" << std::endl;
}

std::string	Contact::get_first(void)
{
    return (this->first_name);
}

std::string	Contact::get_last(void)
{
    return (this->last_name);
}

std::string	Contact::get_nick(void)
{
    return (this->nickname);
}

std::string	Contact::get_number(void)
{
    return (this->number_phone);
}

std::string	Contact::get_secret(void)
{
    return (this->dark_secret);
}

int			Contact::get_status(void)
{
    return (this->in_use);
}

void        Contact::edit(std::string vec[5])
{
    this->first_name = vec[0];
    this->last_name = vec[1];
    this->nickname = vec[2];
    this->number_phone = vec[3];
    this->dark_secret = vec[4];
    this->in_use = 1;
}