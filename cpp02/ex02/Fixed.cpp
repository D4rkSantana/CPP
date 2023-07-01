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
    this->raw = 0;
}

Fixed::Fixed(const Fixed& temp)
{
    *this = temp;
}

Fixed::Fixed(const int number)
{
    this->raw = number << this->fract;
}

Fixed::Fixed(const float number)
{
    this->raw = roundf(number * (1 << this->fract));
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(Fixed const &temp)
{
    this->raw = temp.getRawBits();
    return (*this);
}

Fixed Fixed::operator+(const Fixed& temp)
{
    Fixed result;
    int raw_temp = 0;

    raw_temp = this->getRawBits() + temp.getRawBits();
    result.setRawBits(raw_temp);
    return (result);
}

Fixed Fixed::operator-(const Fixed& temp)
{
    Fixed result;
    int raw_temp = 0;

    raw_temp = this->getRawBits() - temp.getRawBits();
    result.setRawBits(raw_temp);
    return (result);
}

Fixed Fixed::operator*(const Fixed& temp)
{
    Fixed result;
    int raw_temp = 0;

    raw_temp = this->getRawBits() * temp.getRawBits();
    result.setRawBits(raw_temp);
    return (result);
}

Fixed Fixed::operator/(const Fixed& temp)
{
    Fixed result;
    int raw_temp = 0;

    raw_temp = this->getRawBits() / temp.getRawBits();
    result.setRawBits(raw_temp);
    return (result);
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