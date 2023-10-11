/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/29 00:25:58 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN 
{
	public:
		RPN(void);
		RPN(std::string input);
		~RPN(void);
		RPN(RPN const& copy);

		RPN& operator=(RPN const & src);

		void	rpn();
	private:
		std::string		_input;
		std::stack<int> _stack;
		void	_validateInput();
		void	_calculateRPN(char c);
		void	_getResult();
};

bool	isTokens(char c);

#endif /*RPN_HPP*/