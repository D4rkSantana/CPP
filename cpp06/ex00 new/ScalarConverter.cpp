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

static std::string	string_tolower(std::string input)
{
	unsigned long	index;
	int				size;
	std::string		result;

	index = 0;
	size = input.size();
	while (index < input.size())
	{
        if (input[index] > 64 && input[index] < 91)
		    result.push_back(tolower(input[index]));
        else
            result.push_back(input[index]);
		index++;
	}
	return (result);
}

static bool checkOthers(const std::string &literal)
{
    std::string temp;

    temp = string_tolower(literal);

    if (!literal.compare("nan"))
    {
        std::cout << "char: impossible\nint: impossible\n";
        std::cout << "float: nanf\ndouble: nan\n";
    }
    else if (!literal.compare("inf"))
    {
        std::cout << "char: impossible\nint: inf\n";
        std::cout << "float: inff\ndouble: inf\n";
    }
    else if (!literal.compare("-nan"))
    {
        std::cout << "char: impossible\nint: impossible\n";
        std::cout << "float: -nanf\ndouble: -nan\n";
    }
    else if (!literal.compare("-inf"))
    {
        std::cout << "char: impossible\nint: -inf\n";
        std::cout << "float: -inff\ndouble: -inf\n";
    }
    else
        return (false);
    return (true);
}

static void identificType(const std::string &literal)
{
    if (literal.size == 1 && !(literal[0] > 47 && literal[0] < 58))
        this->_isChar == true;
    else if ()
}

static void printChar(const std::string &literal)
{
    if (this->_isChar)
        std::cout << "char: \'" << literal << "\'" << std::endl;
    else if (this->_isInt)
    {
        int temp_int = static_cast<int>(atoi(literal));
    }
    else if (this->_isFloat)
    {

    }
    else if (this->_isDouble)
    {
        
    }
    else
        std::cout << "Error" << std::endl;
}

static void printInt(const std::string &literal)
{
}

static void printFloat(const std::string &literal)
{
}

static void printDouble(const std::string &literal)
{
}
//========================= check =====================//
bool checkPseudo(const std::string &literal)
{

}

bool checkChar(const std::string &literal)
{

}

bool checkNumeric(const std::string &literal)
{

}

char    checkType(const std::string &literal)
{
    if (checkPseudo(const std::string &literal))
        return ('p');
    else if (checkChar(const std::string &literal))
        return ('c');
    else if (checkNumeric(const std::string &literal))
        return ('n');
    return ('e');
}

void ScalarConverter::convert(const std::string &literal)
{
    char result;

    result = checkType(literal);
}

/*
e - error
p - pseudo
c - char
n - numeric
*/