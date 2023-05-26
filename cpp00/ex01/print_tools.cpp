/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:56:57 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/26 18:58:22 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static void    print_div(void)
{
    std::cout << "---------------------------------------------" << std::endl;
}

static void	print_coluns(std::string str)
{
    if (str.length() > 10)
    {
        str.erase(9, str.length());
        str.push_back('.');
    }
    else if (str.length() < 10)
    {
        while (str.length() < 10)
        {
            str.push_back(' ');
        }
    }
    std::cout << str << "|";
}

void    print_line(int index, std::string fname, std::string lname, std::string nick)
{
    std::cout << "|" << index << "         |";
    print_coluns(fname);
    print_coluns(lname);
    print_coluns(nick);
    std::cout << std::endl;
    print_div();
}

void    print_headline(void)
{
    print_div();
    std::cout << "|Index     |";
    std::cout << "First Name|";
    std::cout << "Last Name |";
    std::cout << "Nickname  |" << std::endl;
    print_div();
}