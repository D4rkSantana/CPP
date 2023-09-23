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

bool checkInt(const std::string &literal)
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

bool checkFloat(const std::string &literal)
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

bool checkDouble(const std::string &literal)
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

//========================= print functions =========================//

void    convertOriginChar(const std::string &literal)
{
    char outChar = static_cast<char>(literal[0]);
    int outInt = static_cast<int>(outChar);
    float outFloat = static_cast<float>(outChar);
    double outDouble = static_cast<double>(outChar);

    std::cout << "char:   \'" << outChar << "\'" << std::endl;
    std::cout << "int:    " << outInt << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float:  " << outFloat << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << outDouble << std::endl;
}

bool    convertOriginInt(const std::string &literal)
{
    int         outInt;
    char        outChar;
    float       outFloat;
    double      outDouble;
    long long   convert_aux;

    //testa o limite do tipo
    convert_aux = std::atoll(literal.c_str());
    if (convert_aux > INT_MAX || convert_aux < INT_MIN)
    {
        std::cout << "the integer type number is out of range\n";
        return (false);
    }
    //converte de string para o tipo de origem
    outInt = static_cast<int>(std::atoi(literal.c_str()));
    //converte de int para char
    if (outInt >= 32 && outInt <= 126)
    {
        outChar = static_cast<char>(outInt);
        std::cout << "char:   \'" << outChar << "\'" << std::endl;
    }
    else
        std::cout << "char:   Non displayable" << std::endl;
    //exibe o valor do int
    std::cout << "int:    " << outInt << std::endl;
    //converte de int para float
    if (outInt >= -FLT_MAX && outInt <= FLT_MAX)
    {
        outFloat = static_cast<float>(outInt);
        std::cout << std::fixed << std::setprecision(1) << "float:  " << outFloat << "f\n";
    }
    else
        std::cout << "float:  " << "the range has been exceeded\n";
    //converte de int para double
    if (outInt <= DBL_MAX && outInt >= -DBL_MAX)
    {
        outDouble = static_cast<double>(outInt);
        std::cout << std::fixed << std::setprecision(1) << "double: " << outDouble << std::endl;
    }
    else
        std::cout << "double: " << "the range has been exceeded\n";
    return (true);
}

bool    convertOriginFloat(const std::string &literal)
{
    int         outInt;
    char        outChar;
    float       outFloat;
    double      outDouble;
    long double convert_aux;

    //testa o limite do tipo
    convert_aux = std::strtold(literal.c_str(), NULL);
    if (convert_aux < -FLT_MAX || convert_aux > FLT_MAX)
    {
        std::cout << "the float type number is out of range\n";
        return (false);
    }

    //converte de string para o tipo de origem
    outFloat = static_cast<float>(std::atof(literal.c_str()));

    //converte de int para char
    if (outFloat >= 32.0 && outFloat <= 126.0)
    {
        outChar = static_cast<char>(outFloat);
        std::cout << "char:   \'" << outChar << "\'" << std::endl;
    }
    else
        std::cout << "char:   Non displayable" << std::endl;

    //converte de float para int
    if (outFloat <= INT_MAX && outFloat >= INT_MIN)
    {
        outInt = static_cast<int>(outFloat);
        std::cout << "int:    " << outInt << std::endl;
    }
    else
        std::cout << "int:    " << "the range has been exceeded\n";

    //exibe o valor do float
    std::cout << std::fixed << std::setprecision(1) << "float:  " << outFloat << "f\n";

    //converte de float para double
    outDouble = static_cast<double>(outFloat);
    std::cout << std::fixed << std::setprecision(1) << "double: " << outDouble << std::endl;

    return (true);
}

bool    convertOriginDouble(const std::string &literal)
{
    int         outInt;
    char        outChar;
    float       outFloat;
    double      outDouble;
    long double convert_aux;

    //testa o limite do tipo
    convert_aux = std::strtold(literal.c_str(), NULL);
    if (convert_aux < -DBL_MAX || convert_aux > DBL_MAX)
    {
        std::cout << "the double type number is out of range\n";
        return (false);
    }

    //converte de string para o tipo de origem
    outDouble = static_cast<double>(std::strtod(literal.c_str(), NULL));

    //converte de double para char
    if (outDouble >= 32.0 && outDouble <= 126.0)
    {
        outChar = static_cast<char>(outDouble);
        std::cout << "char:   \'" << outChar << "\'" << std::endl;
    }
    else
        std::cout << "char:   Non displayable" << std::endl;

    //converte de double para int
    if (outDouble <= INT_MAX && outDouble >= INT_MIN)
    {
        outInt = static_cast<int>(outDouble);
        std::cout << "int:    " << outInt << std::endl;
    }
    else
        std::cout << "int:    " << "the range has been exceeded\n";

    //convert de double para float
    if (outDouble >= -FLT_MAX && outDouble <= FLT_MAX)
    {
        outFloat = static_cast<float>(outDouble);
        std::cout << std::fixed << std::setprecision(1) << "float:  " << outFloat << "f\n";
    }
    else
        std::cout << "float:  " << "the range has been exceeded\n";

    //exibe o double
    std::cout << std::fixed << std::setprecision(1) << "double: " << outDouble << std::endl;

    return (true);
}

bool    convertOriginNumeric(const std::string &literal)
{
    char outChar;
    int outInt = 0;
    float outFloat = 0;
    double outDouble = 0;

    char *endPtr;
    long double ld_aux = std::strtold(literal.c_str(), &endPtr);
    if (*endPtr != '\0')
        return (false);
    ld_aux = std::floor(ld_aux * 100.0) / 100.0; 
    std::cout << ld_aux << std::endl;

    if (ld_aux >= 32.0 && ld_aux <= 126.0)
    {
        outChar = static_cast<char>(ld_aux);
        std::cout << "char:   \'" << outChar << "\'" << std::endl;
    }
    else
        std::cout << "char:   Non displayable" << std::endl;

    if (ld_aux >= INT_MIN && ld_aux <= INT_MAX)
    {
        outInt = static_cast<int>(ld_aux);
        std::cout << "int:    " << outInt << std::endl;
    }
    else
        std::cout << "int:    " << "the range has been exceeded\n";

    if (ld_aux >= -FLT_MAX && ld_aux <= FLT_MAX)
    {
        long long test = static_cast<long long>(ld_aux);
        std::cout << "long long: " << test << std::endl;
        outFloat = static_cast<float>(test);
        std::cout << std::fixed << std::setprecision(1) << "float:  " << outFloat << "f\n";
    }
    else
        std::cout << "float:  " << "the range has been exceeded\n";

    if (ld_aux <= DBL_MAX && ld_aux >= -DBL_MAX)
    {
        outDouble = static_cast<double>(ld_aux);
        std::cout << std::fixed << std::setprecision(1) << "double: " << outDouble << std::endl;
    }
    else
        std::cout << "double: " << "the range has been exceeded\n";
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
        convertOriginChar(literal);
    else if (result == 'i')
    {
        if (!convertOriginInt(literal))
            std::cout << "An error occurred, please try again using an int, char, float or double literal\n";
    }
    else if (result == 'f')
    {
        if (!convertOriginFloat(literal))
            std::cout << "An error occurred, please try again using an int, char, float or double literal\n";
    }
    else if (result == 'd')
    {
        if (!convertOriginDouble(literal))
            std::cout << "An error occurred, please try again using an int, char, float or double literal\n";
    }
}

/*
u - unknow (não iniciado)
e - error
p - pseudo
c - char
i - int
f - float
d - double
*/