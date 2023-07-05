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

//construtores
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

//destrutor
Fixed::~Fixed()
{
}

//Operador igualdade
Fixed &Fixed::operator=(Fixed const &temp)
{
    this->raw = temp.getRawBits();
    return (*this);
}

//Operadores aritmeticos
Fixed Fixed::operator+(const Fixed& temp)
{
    Fixed result(*this);

    result.setRawBits(this->getRawBits() + (long)temp.getRawBits());
    return (result);
}

Fixed Fixed::operator-(const Fixed& temp)
{
    Fixed result(*this);

    result.setRawBits(this->getRawBits() - temp.getRawBits());
    return (result);
}

Fixed Fixed::operator*(const Fixed& temp)
{
    Fixed result(*this);

    result.setRawBits(((long)this->getRawBits() * (long)temp.getRawBits()) / (1 << this->fract));
    return (result);
}

Fixed Fixed::operator/(const Fixed& temp)
{
    Fixed result(*this);

    result.setRawBits((long)this->getRawBits() * (1 << this->fract) / (long)temp.getRawBits());
    return (result);
}

//Operadores de comparação
bool Fixed::operator>(const Fixed& temp)
{
    bool    result;

    result = this->raw > temp.getRawBits();
    return (result);
}

bool Fixed::operator<(const Fixed& temp)
{
    bool    result;

    result = this->raw < temp.getRawBits();
    return (result);
}

bool Fixed::operator>=(const Fixed& temp)
{
    bool    result;

    result = this->raw >= temp.getRawBits();
    return (result);
}

bool Fixed::operator<=(const Fixed& temp)
{
    bool    result;

    result = this->raw <= temp.getRawBits();
    return (result);
}

bool Fixed::operator==(const Fixed& temp)
{
    bool    result;

    result = this->raw == temp.getRawBits();
    return (result);
}

bool Fixed::operator!=(const Fixed& temp)
{
    bool    result;

    result = this->raw != temp.getRawBits();
    return (result);
}

//Operadores incremento/decremento
Fixed &Fixed::operator++(void)
{
    this->raw++;
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    this->raw--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed   old = *this;

    this->operator++();
    return (old);
}

Fixed Fixed::operator--(int)
{
    Fixed   old = *this;

    this->operator--();
    return (old);
}

//Metodos
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
    return ((float)this->raw / (float)(1 << this->fract));
}

//
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

//Metodos Min e Max
Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
     if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}
