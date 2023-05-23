/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:56:50 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/22 21:42:34 by esilva-s         ###   ########.fr       */
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
        std::cout << " name: " << this->contacts[index].get_first();
        std::cout << " number: " << this->contacts[index].get_number();
        std::cout << std::endl;
        index++;
    }
}

void    print_search(int index, Contact contact)
{
    std::cout << "Index: " << index << std::endl;
    std::cout << "First Name: " << contact.get_first() << std::endl;
    std::cout << "Last Name: " << contact.get_last() << std::endl;
    std::cout << "Nickname: " << contact.get_nick() << std::endl;
    std::cout << "Number: " << contact.get_number() << std::endl;
    std::cout << "Darkest Secret: " << contact.get_secret() << std::endl;

}

void	PhoneBook::search_contact(void)
{
    std::string command;
    int index = 0;

    this->print_contacts();
    std::cout << "enter the index of the contact: ";
    std::cin >> command;
    if (command.length() != 1)
    {
        std::cout << "wrong index" << std::endl;
        return ;
    }
    index = std::stoi(command);
    if (index < 0 || index > 7)
    {
        std::cout << "wrong index" << std::endl;
        return ;
    }
    if (this->contacts[index].get_status() != 1)
    {
        std::cout << "wrong index" << std::endl;
        return ;
    }
    print_search(index, this->contacts[index]);
}

