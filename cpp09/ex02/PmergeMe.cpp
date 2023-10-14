/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/14 22:40:46 by esilva-s         ###   ########.fr       */
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
	std::vector<int> raw = this->_vector;
	//verifica se é possivel ordenar
	if (raw.size() < 2)
	{
		this->_isOrdered = true;
		return ;
	}

	//Passo 1
	//Verifica se o vetor é impar, caso seja, retirar e salva o ultimo numero
	int burr;
	int is_odd = raw.size() % 2;
	
	if (is_odd)
	{
		burr = raw.back();
		raw.pop_back();
	}
	this->_vector.clear();
	this->_vector = raw;
	//Passo 2
	//separa o vetor principal em pares e guarda dentro de um array
	std::vector<int> temp;
	std::deque<std::vector<int> > pairs;
	
	//std::cout << "raw size: " << raw.size() << std::endl;
	for (size_t i = 0; i < raw.size(); i += 2)
	{
		temp.push_back(raw[i]);
		temp.push_back(raw[i+1]);
		pairs.push_back(temp);
		temp.clear();
	}
	//std::cout << "pairs size: " << pairs.size() << std::endl;
	std::cout << "antes da primeira ordenação\n";
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << "pair " << i << ": " << pairs[i][0] << " " << pairs[i][1] << std::endl;
	
	//passo 3
	//ordenar internamente os os pares, colocando o maior numero na esquerda
	int temp_int;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i][0] > pairs[i][1])
		{
			temp_int = pairs[i][1];
			pairs[i][1] = pairs[i][0];
			pairs[i][0] = temp_int;
		}
			
	}
	std::cout << "depois da primeira ordenação\n";
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << "pair " << i << ": " << pairs[i][0] << " " << pairs[i][1] << std::endl;
	
	//passo 4
	//cria 2 listas e ordena se baseando do no maior elemento do par para ordenar os pares
	std::deque<std::vector<int> > ord;
	std::deque<std::vector<int> >::iterator it;
	std::vector<int> element;
	ord.push_back(*pairs.begin());
	pairs.pop_front();
	
	while (!pairs.empty())
	{
		it = ord.begin();
		element = *pairs.begin();
		while (it != ord.end())
		{
			if (element[1] < it[0][1])
			{
				ord.insert(it, element);
				break ;
			}
			++it;
			if (it == ord.end())
			{
				ord.push_back(element);
				break ;
			}
		}
		pairs.pop_front();
	}
	
	std::cout << "depois da segunda ordenação\n";
	for (size_t i = 0; i < ord.size(); i++)
		std::cout << "pair " << i << ": " << ord[i][0] << " " << ord[i][1] << std::endl;

}

void	PmergeMe::printNumbers(void)
{
	std::vector<int>::iterator it;

	it = this->_vector.begin();
	std::cout << std::endl << "=== vector ===" << std::endl;
	for (it = this->_vector.begin(); it != this->_vector.end(); ++it)
		std::cout << *it << " ";
	std::cout  << std::endl << "==============" << std::endl;
}