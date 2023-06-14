/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/06/13 21:18:29 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->number = 0;
}

Fixed::Fixed(const Fixed& temp)
{
    this->number = * new int[1];
    this->number = temp.number;
}

Fixed &Fixed::operator=(const Fixed &temp)
{
    // TODO: insert return statement here
}

Fixed::~Fixed()
{
    delete &number;
}

int Fixed::getRawBits(void) const
{

}

void Fixed::setRawBits(int const raw)
{

}