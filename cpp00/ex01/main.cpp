/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:05:19 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/02 12:03:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook book;
    std::string arg;
    std::string command;

    while (!std::cin.eof())
    {
        std::cout << "type a command, ADD, SEARCH, or EXIT: ";
        command = catch_arg();
        if (command.compare("ADD") == 0)
            book.add_contact();
        else if (command.compare("SEARCH") == 0)
            book.search_contact();
        else if (command.compare("EXIT") == 0)
            break ;
        else if (std::cin.eof())
            break;
        else
            std::cout << "invalid command, type again" << std::endl;
    }
    return (0);
}
