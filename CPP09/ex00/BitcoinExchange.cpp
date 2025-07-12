#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

void BitcoinExchange::check_file(std::string arg)
{
	std::ifstream file(arg);
	std::string line;
	while (std::getline(file, line))
	{
		
	}
	
}



BitcoinExchange::~BitcoinExchange(){}