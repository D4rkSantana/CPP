/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s < esilva-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:40:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/06/07 11:38:03 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "replace.hpp"

//recebe 3 parametros (filename; string1; string2)
//subtistitui todas as ocorrencias de s1 por s2
//sava o resultado em um novo arquivo chamado filename.replace

static int	check_args(int argc)
{
	if (argc != 4)
	{
		std::cout << "Only 3 arguments bro!" << std::endl;
		std::cout << "./my_replace <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	std::string	content;
	std::string	result;

	if (check_args(argc))
		return (1);

	content = read_file(argv[1]);
	if (content == "")
	{
		std::cout << "File empyt" << std::endl;
		return (1);
	}
	std::cout << content;
	result = replace(content, argv[2], argv[3])
	return (0);
}

//checar quantidade de argumentos -- OK

//abrir arquivo -- OK
	//se não conseguir retornar erro -- OK

//salvar dados do arquivo -- OK
	//se estiver vazio retornar erro

//fazer substituições

//salvar no novo arquivo
