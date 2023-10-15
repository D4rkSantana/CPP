/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/15 03:21:43 by esilva-s         ###   ########.fr       */
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

std::deque<int>	PmergeMe::goSort(void)
{
	std::vector<int> raw = this->_vector;
	std::deque<std::vector<int> > pairs;

	if (raw.size() < 2)
	{
		std::deque<int> small(raw.begin(), raw.end());
		this->_isOrdered = true;
		return (small);
	}
	parse_odd();

	pairs = splitPairs(this->_vector);
	pairs = externSortPairs(pairs);
	return(sorted(pairs));
}

void PmergeMe::parse_odd(void)
{
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
	std::deque<int>::iterator it;
	std::vector<int> insert_order;

	for (size_t i = 0; i < raw.size(); i++)
	{
		main.push_back(raw[i][0]);
		pend.push_back(raw[i][1]);
	}
	if (this->_odd)
		pend.push_back(this->_burr);

	main.push_front(*pend.begin());
	
	insert_order = creatInsertOrder(pend.size());
	for (size_t i = 0; i < insert_order.size(); i++)
	{
		int value = pend[insert_order[i]];
		size_t pos = searchPos(main, value);
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

size_t searchPos(std::deque<int> main, int value)
{
	size_t i;

	for (i = 0; i < main.size(); i++)
	{
		if (main[i] > value)
			return (i);
	}
	return (main.size());
}

std::vector<int>	creatInsertOrder(size_t size)
{
	int j_count = 0;
	int i_count = 0;
	std::deque<int> index;
	std::vector<int> result;
	std::deque<int> jacobs = createJacobsthalSequence(size);

	for (size_t i = 0; i < size + 1; i++)
		index.push_back(i);
	jacobs.pop_front();
	jacobs.pop_front();
	index.pop_front();

	result.push_back(jacobs[0]);
	while (result.size() != size - 1)
	{
		if (jacobs[j_count] <= index[i_count])
		{
			j_count++;
			if (jacobs[j_count] < (int)size)
				result.push_back(jacobs[j_count]);
		}
		else
			result.push_back(index[i_count]);
		i_count++;
	}
	return (result);
}

int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::deque<int> createJacobsthalSequence(size_t n)
{
    std::deque<int> result;

    for (size_t i = 0; i <= n; ++i) {
        result.push_back(jacobsthal(i));
    }
    return result;
}

void	printDeque(std::deque<int> vec)
{
	std::deque<int>::iterator it;

	it = vec.begin();

	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout  << std::endl;
}