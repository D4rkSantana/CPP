/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/29 00:25:47 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer was created" << std::endl;
}

Serializer::Serializer(const Serializer& temp)
{
    *this = temp;
    std::cout << "Serializer was copied" << std::endl;
}

Serializer &Serializer::operator=(const Serializer& temp)
{
    std::cout << "Serializer has been assigned" << std::endl;
    return (*this);
}

Serializer::~Serializer()
{
    std::cout << "Serializer was destroyed" << std::endl;
}

std::ostream&   operator<<( std::ostream &out, const Serializer &ref)
{
	(void)ref;
    out << "Serializer ";
    return (out);
}

uintptr_t   Serializer::serialize(Data* ptr)
{

}

Data*       Serializer::deserialize(uintptr_t raw)
{
    
}