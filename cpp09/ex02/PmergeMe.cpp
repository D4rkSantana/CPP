/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/15 15:00:58 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	this->_sizeV = 0;
	this->_sizeD = 0;
	this->_odd = false;
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

int PmergeMe::getSizeV(void)
{
	return (this->_sizeV);
}


int PmergeMe::getSizeD(void)
{
	return (this->_sizeD);
}

// Add Numbers 

void	PmergeMe::addNumberV(std::string input)
{
	long long temp;

	for (size_t index = 0; index < input.size(); index++)
	{
		if (input[index] >= '0' && input[index] <= '9')
			continue ; 		
		else if ((input[index] == '+' || input[index] == ' ') && index == 0)
			continue ;
		else
			throw std::runtime_error("Error: Invalid character in input.");
	}
	temp = std::atoll(input.c_str());
	if (temp > INT_MAX || temp < INT_MIN)
		throw std::runtime_error("Error: number out range of int.");
	this->_vector.push_back(std::atoi(input.c_str()));
	this->_sizeV++;
}

void	PmergeMe::addNumberD(std::string input)
{
	long long temp;
	for (size_t index = 0; index < input.size(); index++)
	{
		if (input[index] >= '0' && input[index] <= '9')
			continue ; 		
		else if ((input[index] == '+' || input[index] == ' ') && index == 0)
			continue ;
		else
			throw std::runtime_error("Error: Invalid character in input.");
	}
	temp = std::atoll(input.c_str());
	if (temp > INT_MAX || temp < INT_MIN)
		throw std::runtime_error("Error: number out range of int.");
	this->_deque.push_back(std::atoi(input.c_str()));
	this->_sizeD++;
}

//print raws

void	PmergeMe::printRawV(void)
{
	std::vector<int> temp = this->_vector;

	if (this->_odd)
		temp.push_back(this->_burr);
	printVector(temp);
}
void	PmergeMe::printRawD(void)
{
	std::deque<int> temp = this->_deque;

	if (this->_odd)
		temp.push_back(this->_burr);
	printDeque(temp);
}

//go sorts

std::vector<int>	PmergeMe::goSortV(void)
{
	std::vector<int> raw = this->_vector;
	std::vector<std::vector<int> > pairs;

	if (raw.size() < 2)
		return (raw);
	if (raw.size() == 2)
	{
		std::vector<int> small;
		if (raw[0] < raw[1])
		{
			small.push_back(raw[0]);
			small.push_back(raw[1]);
			return (small);
		}
		small.push_back(raw[1]);
		small.push_back(raw[0]);
		return (small);
	}
	parseOddV();

	pairs = splitPairsV(this->_vector);
	pairs = externSortPairsV(pairs);
	return(sortedV(pairs));
}

std::deque<int>	PmergeMe::goSortD(void)
{
	std::deque<int> raw = this->_deque;
	std::deque<std::deque<int> > pairs;

	if (raw.size() < 2)
		return (raw);
	if (raw.size() == 2)
	{
		std::deque<int> small;
		if (raw[0] < raw[1])
		{
			small.push_back(raw[0]);
			small.push_back(raw[1]);
			return (small);
		}
		small.push_back(raw[1]);
		small.push_back(raw[0]);
		return (small);
	}
	parseOddD();
	pairs = splitPairsD(this->_deque);
	pairs = externSortPairsD(pairs);
	return(sortedD(pairs));
}

//parde odd

void PmergeMe::parseOddV(void)
{
	int is_odd = this->_vector.size() % 2;

	this->_odd = false;
	if (!is_odd)
		return ;
	this->_burr = this->_vector.back();
	this->_odd = true;
	this->_vector.pop_back();
}

void PmergeMe::parseOddD(void)
{
	int is_odd = this->_deque.size() % 2;

	this->_odd = false;
	if (!is_odd)
		return ;
	this->_burr = this->_deque.back();
	this->_odd = true;
	this->_deque.pop_back();
}

//sorteds

std::vector<int> PmergeMe::sortedV(std::vector<std::vector<int> > raw)
{
	std::vector<int> main;
	std::vector<int> pend;
	std::vector<int>::iterator it;
	std::vector<int> insert_order;

	for (size_t i = 0; i < raw.size(); i++)
	{
		main.push_back(raw[i][0]);
		pend.push_back(raw[i][1]);
	}
	if (this->_odd)
		pend.push_back(this->_burr);

	main.insert(main.begin(), *pend.begin());
	
	insert_order = creatInsertOrderV(pend.size());
	for (size_t i = 0; i < insert_order.size(); i++)
	{
		int value = pend[insert_order[i]];
		size_t pos = searchPosV(main, value);
		if (pos == main.size())
			main.push_back(value);
		else
		{
			it = main.begin();
			std::advance(it, pos);
			main.insert(it, value);
		}
	}
	return (main);
}

std::deque<int> PmergeMe::sortedD(std::deque<std::deque<int> > raw)
{
	std::deque<int> main;
	std::deque<int> pend;
	std::deque<int>::iterator it;
	std::deque<int> insert_order;

	for (size_t i = 0; i < raw.size(); i++)
	{
		main.push_back(raw[i][0]);
		pend.push_back(raw[i][1]);
	}
	if (this->_odd)
		pend.push_back(this->_burr);

	main.push_front(*pend.begin());
	
	insert_order = creatInsertOrderD(pend.size());
	for (size_t i = 0; i < insert_order.size(); i++)
	{
		int value = pend[insert_order[i]];
		size_t pos = searchPosD(main, value);
		if (pos == main.size())
			main.push_back(value);
		else
		{
			it = main.begin();
			std::advance(it, pos);
			main.insert(it, value);
		}
	}
	return (main);
}

//splits pairs 

std::vector<std::vector<int> > splitPairsV(std::vector<int> raw)
{
	std::vector<int>				temp;
	std::vector<std::vector<int> >	pairs;

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

std::deque<std::deque<int> > splitPairsD(std::deque<int> raw)
{
	std::deque<int> temp;
	std::deque<std::deque<int> > pairs;

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

//externSortPairs

std::vector<std::vector<int> > externSortPairsV(std::vector<std::vector<int> > raw)
{
	std::vector<std::vector<int> > ord;
	std::vector<std::vector<int> > pairs = raw;
	std::vector<std::vector<int> >::iterator it;
	std::vector<int> element;

	ord.push_back(*pairs.begin());
	pairs.erase(pairs.begin());
	
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
		pairs.erase(pairs.begin());
	}
	return (ord);
}

std::deque<std::deque<int> > externSortPairsD(std::deque<std::deque<int> > raw)
{
	std::deque<std::deque<int> > ord;
	std::deque<std::deque<int> > pairs = raw;
	std::deque<std::deque<int> >::iterator it;
	std::deque<int> element;

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

//creatInsertOrders

std::vector<int>	creatInsertOrderV(size_t size)
{
	int j_count = 2;
	int i_count = 0;
	int jacobs = jacobsthal(j_count);
	std::vector<int> index;
	std::vector<int> result;

	for (size_t i = 0; i < size + 1; i++)
		index.push_back(i);
	index.erase(index.begin());

	result.push_back(jacobs);
	while (result.size() != size - 1)
	{
		if (jacobs <= index[i_count])
		{
			j_count++;
			jacobs = jacobsthal(j_count);
			if (jacobs < (int)size)
				result.push_back(jacobs);
		}
		else
			result.push_back(index[i_count]);
		i_count++;
	}
	return (result);
}

std::deque<int>	creatInsertOrderD(size_t size)
{
	int j_count = 2;
	int i_count = 0;
	int jacobs = jacobsthal(j_count);
	std::deque<int> index;
	std::deque<int> result;

	for (size_t i = 0; i < size + 1; i++)
		index.push_back(i);
	index.pop_front();

	result.push_back(jacobs);
	while (result.size() != size - 1)
	{
		if (jacobs <= index[i_count])
		{
			j_count++;
			jacobs = jacobsthal(j_count);
			if (jacobs < (int)size)
				result.push_back(jacobs);
		}
		else
			result.push_back(index[i_count]);
		i_count++;
	}
	return (result);
}

//creat jacobsthal sequences

std::vector<int> createJacobsthalSequenceV(size_t n)
{
    std::vector<int> result;

    for (size_t i = 0; i <= n; ++i) {
        result.push_back(jacobsthal(i));
    }
    return result;
}

std::deque<int> createJacobsthalSequenceD(size_t n)
{
    std::deque<int> result;

    for (size_t i = 0; i <= n; ++i) {
        result.push_back(jacobsthal(i));
    }
    return result;
}

//searchPos

size_t searchPosV(std::vector<int> main, int value)
{
	size_t i;

	for (i = 0; i < main.size(); i++)
	{
		if (main[i] > value)
			return (i);
	}
	return (main.size());
}

size_t searchPosD(std::deque<int> main, int value)
{
	size_t i;

	for (i = 0; i < main.size(); i++)
	{
		if (main[i] > value)
			return (i);
	}
	return (main.size());
}

//jacobsthal

int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

//prints

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


