/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:05:19 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/29 20:45:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	string_toupper(std::string input)
{
	unsigned long   index;
	std::string	    result;

	index = 0;
	while (index < input.size())
	{
		result.push_back(toupper(input[index]));
		index++;
	}
	return (result);
}

int main(void)
{
    PhoneBook book;
    std::string arg;
    std::string command;

    while (1)
    {
        std::cout << "type a command, (a)dd, (s)earch, or (e)xit: ";
        std::cin >> arg;
        command = string_toupper(arg);
        if (command.compare("ADD") == 0 || command.compare("A") == 0)
            book.add_contact();
        else if (command.compare("SEARCH") == 0 || command.compare("S") == 0)
            book.search_contact();
        else if (command.compare("EXIT") == 0 || command.compare("E") == 0)
            break ;
        else
            std::cout << "invalid command, type again" << std::endl;
    }
    return (0);
}
