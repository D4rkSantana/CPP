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

BitcoinExchange::BitcoinExchange(void) : _inputFile("input.txt"), _dataFile("data.csv")
{
	goWork();
}

BitcoinExchange::BitcoinExchange(std::string inputFile) : _inputFile(inputFile), _dataFile("data.csv")
{
	goWork();
}

BitcoinExchange::~BitcoinExchange(void){
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& copy){
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & src){
	if (this != &src){
		this->_inputFile = src._inputFile;
		this->_dataFile = src._dataFile;
	}
	return (*this);
}

//inicializador

void	BitcoinExchange::goWork(){
	_initDataFile();
	_initInputFile();
}

//verifica a integrigade dos arquivos

void checkOpen(const char *archive, char key)
{
	std::string line;
	bool bad_header = false;

	std::ifstream ifs(archive);
	if (ifs.fail())
		throw std::runtime_error("critical error in data.csv.");
	if (ifs.peek() == EOF){
		ifs.close();
		throw std::runtime_error("Error: empty file.");
	}
	std::getline(ifs, line);
	if (key == 'd')
	{
		if (line != "date,exchange_rate")
			bad_header = true;
	}
	else
	{
		if (line != "date | value")
			bad_header = true;
	}
	ifs.close();
	if (bad_header)
		throw std::runtime_error("Invalid format header.");
}

// inicializa o banco de dados e salva na no conteiner map

void	BitcoinExchange::_initDataFile(){
	std::ifstream	ifs;
	std::string		date, value, line;
	size_t pos;
	float rate;

	checkOpen(this->_dataFile.c_str(), 'd');
	ifs.open(this->_dataFile.c_str());
	std::getline(ifs, line); //pega a header e ignora
	while (std::getline(ifs, line)){
		pos = line.find(',');
		
		date = line.substr(0, pos); // recorta a string com a data
		value = line.substr(pos + 1); // recorta a string com valor
		rate = atof(value.c_str()); //converte a string valor para float
		_dataBase[date] = rate; // insere a nova cotação no mapa
    }
	ifs.close();
}

// abre o input e faz um loop calculando as linhas em valor

void	BitcoinExchange::_initInputFile(){
	std::ifstream	ifs;
	std::string		line, date, value;

	checkOpen(this->_inputFile.c_str(), 'i');
	ifs.open(this->_inputFile.c_str());
	std::getline(ifs, line); //pega a header e ignora
	while (std::getline(ifs, line))
	{
		//verifica a integridade da linha do input
		if (line.find("|") == std::string::npos || line.empty())
			std::cout << "Error: bad input => " << line << std::endl;
		else
		{
			size_t pos = line.find('|'); // acha o delimitador
			date = line.substr(0, pos); //recorta a string data
			value = line.substr(pos + 1); //recorta string quantidade
			float rate = atof(value.c_str()); // converte quant em float
			_calcBitcoin(date, rate); // calcula o valor do bitcoin
		}
	}
}

//faz a checagem e imprime a linha com o resultado do valor dos bitcoins

void	BitcoinExchange::_calcBitcoin(std::string date, float value){
	if (!checkDate(date)){
		std::cout << "Error: Invalid date." << std::endl;
		return ;
	}
	if (value < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (value > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else {
		float result = _calcValue(date, value);
		std::cout << date << "=> " << value << " = " << result << std::endl;
	}
}

// faz o calculo do valor cruzando os dados do Banco e da linha do input

float	BitcoinExchange::_calcValue(std::string date, float value)
{
	int date_input = 0;
	int	date_it = 0;
	int date_next = 0;
	std::map<std::string, float>::iterator	it; // cria um iterador do map

	it = _dataBase.find(date); // procura no banco se existe uma data identica
	
	if (it != _dataBase.end()) // se existir já resolve o valor
		return (it->second * value);

	date_input = dateToInt(date);
	for (it = _dataBase.begin(); it != _dataBase.end(); it++) //itera o mapa em busca da data mais proxima
	{
		//	cria um iterador para um elemento a frente
		std::map<std::string, float>::iterator	next = it;
		next++;
	
		//converte a data em string para int a fim de viabilizar a comparação
		date_it = dateToInt(it->first);
		if (next != _dataBase.end())
			date_next = dateToInt(next->first);
		else
			date_next = 0;
		
		/*	verifica dois cenarios diferentes

			cenario 1:	se a data do input for maior ou igual 
						ao elemento do banco e esse elemento
						for o ultimo

			cenario 2:	se a data do input for maior ou igual 
						a data o elemento do banco atual e menor
						que a data do proximo elemento do banco

			caso for algum dos dois, resolve e retorna o valor 
		*/

		if (((date_input >= date_it) && (next == _dataBase.end()))
				|| ((date_input >= date_it) && (date_input < date_next)))
			{
				std::cout << "data usado: " << date << std::endl;
				std::cout << "data value: " << it->second << std::endl;
				std::cout << "quantidade: " << value << std::endl;
				return (it->second * value);
			}
	}
	return (0);
}

//data checkers and converter

bool leapYearCheck(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 != 0)
			return (true);
	}
	else if (year % 400 == 0)
		return (true);
	return (false);
}

bool checkDay(date_t date)
{
	bool leap_year = leapYearCheck(date.year);

	if (date.day < 1 || date.day > 31)
		return (false);
	if ((date.month == 4) || (date.month == 6) || (date.month == 9) || (date.month == 11))
	{
		if (date.day > 30)
			return (false);
	}
	else if (date.month == 2)
	{
		if (leap_year)
		{
			if (date.day > 29)
				return (false);
		}
		else 
		{
			if (date.day > 28)
				return (false);
		}
	}
	return (true);
}

int	dateToInt(std::string date)
{
	date_t	result;
	char	aux;

	result.year = -1;
	result.month = -1;
	result.day = -1;

	if (date.length() != 11)
		return (-1);

	std::stringstream ss(date);
	ss >> result.year >> aux >> result.month >> aux >> result.day;

	return ((result.year * 10000) + (result.month * 100) + result.day);
}

date_t	convertDate(std::string date)
{
	date_t	result;
	char	aux;

	result.year = -1;
	result.month = -1;
	result.day = -1;

	if (date.length() != 11)
		return (result);

	std::stringstream ss(date);
	ss >> result.year >> aux >> result.month >> aux >> result.day;

	return (result);
}

bool checkDate(std::string rawDate)
{
	date_t date = convertDate(rawDate);
	
	if (date.year == 2009 && date.month == 1 && date.day == 1)
		return (false);
	if (date.year < 2009 || date.year > 2023)
		return (false);
	if (date.month < 1 || date.month > 12)
		return (false);
	if (!checkDay(date))
		return (false);
	return (true);
}
