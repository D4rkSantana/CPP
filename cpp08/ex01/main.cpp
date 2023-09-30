/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/09/30 03:38:07 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span span(20);
	span.addNumber(20);
	span.addNumber(21);
	span.addNumber(22);
	span.addNumber(23);
	try 
	{
		span[0] = 220;
		std::cout << span[0] << std::endl;
		std::cout << span[1] << std::endl;
		std::cout << span[2] << std::endl;
		std::cout << span[3] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
    return(0);
}
