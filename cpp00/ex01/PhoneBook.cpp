/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:56:50 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/18 20:23:52 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    Contact cont_zero(" ", " ");
	
    std::cout << "Phonebook created" << std::endl;
    for(int i = 0; i < 8; i++)
        this->contacts[i] = cont_zero;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destroed" << std::endl;
}

void	PhoneBook::add_contact(void)
{
    std::string name;
    std::string number;

    std::cout << "\nName plss!\n";
    std::cin >> name;
    std::cout << "\nNumber plss!\n";
    std::cin >> number;

    Contact new_cont(name, number);
    
    this->contacts[this->pos] = new_cont;
    if (this->pos < 7)
        this->pos = this->pos +1;
    else
        this->pos = 0;

}
/*
void	PhoneBook::del_contact(std::string)
{

}

Contact	PhoneBook::get_contacts(void)
{

}
*/