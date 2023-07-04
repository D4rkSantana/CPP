/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:18:45 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/04 17:09:06 by esilva-s         ###   ########.fr       */
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

int replace(std::string arguments[3])
{
	std::string	content;
    std::string result;
    
    content = read_file(arguments[0]);
    if (content.find(arguments[1]) == std::string::npos)
    {
        std::cout << "The string: \"" << arguments[1] << "\" not found in file \"";
        std::cout << arguments[0] << "\"" << std::endl;
        return (1);
    }
    if (content == "")
	{
		std::cout << "File empyt" << std::endl;
		return (1);
	}
    result = replace_content(content, arguments[1], arguments[2]);
    create_file(arguments[0], result);
    return (0);
}

std::string replace_content(std::string str, std::string s1, std::string s2)
{
	std::string result;
    size_t      pos = 0;
    size_t      temp = 0;

    if (s1 == s2)
        return (str);
        
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

void    create_file(std::string file, std::string content)
{
    file.append(".replace");
    std::ofstream   NewFile(file.c_str());

    NewFile << content;
    NewFile.close();
}