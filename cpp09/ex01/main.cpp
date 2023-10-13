/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/13 23:59:19 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	int result;

	if (argc != 2){
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	
	RPN rpn;
	try {
		result = rpn.calcule(argv[1]);
		std::cout << "Result: " << result << std::endl;
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
