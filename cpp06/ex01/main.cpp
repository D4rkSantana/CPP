/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/09/24 20:14:27 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    t_data data;

    data.name = "jorginho";
    
    uintptr_t add = Serializer::serialize(&data);

    t_data *result = Serializer::deserialize(add);

    std::cout << &data << std::endl;
    std::cout << add << std::endl;
    std::cout << result << std::endl;

    return (0);
}
