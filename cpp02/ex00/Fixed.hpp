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

class Fixed
{
    private:
        int raw;
        static const int fract = 8;
    public:
        //construtores
        Fixed();
        Fixed(const Fixed& temp);
        //destrutor
        ~Fixed();
        //atribuição
        Fixed& operator=(const Fixed& temp);

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif /*FIXED_HPP*/