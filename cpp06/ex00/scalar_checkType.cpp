/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_checkType.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:03:08 by esilva-s          #+#    #+#             */
/*   Updated: 2023/09/23 11:12:56 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static std::string	string_tolower(std::string input)
{
	unsigned long	index;
	std::string		result;

	index = 0;
	while (index < input.size())
	{
        if (input[index] > 64 && input[index] < 91)
		    result.push_back(std::tolower(input[index]));
        else
            result.push_back(input[index]);
		index++;
	}
	return (result);
}

static bool checkPseudo(const std::string &literal)
{
    std::string temp;
    char signal = '0';

    temp = string_tolower(literal);

    if (temp[0] == '-' || temp[0] == '+')
    {
        signal = temp[0];
        temp.erase(0, 1);
    }

    if (!temp.compare("inf") || !temp.compare("nan"))
    {
        if (signal != '0')
            temp = signal + temp;
        std::cout << "char:   impossible\nint:    impossible\n";
        std::cout << "float:  " << temp << "f\n";
        std::cout << "double: "<< temp << std::endl;
        return (true);
    }
    else if (!temp.compare("inff") || !temp.compare("nanf"))
    {
        if (signal != '0')
            temp = signal + temp;
        std::cout << "char:   impossible\nint:    impossible\n";
        std::cout << "float:  " << temp << std::endl;
        temp.erase(temp.size() - 1);
        std::cout << "double: "<< temp << std::endl;
        return (true);
    }
    return (false);
}

static bool checkChar(const std::string &literal)
{
    if (literal.size() == 1 && !(literal[0] > 47 && literal[0] < 58))
        return (true);
    return (false);
}

static bool checkInt(const std::string &literal)
{
    size_t index = 0;

    if (literal[0] == '-' || literal[0] == '+')
        index++;
        
    while (index < literal.size())
    {
        if (std::isdigit(literal[index]) == 0)
            return (false);
        index++;
    }
    return (true);
}

static bool checkFloat(const std::string &literal)
{
    size_t  index = 0;
    bool    sulf_f = false;
    bool    point = false;

    if (literal[0] == '-' || literal[0] == '+')
        index++;
    while (index < literal.size())
    {
        if (std::isdigit(literal[index]) == 0 && literal[index] == '.')
        {
            if (!point && index + 1 < literal.size())
            {
                if (std::isdigit(literal[index + 1] == 0))
                    return (false);
                point = true;
            }
            else
                return (false);
        }
        else if (std::isdigit(literal[index]) == 0 && literal[index] == 'f')
        {
            if (!sulf_f)
                sulf_f = true;
            else
                return (false);
        }
        else if (std::isdigit(literal[index]) == 0)
            return (false);
        index++;
    }
    if (point && sulf_f)
        return (true);
    return (false);
}

static bool checkDouble(const std::string &literal)
{
    size_t  index = 0;
    bool    comma = false;

    if (literal[0] == '-' || literal[0] == '+')
        index++;
    while (index < literal.size())
    {
        if (std::isdigit(literal[index]) == 0 && literal[index] == ',')
        {
            if (!comma && index + 1 < literal.size())
            {
                if (std::isdigit(literal[index + 1] == 0))
                    return (false);
                comma = true;
            }
            else
                return (false);
        }
        else if (std::isdigit(literal[index]) == 0)
            return (false);
        index++;
    }
    if (comma)
        return (true);
    return (false);
}

char checkType(const std::string &literal)
{
    if (checkPseudo(literal))
        return ('p');
    else if (checkChar(literal))
        return ('c');
    else if (checkInt(literal))
        return ('i');
    else if (checkFloat(literal))
        return ('f');
    else if (checkDouble(literal))
        return ('d');
    return ('e');
}
