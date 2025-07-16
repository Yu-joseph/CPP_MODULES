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
	(void)amount;
	return "true";
}
bool BitcoinExchange::parse_date(std::string data)
{
	size_t start = data.find_first_not_of(" \t\r\n");
    size_t end = data.find_last_not_of(" \t\r\n");
	data = data.substr(start, end - start + 1);
    if (data.length() != 10 || data[4] != '-' || data[7] != '-')
        return false;

    std::string year = data.substr(0, 4);
    std::stringstream yr(year);
    std::string month = data.substr(6,8);
	std::cout << month << std::endl;
    std::stringstream mn(month);
    int y = 0;
    if (year.size() != 4 || !(yr >> y))
        return false;

    return true;
}
// 0123-56-78
// std::string BitcoinExchange::trim(const std::string& str) 
// {
//     size_t start = str.find_first_not_of(" \t\r\n");
//     size_t end = str.find_last_not_of(" \t\r\n");

//     if (start == std::string::npos)
//         return "";

    
// }


BitcoinExchange::~BitcoinExchange(){}