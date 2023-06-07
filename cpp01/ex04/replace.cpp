/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s < esilva-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:18:45 by esilva-s          #+#    #+#             */
/*   Updated: 2023/06/07 12:51:25 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string	read_file(std::string file_name)
{
	std::ifstream	file(file_name.c_str());
	std::string		result;
	std::string		line;

	if (!file.is_open())
		return ("");

	while (!file.eof())
	{
		std::getline(file, line);
		result.append(line);
		result.push_back('\n');
	}
	result.erase(result.size() -1);
	file.close();
	return (result);
}

std::string replace(std::string content, std::string s1, std::string s2)
{
	std::string	result;
	size_t	pos = 0;
	size_t	pos_temp = 0;

	pos_temp = content.find(s1, pos);
	if ()
	while (){}
}

/*
// string::substr
#include <iostream>
#include <string>

int main ()
{
    std::string result;
    std::string str="We think in generalities, but we live in details.";
    std::string s1 = " ";
    std::string s2 = ".x.";
                                           // (quoting Alfred N. Whitehead)
    size_t  pos = 0;
    size_t  temp = 0;
    
    while (pos < str.size())
    {
        temp = str.find(s1, pos);
        if (temp == std::string::npos)
        {
            result.append(str.substr(pos, str.size()));
            break ;
        }
        else
        {
            result.append(str.substr(pos, temp));
            std::cout << result << "|" << "pos: " << pos << " temp: " << temp << std::endl;
            result.append(s2);
            std::cout << result << "|" << "pos: " << pos << " temp: " << temp << std::endl;
            pos = temp + s1.size();
            std::cout << "--- pos: " << pos << " temp: " << temp << std::endl;
        }
    }
    std::cout << "result: " << std::endl << result << std::endl;
  return 0;
}
*/