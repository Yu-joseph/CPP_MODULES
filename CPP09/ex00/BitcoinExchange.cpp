#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

void BitcoinExchange::check_file()
{
	std::fstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("error opening the file");
	
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string data;
		float price;
		if (std::getline(ss, data, ',') && (ss >> price))
		{
			this->btc[data] = price;
		}
	}
	// for (std::map<std::string, float>::iterator it = btc.begin(); it != btc.end(); ++it) {
    //     std::cout << it->first << " => $" << it->second << std::endl;
    // }
	
}

void BitcoinExchange::input_file(std::string inpt)
{
	std::fstream file(inpt.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("err opening the file");
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string pars;
		if (std::)
		{
			
		}
		
	}
	
}



BitcoinExchange::~BitcoinExchange(){}