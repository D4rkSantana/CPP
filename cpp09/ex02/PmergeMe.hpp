/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/10/14 02:21:08 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

class PmergeMe
{
    private:
		std::vector<int>	_vector;
		bool				_isOrdered;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& temp);
        PmergeMe& operator=(const PmergeMe& temp);
        ~PmergeMe();

		void	addNumber(std::string number);
		void	goSort(void);
		void	printNumbers(void);
};

std::ostream&   operator<<( std::ostream &out, const PmergeMe &ref);

#endif /*PmergeMe_HPP*/