/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:40:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/23 21:33:14 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

static int	check_args(int argc)
{
	if (argc != 4)
	{
		std::cout << "Only 3 arguments bro!" << std::endl;
		std::cout << "./a.out <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	std::string	content;

	if (check_args(argc))
		return (1);

	content = read_file(argv[1]);
	if (content == "")
	{
		std::cout << "File Error" << std::endl;
		return (1);
	}

	std::cout << content;
	return (0);
}

//checar quantidade de argumentos -- OK

//abrir arquivo
	//se não conseguir retornar erro

//salvar dados do arquivo
	//se estiver vazio retornar erro

//fazer substituições

//salvar no novo arquivo
