/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:40:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/22 18:09:47 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string	mensage;
	std::string	*stringPTR;
	std::string &stringREF = mensage;
	mensage = "HI THIS IS BRAIN";
	stringPTR = &mensage;
	
	std::cout << std::endl << "======== Addr =========" << std::endl;
	std::cout << "addr mensage  : " << &mensage << std::endl;
	std::cout << "addr stringPTR: " << &stringPTR << std::endl;
	std::cout << "addr stringREF: " << &stringREF << std::endl;

	std::cout << std::endl << "======= String =========" << std::endl;
	std::cout << "mensage  : " << mensage << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
	std::cout << std::endl;
	
	return (1);
}
