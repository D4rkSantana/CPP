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
    std::cout << "Default constructor called" << std::endl;
    this->raw = 0;
}

Fixed::Fixed(const Fixed& temp)
{
    std::cout << "Copy constructor called" << std::endl;
    this->raw = temp.getRawBits();
}

Fixed::Fixed(const int number)
{
    //std::cout << "Copy constructor called" << std::endl;

}

Fixed::Fixed(const float number)
{
    //std::cout << "Copy constructor called" << std::endl;

}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &temp)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->raw = temp.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->raw);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->raw = raw;
}

int Fixed::toInt(void) const
{
    return (0);
}

float Fixed::toFloat(void) const
{
    return (0);
}