/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/15 00:30:50 by esilva-s         ###   ########.fr       */
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
	parse_odd();

	std::cout << "===== Raw vector pos odd =====\n";
	printVector(this->_vector);
	std::cout << std::endl;

	//Passo 2
	//separa o vetor principal em pares e guarda dentro de um array
	//onde o primeiro elemento do par é o menor numero;

	std::deque<std::vector<int> > pairs;

	pairs = splitPairs(this->_vector);

	std::cout << " == criação dos pares == \n";
	printPairs(pairs);
	std::cout << std::endl;

	//passo 3
	//cria 2 listas e ordena se baseando do no maior elemento do par para ordenar os pares
	
	pairs = externSortPairs(pairs);
	
	std::cout << "depois da segunda ordenação\n";
	printPairs(pairs);
	std::cout << std::endl;

	//passo 4
	std::deque<int> result;
	result = sorted(pairs);

	std::cout << "depois da segunda ordenação\n";
	printDeque(result);
	std::cout << std::endl;
}

void PmergeMe::parse_odd(void)
{
	std::cout << "===== Raw vector pre odd =====\n";
	printVector(this->_vector);
	std::cout << std::endl;

	int is_odd = this->_vector.size() % 2;
	
	if (!is_odd)
		return ;
	this->_burr = this->_vector.back();
	this->_odd = true;
	this->_vector.pop_back();
}

std::deque<std::vector<int> > splitPairs(std::vector<int> raw)
{
	std::vector<int> temp;
	std::deque<std::vector<int> > pairs;

	for (size_t i = 0; i < raw.size(); i += 2)
	{
		if (raw[i] > raw[i+1])
		{
			temp.push_back(raw[i]);
			temp.push_back(raw[i+1]);
		}	
		else
		{
			temp.push_back(raw[i+1]);
			temp.push_back(raw[i]);
		}
		pairs.push_back(temp);
		temp.clear();
	}
	return (pairs);
}

std::deque<std::vector<int> > externSortPairs(std::deque<std::vector<int> > raw)
{
	std::deque<std::vector<int> > ord;
	std::deque<std::vector<int> > pairs = raw;
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
			if (element[0] < it[0][0])
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
	return (ord);
}

std::deque<int> PmergeMe::sorted(std::deque<std::vector<int> > raw)
{
	std::deque<int> main;
	std::deque<int> pend;

	for (size_t i = 0; i < raw.size(); i++)
	{
		main.push_back(raw[i][0]);
		pend.push_back(raw[i][1]);
	}
	if (this->_odd)
		pend.push_back(this->_burr);

	main.push_front(*pend.begin());
	pend.pop_front();

	return (main);
}

void	printPairs(std::deque<std::vector<int> > vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "pair " << i << ": " << vec[i][0] << " " << vec[i][1] << std::endl;
}

void	printVector(std::vector<int> vec)
{
	std::vector<int>::iterator it;

	it = vec.begin();

	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout  << std::endl;
}

void	printDeque(std::deque<int> vec)
{
	std::deque<int>::iterator it;

	it = vec.begin();

	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout  << std::endl;
}