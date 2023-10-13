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
#include <fstream> //abrir e ler arquivo
#include <sstream> //separar numeros da data
#include <string>
#include <cstdlib>
#include <map> //conteiner map

typedef struct date_s
{
	int		year;
	int		month;
	int		day;

} date_t;

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(std::string inputFile);
		~BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const& copy);

		BitcoinExchange& operator=(BitcoinExchange const & src);
		
		void	goWork(void);

	private:
		std::string	_inputFile;
		std::string	_dataFile;
		std::map<std::string, double>	_dataBase;

		void	_initDataFile();
		void	_initInputFile();
		void	_calcBitcoin(std::string date, double value);
		double	_calcValue(std::string date, double value);
};

bool	checkDate(std::string rawDate);
bool	checkFile(std::string file);
int		dateToInt(std::string date);
#endif /*BITCOINEXCHANGE_HPP*/
