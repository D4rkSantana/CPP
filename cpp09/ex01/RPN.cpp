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

RPN::RPN()
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

int		RPN::calcule(std::string input){
	int result;
	
	checkInput(input);
	result = getResult(input);

	return (result);
}

// throw std::runtime_error("Error: invalid expression.");

// Função faz a verificação dos inputs e grava na stack

void	RPN::_validateInput(std::string input){

	size_t	index;
	size_t	size = input.size();

	for (index = 0; index < size; index++)
	{
		if (checkElement(input[index]))
			throw std::runtime_error("Error: invalid expression.");
	}
}

void	RPN::_calculateRPN(char c){
}

void	RPN::_getResult(){

}