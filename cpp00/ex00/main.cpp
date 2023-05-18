/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:05:24 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/18 01:22:15 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>

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

int	check_args(int argc)
{
	if (argc == 1)
	{
		std::cout << "Estatica bizzzzzz zzzzzz" << std::endl;
		return (1);
	}
	if (argc > 2)
	{
		std::cout << "Digite somente uma mensagem por gentileza" << std::endl;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	std::string	result;

	if (check_args(argc))
		return (1);
	result = string_toupper(argv[1]);
	std::cout << result << std::endl;
	return (0);
}