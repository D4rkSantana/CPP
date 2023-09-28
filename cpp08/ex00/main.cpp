/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/09/28 23:18:03 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	size_t index = 0;

	// criando e preenchendo os valores do conteiner
	std::vector<int> inter;
	
	while (index < 11)
	{
		inter.push_back(static_cast<int>(index));
		index++;
	}

	// Procurando o elemento no conteiner
	try {
		easyfind(inter, 10);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    return(0);
}
