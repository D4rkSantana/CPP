/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/01 03:03:26 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void teste_subject(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return ;
}

void teste_from_hell(void)
{
	unsigned int	index = 0;

	Span sp = Span(100000);
	
	if (!sp.insertAll(0))
		return ;
	if (!sp.insertIncrementAll(0))
		return ;
	if (!sp.insertInRange(99950, 99990, 42))
		return ;
	
	while (index < sp.getSize())
	{
		std::cout << "[" << index << "]:" << sp.getElement(index) << " ";
		index++;
	}
	std::cout << "\nshort: " << sp.shortestSpan() << " long: " << sp.longestSpan() << "\n";
	std::cout << "size: " << sp.getSize() << " used: " << sp.getUsed() << std::endl;
}

void teste_basico(void)
{
	unsigned int	index = 0;

	Span sp = Span(10);
	
	if (!sp.insertAll(0))
		return ;
	if (!sp.insertIncrementAll(0))
		return ;
	if (!sp.insertInRange(9700, 9900, 42))
		return ;
	
	while (index < sp.getSize())
	{
		std::cout << "[" << index << "]:" << sp.getElement(index) << " ";
		index++;
	}
	std::cout << "\nshort: " << sp.shortestSpan() << " long: " << sp.longestSpan() << "\n";
	std::cout << "size: " << sp.getSize() << " used: " << sp.getUsed() << std::endl;
}

int main()
{
	//teste_basico();
	teste_from_hell();

	//teste_subject();
	
	return (0);
}
