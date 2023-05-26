/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:05:19 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/26 19:11:08 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string	string_toupper(std::string input)
{
	int			index;
	int			size;
	std::string	result;

	index = 0;
	size = input.size();
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
    std::cout << "end!" << std::endl;
    return (0);
}
