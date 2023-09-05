/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/29 00:25:47 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter was created" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& temp)
{
    *this = temp;
    std::cout << "ScalarConverter was copied" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& temp)
{
	(void)temp;
    std::cout << "ScalarConverter has been assigned" << std::endl;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter was destroyed" << std::endl;
}

std::ostream&   operator<<( std::ostream &out, const ScalarConverter &ref)
{
	(void)ref;
    out << "ScalarConverter ";
    return (out);
}

void ScalarConverter::convert(const std::string &literal)
{
	std::cout << "Literal recebido: " << literal << std::endl;
}