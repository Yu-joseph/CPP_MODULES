#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
class BitcoinExchange
{
private:
	// std::ifstream file_;
	std::map<std::string, float> btc;
public:
	BitcoinExchange();
	void	check_file();
	void input_file(std::string inpt);
	// void parse_year(int y);
	bool parse_date(std::string date);
	std::string parse_amount(std::string amount);
	~BitcoinExchange();
};

