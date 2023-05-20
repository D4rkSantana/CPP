/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:56:50 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/19 17:43:37 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "Phonebook created" << std::endl;
    this->pos = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destroed" << std::endl;
}

void	PhoneBook::add_contact(void)
{
    std::string vec[4];

    std::cout << "First Name: ";
    std::cin >> vec[0];
     std::cout << "Last Name: ";
    std::cin >> vec[1];
     std::cout << "Nickname: ";
    std::cin >> vec[2];
    std::cout << "Number Phone: ";
    std::cin >> vec[3];
    
    this->contacts[this->pos].edit(vec);
    if (this->pos < 7)
        this->pos = this->pos +1;
    else
        this->pos = 0;

}

void	PhoneBook::print_contacts(void)
{
    int index;

    index = 0;
    while (index < 8)
    {
        if (this->contacts[index].get_status() != 1)
            break ;
        std::cout << "[" << index << "]";
        std::cout << " name: " << this->contacts[index].get_name();
        std::cout << " number: " << this->contacts[index].get_number();
        std::cout << std::endl;
        index++;
    }
}
