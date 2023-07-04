/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:40:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/04 17:10:21 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "replace.hpp"

//recebe 3 parametros (filename; string1; string2)
//subtistitui todas as ocorrencias de s1 por s2
//sava o resultado em um novo arquivo chamado filename.replace

static int	check_argc(int argc)
{
	if (argc != 4)
	{
		std::cout << "Only 3 arguments!" << std::endl;
		std::cout << "./my_replace <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	return (0);
}

static int	check_args(std::string arguments[3])
{
	if (arguments[0] == "" || arguments[1] == "" || arguments[2] == "")
	{
		std::cout << "fields cannot be empty" << std::endl;
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	std::string	arguments[3];

	if (check_argc(argc))
		return (1);

	arguments[0] = argv[1];
	arguments[1] = argv[2];
	arguments[2] = argv[3];

	if (check_args(arguments))
		return (1);
	replace(arguments);
	return (0);
}
