/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/09/28 23:18:20 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class NotFoundException : public std::exception
{
	virtual const char* what() const throw(){
		return ("Not Found !");
	};
};

template <typename Conteiner>
void easyfind(Conteiner &data, int element)
{
    if (std::find(data.begin(), data.end(), element) != data.end())
	{
		std::cout << "Found !" << std::endl;
		return ;
	}
	else
	{
		throw ::NotFoundException();
	}
		
}

#endif /*EASYFIND_HPP*/