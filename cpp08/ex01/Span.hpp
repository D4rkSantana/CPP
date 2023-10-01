/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/29 00:25:58 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <climits> //limits for int;
#include <vector> //para o std::vector
#include <numeric> // para o std::adjacent_difference()
#include <algorithm> // para std::sort(), std::min_element() e std::max_element()

class Span
{
    private:
		std::vector<int>	_data;
		unsigned int		_size;
		unsigned int		_used;
    public:
        Span(unsigned int size);
        Span(const Span& temp);
        Span& operator=(const Span& temp);
		int &operator[](unsigned int index);

        ~Span();

		unsigned int	getSize(void) const;
		unsigned int	getUsed(void) const;
		int				getElement(unsigned int index) const;
	
		void			addNumber(int number);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		// completa todo o vector com um numero
		bool			insertAll(int number);
		// insere um numero na posição 0 e incrementa +1 a cada posição
		bool			insertIncrementAll(int number);
		// insere um numero nas posisoes de um range especifico
		bool			insertInRange(unsigned int begin, unsigned int end, int number);

		class IndexOutOfLimitException : public std::exception
		{
			virtual const char * what() const throw(){ 
				return ("Index out of limit");
			}
		};

		class LimitReachedtException : public std::exception
		{
			virtual const char * what() const throw(){ 
				return ("It is not possible to add the number, the limit has been reached");
			}
		};

		class InsufficientElementsException : public std::exception
		{
			virtual const char * what() const throw(){
				return ("There are not enough elements to complete the action");
			}
		};
};

std::ostream&   operator<<( std::ostream &out, const Span &ref);

#endif /*SPAN_HPP*/