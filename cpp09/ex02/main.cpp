/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/15 20:08:27 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	PmergeMe pmerge;
	std::vector<int> resultV;
	std::deque<int> resultD;
	std::clock_t start;
	std::clock_t end;
	double timeV;
	double timeD;

	std::cout << std::endl;
	if (argc < 3)
	{
		std::cerr << "Error: minimum 2 arguments" << std::endl;
		return (0);
	}

	try
	{
		start = std::clock();
		for (int i = 1; i < argc; i++)
		{
			pmerge.addNumberV(argv[i]);
		}
		resultV = pmerge.goSortV();
		end = std::clock();
		timeV = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
	
		start = std::clock();
		for (int i = 1; i < argc; i++)
		{
			pmerge.addNumberD(argv[i]);
		}
		resultD = pmerge.goSortD();
		end = std::clock();
		timeD = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	std::cout << "before: ";
	pmerge.printRawV();

	std::cout << "after : ";
	printVector(resultV);

	std::cout << "Time to process a range of " << pmerge.getSizeV() << " elements with std::vector : " << timeV << " ms\n";
	std::cout << "Time to process a range of " << pmerge.getSizeD() << " elements with std::deque  : " << timeD << " ms\n";




	return (0);
}