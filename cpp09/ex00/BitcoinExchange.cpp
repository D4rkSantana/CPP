/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/29 00:25:47 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	this->_data = std::string();
    std::cout << "BitcoinExchange was created" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string data)
{
	this->_data = std::string();
	if (!this->_openFile(data))
		std::cout << "File Error\n";
    std::cout << "BitcoinExchange was created" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& temp)
{
    *this = temp;
    std::cout << "BitcoinExchange was copied" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& temp)
{
	(void)temp;
    std::cout << "BitcoinExchange has been assigned" << std::endl;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange was destroyed" << std::endl;
}

std::ostream&   operator<<( std::ostream &out, const BitcoinExchange &ref)
{
	(void)ref;
    out << "BitcoinExchange ";
    return (out);
}

// funções


void	BitcoinExchange::_convertDate(std::string date)
{
	int year, mouth, day;
	char aux;

	std::stringstream ss(date);
	ss >> year >> aux >> mouth >> aux >> day;
}

bool	BitcoinExchange::_saveLineData(std::string line)
{
	if (line.empty())
		return (false);
	
	return (true);

bool	BitcoinExchange::_loadData(std::string data)
{
	std::string line = std::string();

	std::ifstream file(data.c_str());
	if (!file.is_open())
		return (false);
	while (file >> line)
	{
		this->_data += line;
		if (!this->_saveLineData(line))
			return (false);
	}
	file.close();
	return (true);
}

bool	BitcoinExchange::_openFile(std::string name)
{
	std::string line = std::string();

	std::ifstream file(name.c_str());
	if (!file.is_open())
		return (false);
	while (file >> line)
	{
		this->_data += line;
	}
	file.close();
	return (true);
}