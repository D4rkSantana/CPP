/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/06/13 21:18:34 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <math.h>

class Fixed
{
    private:
        int raw;
        static const int fract = 8;
    public:
        Fixed();
        Fixed(const Fixed& temp);
        Fixed(const int number);
        Fixed(const float number);
        ~Fixed();
        Fixed& operator=(const Fixed& temp);
        //Metodos Min e Max
        static Fixed const &min(Fixed const &a, Fixed const &b);
        static Fixed const &max(Fixed const &a, Fixed const &b);
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        //Metodos
        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void) const;
        float toFloat(void) const;
        //Operadores aritmeticos
        Fixed operator+(const Fixed& temp) const;
        Fixed operator-(const Fixed& temp) const;
        Fixed operator*(const Fixed& temp) const;
        Fixed operator/(const Fixed& temp) const;
        //Operadores de comparação  Os 6 operadores de comparação: >, <, >=, <=, == e !=.
        bool operator>(const Fixed& temp) const;
        bool operator<(const Fixed& temp) const;
        bool operator>=(const Fixed& temp) const;
        bool operator<=(const Fixed& temp) const;
        bool operator==(const Fixed& temp) const;
        bool operator!=(const Fixed& temp) const;
        //Operadores incrimento/decremento
        Fixed &operator++(void);
        Fixed &operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif /*FIXED_HPP*/