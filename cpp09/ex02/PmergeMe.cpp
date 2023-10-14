/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/14 02:50:32 by esilva-s         ###   ########.fr       */
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
		if (input[index] >= '0' && input[index] <= '9')
			continue ; 		
		else if ((input[index] == '+' || input[index] == ' ') && index == 0)
			continue ;
		else
			throw std::runtime_error("Error: Invalid character in input.");
	}
	this->_vector.push_back(std::atoi(input.c_str()));
	this->_isOrdered = false;
}

void	PmergeMe::goSort(void)
{

	//verifica se é possivel ordenar
	if (this->_vector.size() < 2)
	{
		this->_isOrdered = true;
		return ;
	}

	//Passo 1
	//Verifica se o vetor é impar, caso seja, retirar e salva o ultimo numero
	int burr;
	int is_odd = this->_vector.size() % 2;
	
	if (is_odd)
	{
		std::cout << "é impar\n";
		burr = this->_vector.back();
		this->_vector.pop_back();
	}
	else
		std::cout << "é par\n";
}

void	PmergeMe::printNumbers(void)
{
	std::vector<int>::iterator it;

	it = this->_vector.begin();
	for (it = this->_vector.begin(); it != this->_vector.end(); ++it)
		std::cout << *it << std::endl;
}