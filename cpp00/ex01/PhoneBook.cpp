/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s < esilva-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:56:50 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/02 19:05:36 by esilva-s         ###   ########.fr       */
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
	std::cout << std::endl << "Phonebook destroed" << std::endl;
}

void	PhoneBook::add_contact(void)
{
    std::string vec[5];

    
    std::cout << "First Name: ";
    vec[0] = catch_arg();
    if (std::cin.eof())
        return ;
    std::cout << "Last Name: ";
    vec[1] = catch_arg();
    if (std::cin.eof())
        return ;
    std::cout << "Nickname: ";
    vec[2] = catch_arg();
    if (std::cin.eof())
        return ;
    std::cout << "Number Phone: ";
    vec[3] = catch_arg();
    if (std::cin.eof())
        return ;
    std::cout << "A Darkness Secret: ";
    vec[4] = catch_arg();
    if (std::cin.eof())
        return ;
    if (empyt_check(vec, 5))
    {
        std::cout << "empty fields are not accepted" << std::endl;
        return ;
    }
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
    print_div();
    std::cout << "Index: " << index << std::endl;
    std::cout << "First Name: " << this->contacts[index].get_first() << std::endl;
    std::cout << "Last Name  " << this->contacts[index].get_last() << std::endl;
    std::cout << "Nickname  " << this->contacts[index].get_nick() << std::endl;
    std::cout << "Number: " << this->contacts[index].get_number() << std::endl;
    std::cout << "Darkest Secret: " << this->contacts[index].get_secret() << std::endl;
    print_div();
}

void	PhoneBook::search_contact(void)
{
    std::string command;
    int index = 0;

    if (this->print_contacts())
        return ;
    std::cout << "enter the index of the contact: ";
    command = catch_arg();
    if (std::cin.eof())
        return ;
    if (command.length() != 1 || !str_isdigit(command.c_str()))
    {
        std::cout << "wrong index" << std::endl;
        return ;
    }
    index = atoi(command.c_str());
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

