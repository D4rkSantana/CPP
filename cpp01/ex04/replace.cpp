/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:18:45 by esilva-s          #+#    #+#             */
/*   Updated: 2023/06/07 22:32:17 by esilva-s         ###   ########.fr       */
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

std::string replace(std::string str, std::string s1, std::string s2)
{
	std::string result;
    size_t      pos = 0;
    size_t      temp = 0;

    while (pos < str.size())
    {
        temp = str.find(s1, pos);
        if (temp == std::string::npos)
        {
            result.append(str.substr(pos, str.size()));
            break ;
        }
        result.append(str.substr(pos, temp - pos));
        result.append(s2);
        pos = temp + s1.size();
    }
    return (result);
}
