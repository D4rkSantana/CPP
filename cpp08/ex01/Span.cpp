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
    std::cout << "Span was created" << std::endl;
}

Span::Span(const Span& temp)
{
    *this = temp;
    std::cout << "Span was copied" << std::endl;
}

Span &Span::operator=(const Span& temp)
{
	unsigned int index = 0;

	this->_size = temp.getSize();
	this->_used = temp.getUsed();
	if (!this->_data.empty())
		this->_data.clean();
	while (index < this->_used)
	{
		this->_data.push_back(temp[index]);
		index++;
	}
    std::cout << "Span has been assigned" << std::endl;
    return (*this);
}

int &Span::operator[](unsigned int index) const
{
	if (index >= this->_size)
        throw Span::IndexOutOfLimitException();
    else
		return (this->_data[index]);
}

Span::~Span()
{
    std::cout << "Span was destroyed" << std::endl;
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

unsigned int	Span::getSize(void) const
{
	return (this->_used);
}

unsigned int	getElement(unsigned int index) const
{
	if (index >= this->_size)
		
}

void			Span::addNumber(int number)
{
	if (this->_used >= this->_size)
		throw std::LimitReachedtException();
	this->_data.pop_back(number);
	this->_used = this->_used + 1;
}

unsigned int	Span::shortSpan(void) const
{
	int min1;
	int min2;
	std::vector<int>::iterator it;

	if (this->_used < 2)
		throw std::InsufficientElementsException();

	std::vector<int> temp = this->_data;

	it = std::min_element(temp.begin(), temp.end());
	min1 = *it;
	temp.erase(it);

	it = std::min_element(temp.begin(), temp.end());
	min2 = *it;
	
	return (min2 - min1)
}

unsigned int	Span::LongSpan(void) const
{

}