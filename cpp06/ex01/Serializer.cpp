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
    (void)temp;
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

uintptr_t   Serializer::serialize(t_data* ptr)
{
    uintptr_t result;
    if (ptr == NULL)
        return (0);

    result = reinterpret_cast<uintptr_t>(ptr);
    return (result);
}

t_data  *Serializer::deserialize(uintptr_t raw)
{
    t_data *result;

    if (raw == 0)
        return (NULL);

    result = reinterpret_cast<t_data *>(raw);
    return (result);
}