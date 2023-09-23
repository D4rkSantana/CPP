/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/29 00:25:58 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

struct Data {
    std::string name;
    std::string weapon;
    int         hp;
    int         lvl;
    int         atk;
    int         def;
};

class Serializer
{
    private:
    public:
        Serializer();
        Serializer(const Serializer& temp);
        Serializer& operator=(const Serializer& temp);
        ~Serializer();

        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};

std::ostream&   operator<<( std::ostream &out, const Serializer &ref)

#endif /*SERIALIZER_HPP*/