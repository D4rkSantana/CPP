/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/29 00:25:47 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int size)
{
	this->_size = size;
	this->_used = 0;
    //std::cout << "Span was created" << std::endl;
}

Span::Span(const Span& temp)
{
    *this = temp;
    //std::cout << "Span was copied" << std::endl;
}

Span &Span::operator=(const Span& temp)
{
	unsigned int index = 0;

	this->_size = temp.getSize();
	this->_used = temp.getUsed();
	if (!this->_data.empty())
		this->_data.clear();
	while (index < this->_used)
	{
		this->_data.push_back(temp.getElement(index));
		index++;
	}
    //std::cout << "Span has been assigned" << std::endl;
    return (*this);
}

int &Span::operator[](unsigned int index)
{
	if (index >= this->_used)
		throw Span::IndexOutOfLimitException();
    else
		return (this->_data[index]);
}

Span::~Span()
{
    //std::cout << "Span was destroyed" << std::endl;
}

std::ostream&   operator<<( std::ostream &out, const Span &ref)
{
    out << "Span have " << ref.getSize() << "of limited and " << ref.getUsed() << " elements" ;
    return (out);
}

unsigned int	Span::getSize(void) const
{
	return (this->_size);
}

unsigned int	Span::getUsed(void) const
{
	return (this->_used);
}

int	Span::getElement(unsigned int index) const
{
	int result;
	std::vector<int> temp = this->_data;

	if (index >= this->_size)
		throw Span::IndexOutOfLimitException();
	result = temp[index];
	return (result);
}

void			Span::addNumber(int number)
{
	if (this->_used >= this->_size)
		throw Span::LimitReachedtException();
	this->_data.push_back(number);
	this->_used = this->_used + 1;
}

void printVector(int nb)
{
	std::cout << nb << "\n";
}

unsigned int	Span::shortestSpan(void) const
{
	std::vector<int>::iterator it;

	std::vector<int> temp = this->_data;
	std::vector<int> output(temp.size());
	
	if (this->_used < 2)
		throw Span::InsufficientElementsException();
	std::sort(temp.begin(), temp.end());
	std::adjacent_difference(temp.begin(), temp.end(), output.begin());
	output.erase(output.begin());
	it = std::min_element(output.begin(), output.end());
	return (*it);
}

unsigned int	Span::longestSpan(void) const
{
	int min = 0;
	int max = 0;
	std::vector<int>::iterator it;

	if (this->_used < 2)
		throw Span::InsufficientElementsException();

	std::vector<int> temp = this->_data;

	it = std::min_element(temp.begin(), temp.end());
	min = *it;
	it = std::max_element(temp.begin(), temp.end());
	max = *it;
	
	return (max - min);
}

bool	Span::insertAll(int number)
{
	unsigned int	index = 0;

	if (this->_size == 0)
		return (false);
	while (index < this->_used)
	{
		this->_data[index] = number;
		index++;
	}
	while (index < this->_size)
	{
		this->_data.push_back(number);
		this->_used++;
		index++;
	}
	return (true);
}

bool	Span::insertIncrementAll(int number)
{
	unsigned int	index = 0;

	if (this->_size == 0)
		return (false);
	if ((number + static_cast<int>(this->_size)) > INT_MAX)
		return (false);

	while (index < this->_used)
	{
		this->_data[index] = number + static_cast<int>(index);
		index++;
	}
	while (index < this->_size)
	{
		this->_data.push_back(number + static_cast<int>(index));
		this->_used++;
		index++;
	}
	return (true);
}

bool	Span::insertInRange(unsigned int begin, unsigned int end, int number)
{
	unsigned int	index;

	if (this->_size == 0)
		return (false);
	if (begin >= this->_size || end >= this->_size ||begin >= end )
		return (false);

	if (end >= this->_used)
	{
		index = this->_used -1;
		while (index <= end)
		{
			this->_data.push_back(int());
			index++;
			this->_used++;
		}
	}
	index = begin;
	while (index <= end)
	{
		this->_data[index] = number;
		index++;
	}
	return (true);
}