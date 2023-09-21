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

//========================= check type =========================//

bool checkPseudo(const std::string &literal)
{
    std::string temp;

    temp = string_tolower(literal);

    if (temp[0] == '-' || temp[0] == '+')
        temp.erase(0, 1);

    if (!temp.compare("inf") || !temp.compare("inff") || !temp.compare("nan"))
        return (true);
    return (false);
}

bool checkChar(const std::string &literal)
{
    if (literal.size() == 1 && !(literal[0] > 47 && literal[0] < 58))
        return (true);
    return (false);
}

bool checkNumeric(const std::string &literal)
{
    size_t index = 0;

    if (literal[0] == '-' || literal[0] == '+')
        index++;
        
    while (index < literal.size())
    {
        if (std::isdigit(literal[index]) == 0 && literal[index] != '.')
            return (false);
        index++;
    }
    return (true);
}

char    checkType(const std::string &literal)
{
    if (checkPseudo(literal))
        return ('p');
    else if (checkChar(literal))
        return ('c');
    else if (checkNumeric(literal))
        return ('n');
    return ('e');
}

//========================= print functions =========================//

void    printOriginChar(const std::string &literal)
{
    char outChar = static_cast<char>(literal[0]);
    int outInt = static_cast<int>(literal[0]);
    float outFloat = static_cast<float>(outInt);
    double outDouble = static_cast<double>(outInt);

    std::cout << "char: \'" << outChar << "\'" << std::endl;
    std::cout << "int: " << outInt << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << outFloat << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << outDouble << std::endl;
}

bool    printOriginNumeric(const std::string &literal)
{
    char outChar;
    //int outInt = static_cast<int>(std::atoi(literal.c_str()));
    //float outFloat = static_cast<float>(std::atof(literal.c_str()));

    char *return_strtod1;
    int outInt = static_cast<int>(std::strtod(literal.c_str(), &return_strtod1));
    char *return_strtod2;
    float outFloat = static_cast<float>(std::strtod(literal.c_str(), &return_strtod2));

    char *return_strtod;
    double outDouble = static_cast<double>(std::strtod(literal.c_str(), &return_strtod));
    if (*return_strtod != '\0')
        return (false);

    if (outInt > 31 && outInt < 127)
    {
        outChar = static_cast<char>(outInt);
        std::cout << "char: \'" << outChar << "\'" << std::endl;
    }
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << outInt << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << outFloat << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << outDouble << std::endl;
    return (true);
}
//========================= converter main =========================//

void ScalarConverter::convert(const std::string &literal)
{
    char result;

    result = checkType(literal);
    if (result == 'e')
        std::cout << "An error occurred, please try again using an int, char, float or double literal\n";
    else if (result == 'p')
    {
        std::cout << "char: impossible\n int: impossible\n";
        std::cout << "float: " << literal << "f\n";
        std::cout << "double: "<< literal << std::endl;
    }
    else if (result == 'c')
        printOriginChar(literal);
    else if (result == 'n')
    {
        if (!printOriginNumeric(literal))
            std::cout << "An error occurred, please try again using an int, char, float or double literal\n";
    }
}

/*
e - error
p - pseudo
c - char
n - numeric
*/