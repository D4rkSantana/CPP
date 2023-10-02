/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/29 00:25:58 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>

typedef struct date_s
{
	int year;
	int mouth;
	int day;

} date_t;

class BitcoinExchange
{
    private:
		std::map<std::string, float> _data;
		std::map<std::string, float> _input;
		bool	_loadData(std::string data);
		bool	_openFile(std::string name);
		bool	_saveLine(std::string line);
    public:
        BitcoinExchange();
		BitcoinExchange(std::string data_name);
        BitcoinExchange(const BitcoinExchange& temp);
        BitcoinExchange& operator=(const BitcoinExchange& temp);
        ~BitcoinExchange();
};

std::ostream&   operator<<( std::ostream &out, const BitcoinExchange &ref);

#endif /*BITCOINEXCHANGE_HPP*/