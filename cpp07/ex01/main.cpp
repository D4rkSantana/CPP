/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/09/26 22:15:08 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void func1(std::string str)
{
    str.erase(1, 1);
    std::cout << str << std::endl;
    
}

int main()
{
    std::string  array[5];

    array[0] = "aaaa";
    array[1] = "bbbb";
    array[2] = "cccc";
    array[3] = "dddd";
    array[4] = "eeee";
    std::cout << "antes:\n" << *array << std::endl;

    iter(array, 5, func1);

    std::cout << "depois:\n" << *array << std::endl;

    return(0);
}
