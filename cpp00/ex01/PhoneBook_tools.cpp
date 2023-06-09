/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_tools.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s < esilva-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:56:57 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/02 19:12:42 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string catch_arg(void)
{
    std::string arg;

    std::getline(std::cin, arg);
    return (arg);
}

bool    empyt_check(std::string vec[], int size)
{
    int i = 0;

    while (i < size)
    {
        if (vec[i].empty())
            return (true);
        i++;
    }
    return (false);
}

static int  char_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int str_isdigit(const char *str)
{
    int index = 0;

    while (str[index] != 0)
    {
        if (!char_isdigit(str[index]))
            return (0);
        index++;
    }
    return (1);
}

void    print_div(void)
{
    std::cout << std::setfill('-') << std::setw(45); 
    std::cout << "-" << std::endl;
}

static void	print_coluns(std::string str)
{
    if (str.length() > 10)
    {
        str.erase(9, str.length());
        str.push_back('.');
    }
    std::cout << std::setfill(' ') << std::setw(10);
    std::cout << str << "|";
}

void    print_line(int index, std::string fname, std::string lname, std::string nick)
{
    std::cout << "|";
    std::cout << std::setfill(' ') << std::setw(10);
    std::cout << index << "|";
    print_coluns(fname);
    print_coluns(lname);
    print_coluns(nick);
    std::cout << std::endl;
    print_div();
}

void    print_headline(void)
{
    print_div();
    std::cout << "|";
    std::cout << std::setfill(' ') << std::setw(10);
    std::cout << "Index" << "|";
    std::cout << std::setfill(' ') << std::setw(10);
    std::cout << "First Name" << "|";
    std::cout << std::setfill(' ') << std::setw(10);
    std::cout << "Last Name" << "|";
    std::cout << std::setfill(' ') << std::setw(10);
    std::cout << "Nickname" << "|" << std::endl;
    print_div();
}