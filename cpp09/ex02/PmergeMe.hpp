/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/14 23:39:14 by esilva-s         ###   ########.fr       */
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
		std::deque<int>		_deque;
		bool				_odd;
		int					_burr;
		void				parseOddV(void);
		void				parseOddD(void);
		std::vector<int> 	sortedV(std::vector<std::vector<int> > raw);
		std::deque<int> 	sortedD(std::deque<std::deque<int> > raw);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& temp);
        PmergeMe& operator=(const PmergeMe& temp);
        ~PmergeMe();

		void				addNumber(std::string number);
		std::vector<int>	goSortV(void);
		std::deque<int>		goSortD(void);
};

std::ostream&   operator<<( std::ostream &out, const PmergeMe &ref);

void							printVector(std::vector<int> vec);
void							printDeque(std::deque<int> vec);
int								jacobsthal(int n);

std::vector<std::vector<int> >	splitPairsV(std::vector<int> raw);
std::deque<std::deque<int> >	splitPairsD(std::deque<int> raw);

std::vector<std::vector<int> >	externSortPairsV(std::vector<std::vector<int> > raw);
std::deque<std::deque<int> >	externSortPairsD(std::deque<std::deque<int> > raw);

std::vector<int>				creatInsertOrderV(size_t size);
std::deque<int>					creatInsertOrderD(size_t size);

std::vector<int>				createJacobsthalSequenceV(size_t n);
std::deque<int>					createJacobsthalSequenceD(size_t n);

size_t							searchPosV(std::vector<int> main, int value);
size_t							searchPosD(std::deque<int> main, int value);





#endif /*PmergeMe_HPP*/