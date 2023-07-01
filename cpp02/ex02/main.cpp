/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/01 15:43:51 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    //std::cout << ++a << std::endl;
    //std::cout << a << std::endl;
    //std::cout << a++ << std::endl;
    //std::cout << a << std::endl;

    std::cout << b << std::endl;

    // std::cout << Fixed::max( a, b ) << std::endl;
        
    return 0;
}
