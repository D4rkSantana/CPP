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
    *this = temp;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    this->raw = number << this->fract;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->raw = roundf(number * (1 << this->fract));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &temp)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->raw = temp.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->raw);
}

void Fixed::setRawBits(int const raw)
{
    this->raw = raw;
}

int Fixed::toInt(void) const
{
    return (this->raw >> fract);
}

float Fixed::toFloat(void) const
{
    return ((float)this->raw / (float)(1 << fract));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}