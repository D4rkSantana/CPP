/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_convertOrigin.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:05:12 by esilva-s          #+#    #+#             */
/*   Updated: 2023/09/23 11:12:55 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void    convertOriginChar(const std::string &literal)
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

static bool    convertOriginInt(const std::string &literal)
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

static bool    convertOriginFloat(const std::string &literal)
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

static bool    convertOriginDouble(const std::string &literal)
{
    int         outInt;
    char        outChar;
    float       outFloat;
    double      outDouble;
    long double convert_aux;

    //substitui a ',' por '.'
    std::string temp = literal;
    temp[temp.find(',')] = '.';

    //testa o limite do tipo
    convert_aux = std::strtold(temp.c_str(), NULL);
    if (convert_aux < -DBL_MAX || convert_aux > DBL_MAX)
    {
        std::cout << "the double type number is out of range\n";
        return (false);
    }

    //converte de string para o tipo de origem
    outDouble = static_cast<double>(std::strtod(temp.c_str(), NULL));
    std::cout << outDouble << std::endl;
    
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

void    convertOrigin(char key, const std::string &literal)
{
    if (key == 'c')
        convertOriginChar(literal);
    else if (key == 'i')
    {
        if (!convertOriginInt(literal))
            std::cout << "An error occurred, please try again using an int, char, float or double literal\n";
    }
    else if (key == 'f')
    {
        if (!convertOriginFloat(literal))
            std::cout << "An error occurred, please try again using an int, char, float or double literal\n";
    }
    else if (key == 'd')
    {
        if (!convertOriginDouble(literal))
            std::cout << "An error occurred, please try again using an int, char, float or double literal\n";
    }
}
