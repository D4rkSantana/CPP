/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/15 03:14:44 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
		std::vector<int>	_vector;
		bool				_isOrdered;
		bool				_odd;
		int					_burr;
		void	parse_odd(void);
		std::deque<int> sorted(std::deque<std::vector<int> > raw);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& temp);
        PmergeMe& operator=(const PmergeMe& temp);
        ~PmergeMe();

		void	addNumber(std::string number);
		std::deque<int>	goSort(void);
};

std::ostream&   operator<<( std::ostream &out, const PmergeMe &ref);
void	printPairs(std::deque<std::vector<int> > vec);
void	printVector(std::vector<int> vec);
void	printDeque(std::deque<int> vec);
int		jacobsthal(int n);
std::vector<int>	creatInsertOrder(size_t size);
std::deque<int> createJacobsthalSequence(size_t n);
size_t searchPos(std::deque<int> main, int value);
std::deque<std::vector<int> > splitPairs(std::vector<int> raw);
std::deque<std::vector<int> > externSortPairs(std::deque<std::vector<int> > raw);


#endif /*PmergeMe_HPP*/