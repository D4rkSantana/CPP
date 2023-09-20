/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_tools.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:40:59 by esilva-s          #+#    #+#             */
/*   Updated: 2023/09/19 21:22:21 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	string_tolower(std::string input)
{
	unsigned long	index;
	std::string		result;

	index = 0;
	while (index < input.size())
	{
        if (input[index] > 64 && input[index] < 91)
		    result.push_back(std::tolower(input[index]));
        else
            result.push_back(input[index]);
		index++;
	}
	return (result);
}
