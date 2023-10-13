/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/29 00:25:47 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	return ;
}

RPN::~RPN(void)
{
	return ;
}

RPN::RPN(RPN const& copy)
{
	*this = copy;
}

RPN& RPN::operator=(RPN const & src)
{
	if (this != &src){
		this->_input = src._input;
		this->_stack = src._stack;
	}
	return (*this);
}

int	RPN::calcule(std::string input)
{
	int result;
	
	checkInput(input);
	result = getResult(input);

	return (result);
}

// throw std::runtime_error("Error: invalid expression.");

// Função faz a verificação dos inputs e grava na stack

void	RPN::checkInput(std::string input){

	size_t	index;
	size_t	size = input.size();
	char	c;
	int 	qt_digits = 0;
	int 	qt_tokens = 0;

	for (index = 0; index < size; index++)
	{
		c = input[index];
		if (c >= '0' && c <= '9')
			qt_digits++;
		else if (c == '-' || c == '+' || c == '*' || c == '/')
			qt_tokens++;
		else if (c == ' ')
			continue ;
		else
			throw std::runtime_error("Error: invalid input.");
	}
	if (qt_digits != qt_tokens + 1)
		throw std::runtime_error("Error: invalid input.");
}

int	RPN::getResult(std::string input)
{
	std::cout << input << " result\n";
	return (0);
}