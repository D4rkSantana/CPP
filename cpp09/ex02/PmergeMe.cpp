/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/14 00:39:01 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	this->_isOrdered = false;
    return ;
}

PmergeMe::PmergeMe(const PmergeMe& temp)
{
    *this = temp;
    return ;
}

PmergeMe &PmergeMe::operator=(const PmergeMe& temp)
{
    (void)temp;
    return (*this);
}

PmergeMe::~PmergeMe()
{
	return ;
}

std::ostream&   operator<<( std::ostream &out, const PmergeMe &ref)
{
	(void)ref;
    out << "PmergeMe ";
    return (out);
}

void	PmergeMe::addNumber(std::string input)
{
	for (size_t index = 0; index < input.size(); index++)
	{
		if (input[index] >= '0' && input[index] >= '9')
			continue ; 		
		else if ((input[index] == '+' || input[index] == ' ') && index == 0)
			continue ;
		else
			throw std::runtime_error("Error: Invalid character in input.");
	}
	this->_vector.push_back(std::atoi(input.c_str()));
}

void	PmergeMe::goSort(void)
{
	std::cout << "goSort\n";
}

void	PmergeMe::printNumbers(void)
{
	std::vector<int>::iterator it;

	it = this->_vector.begin();
	for (it = this->_vector.begin(); it != this->_vector.end(); ++it)
		std::cout << *it << std::endl;
}