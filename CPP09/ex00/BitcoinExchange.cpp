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
		std::string amount;
		if (std::getline(ss, pars, '|') && std::getline(ss, amount))
		{
			if (!parse_date(pars))
			{
				std::cerr << "Error: bad input => " << pars << std::endl;
				continue;
			}
			std::string errtype = parse_amount(amount);
			if (errtype != "true")
			{
				std::cerr << errtype << " " << amount << std::endl;
				continue;
			}
			
		}
	}
	
}

std::string BitcoinExchange::parse_amount(std::string amount)
{

}

bool BitcoinExchange::parse_date(std::string data)
{
	if (data.size() != 10)
		return false;
	
	std::stringstream date(data);
	std::string year;
	if (std::getline(date, year, '-'))
	{
		
	}
	return true;
}

BitcoinExchange::~BitcoinExchange(){}