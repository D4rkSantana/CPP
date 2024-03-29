/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/29 00:25:58 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cfloat> //limits for float and double;
#include <climits> //limits for int;
#include <cmath> //floor
#include <cctype> //tolower, isdigit, isprint
#include <iomanip> //setprecision

class ScalarConverter
{
    private:

    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& temp);
        ScalarConverter& operator=(const ScalarConverter& temp);
        ~ScalarConverter();

		static void convert(const std::string &literal);
};

std::ostream&   operator<<( std::ostream &out, const ScalarConverter &ref);

char            checkType(const std::string &literal);
void            convertOrigin(char key, const std::string &literal);

#endif /*ScalarConverter_HPP*/