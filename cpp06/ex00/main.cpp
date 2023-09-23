/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/09/23 10:36:44 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool checkInput(std::string input)
{
    size_t index = 0;

    if (input.empty())
        return (true);

    while (index < input.size())
    {
        if (std::isprint(input[index]))
            index++;
        else
            return (true);
    }
    return (false);
}

int main(int argc,char **argv)
{
    if (argc != 2)
    {
        std::cout << "use exactly 1 argument" << std::endl;
        return (0);
    }
    std::string input = argv[1];
    if (checkInput(input))
        std::cout << "type a valid argument" << std::endl;
    else
	    ScalarConverter::convert(input);
    return(0);
}
