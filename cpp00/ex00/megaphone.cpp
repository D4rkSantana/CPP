/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:05:24 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/29 20:43:31 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>

std::string	string_toupper(std::string input)
{
	unsigned long	index;
	int				size;
	std::string		result;

	index = 0;
	size = input.size();
	while (index < input.size())
	{
		result.push_back(toupper(input[index]));
		index++;
	}
	return (result);
}

int	check_args(int argc)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	std::string	input;
	std::string	result;
	int			index = 1;

	if (check_args(argc))
		return (1);
	while (index < argc)
	{
		input += argv[index];
		index++;
	}
	result = string_toupper(input);
	std::cout << result << std::endl;
	return (0);
}