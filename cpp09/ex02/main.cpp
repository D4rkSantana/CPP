/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/14 23:35:28 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	PmergeMe pmerge;
	std::vector<int> resultV;
	std::deque<int> resultD;

	if (argc < 3)
	{
		std::cerr << "Error: minimum 2 arguments" << std::endl;
		return (0);
	}

	try
	{
		for (int i = 1; i < argc; i++)
		{
			pmerge.addNumber(argv[i]);
		}
		resultV = pmerge.goSortV();
		resultD = pmerge.goSortD();

		std::cout << std::endl;
		printVector(resultV);
		std::cout << std::endl;
		printDeque(resultD);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}