/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:18:45 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/23 21:30:41 by esilva-s         ###   ########.fr       */
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