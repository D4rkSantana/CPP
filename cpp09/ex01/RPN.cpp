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
	(void)src;
	return (*this);
}

int	RPN::calcule(std::string input)
{
	int result;
	
	checkInput(input);
	result = getResult(input);

	return (result);
}

// Função faz a verificação dos inputs

void	RPN::checkInput(std::string input)
{

	size_t	index;
	size_t	size = input.size();
	int 	qt_digits = 0;
	int 	qt_tokens = 0;

	for (index = 0; index < size; index++)
	{
		if (isDigit(input[index]))
			qt_digits++;
		else if (isToken(input[index]))
			qt_tokens++;
		else if (input[index] == ' ')
			continue ;
		else
			throw std::runtime_error("Error: Invalid character in input.");
	}
	if (qt_digits != qt_tokens + 1)
		throw std::runtime_error("Error: the total number of numbers must be the number of tokens + 1.");
}

int	RPN::getResult(std::string input)
{
	size_t	index;
	size_t	size = input.size();
	int		temp1, temp2;


	std::stack<int> stack;
	for (index = 0; index < size; index++)
	{
		if (isDigit(input[index]))
			stack.push(static_cast<int>(input[index] - '0'));
		else if (isToken(input[index]))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: It is necessary to have at least 2 numbers for a token to be applied.");
			temp2 = stack.top();
			stack.pop();
			temp1 = stack.top();
			stack.pop();
			stack.push(simpleCalc(temp1, temp2, input[index]));
		}
		else if (input[index] == ' ')
			continue ;
		else
			throw std::runtime_error("Error: Invalid character in input.");
	}
	if (stack.size() == 1)
		return (stack.top());
	else
		throw std::runtime_error("Error: calculation broke.");
	return (0);
}

bool	isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	isToken(char c)
{
	return (c == '-' || c == '+' || c == '*' || c == '/');
}

int	simpleCalc(int n1, int n2, char token)
{
	if (token == '+')
		return (n1 + n2);
	else if (token == '-')
		return (n1 - n2);
	else if (token == '*')
		return (n1 * n2);
	else if (token == '/')
	{
		if (n2 == 0)
			throw std::runtime_error("Error: Division by 0 is not accepted.");
		return (n1 / n2);
	}
	else
		throw std::runtime_error("Error: Invalid Token.");
	return (0);
}