/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/14 00:00:23 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2){
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange	btc(argv[1]);
	}
	catch (std::exception const &e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}