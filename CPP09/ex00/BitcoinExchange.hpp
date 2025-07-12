#pragma once

#include <iostream>
#include <map>

class BitcoinExchange
{
private:
	// std::ifstream file_;
	std::map<std::string, float> btc;
public:
	BitcoinExchange();
	void	check_file(std::string arg);
	~BitcoinExchange();
};

