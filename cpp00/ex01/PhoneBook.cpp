/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:56:50 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/26 19:12:36 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

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
    std::string vec[5];

    std::cout << "First Name: ";
    std::cin >> vec[0];
     std::cout << "Last Name: ";
    std::cin >> vec[1];
     std::cout << "Nickname: ";
    std::cin >> vec[2];
    std::cout << "Number Phone: ";
    std::cin >> vec[3];
    std::cout << "A Darkness Secret: ";
    std::cin >> vec[4];
    this->contacts[this->pos].edit(vec);
    if (this->pos < 7)
        this->pos = this->pos +1;
    else
        this->pos = 0;

}

int    PhoneBook::print_contacts()
{
    int index;

    index = 0;
    if (this->contacts[0].get_status() == 0)
    {
        std::cout << "No contact found" << std::endl;
        return (1);
    }
    print_headline();
    while (index < 8)
    {
        if (this->contacts[index].get_status() == 0)
            return (0);
        print_line(index, this->contacts[index].get_first(),
            this->contacts[index].get_last(), this->contacts[index].get_nick());
        index++;
    }
    return (0);
}

void    PhoneBook::print_search(int index)
{
    std::cout << "Index: " << index << std::endl;
    std::cout << "First Name: " << this->contacts[index].get_first() << std::endl;
    std::cout << "Last Name  " << this->contacts[index].get_last() << std::endl;
    std::cout << "Nickname  " << this->contacts[index].get_nick() << std::endl << std::endl;
    std::cout << "Number: " << this->contacts[index].get_number() << std::endl;
    std::cout << "Darkest Secret: " << this->contacts[index].get_secret() << std::endl;
}

void	PhoneBook::search_contact(void)
{
    std::string command;
    int index = 0;

    if (this->print_contacts())
        return ;
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
    print_search(index);
}

