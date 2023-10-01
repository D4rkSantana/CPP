/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 03:18:34 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/01 03:44:05 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

		MutantStack<T>(void) {};

		~MutantStack<T>(void) {};

		MutantStack<T>(MutantStack const &copy) 
		{
			*this = copy;
		};
		MutantStack<T>& operator=(MutantStack const &copy) 
		{
			*this = copy;
			return (*this);
		};
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		
		iterator begin() {
        	return std::stack<T>::c.begin();
    	}

    	iterator end() {
        	return std::stack<T>::c.end();
    	}
	private:
};

#endif /*MUTANTSTACK_HPP*/