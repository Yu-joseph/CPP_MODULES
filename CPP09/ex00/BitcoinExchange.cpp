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

// void BitcoinExchange::input_file(std::string inpt)
// {
// 	std::fstream file(inpt.c_str());
// 	if (!file.is_open())
// 	{
// 		throw std::runtime_error("err opening the file");
// 	}
// 	std::string line;
// 	while (std::getline(file, line))
// 	{
// 		std::stringstream ss(line);
// 		std::string pars;
// 		std::string amount;
// 		if (std::getline(ss, pars, '|') && std::getline(ss, amount))
// 		{
// 			if (!parse_date(pars))
// 			{
// 				std::cerr << "Error: bad input => " << pars << std::endl;
// 				continue;
// 			}
// 			std::string errtype = parse_amount(amount);
// 			if (errtype != "true")
// 			{
// 				std::cerr << errtype << " " << amount << std::endl;
// 				continue;
// 			}
// 		}
// 	}
	
// }


void BitcoinExchange::input_file(std::string inpt)
{
	std::fstream file(inpt.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date, amountStr;

		if (std::getline(ss, date, '|') && std::getline(ss, amountStr))
		{
			if (!parse_date(date))
			{
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}

			std::string result = parse_amount(amountStr);
			if (result != "true")
			{
				std::cerr << result << " => " << amountStr << std::endl;
				continue;
			}

			size_t start = amountStr.find_first_not_of(" \t\r\n");
			size_t end = amountStr.find_last_not_of(" \t\r\n");
			amountStr = amountStr.substr(start, end - start + 1);
			std::stringstream conv(amountStr);
			float amount = 0;
			conv >> amount;

			std::map<std::string, float>::const_iterator it = this->btc.lower_bound(date);
			if (it == btc.end() || it->first != date)
			{
				if (it == btc.begin())
				{
					std::cerr << "Error: no earlier date found for => " << date << std::endl;
					continue;
				}
				--it;
			}

			float price = it->second;
			std::cout << date << " => " << amount << " = " << amount * price << std::endl;
		}
		else if (!line.empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
}


std::string BitcoinExchange::parse_amount(std::string amount)
{
    size_t start = amount.find_first_not_of(" \t\r\n");
    size_t end = amount.find_last_not_of(" \t\r\n");
    if (start == std::string::npos || end == std::string::npos)
        return "Error: invalid input";
    amount = amount.substr(start, end - start + 1);

    std::stringstream ss(amount);
    float value;
    char extra;

    if (!(ss >> value) || (ss >> extra)) {
        return "Error: not a valid number";
    }

    if (value < 0)
        return "Error: not a positive number";
    if (value > 1000)
        return "Error: too large a number";

    return "true";
}




bool BitcoinExchange::parse_date(std::string data)
{
    size_t start = data.find_first_not_of(" \t\r\n");
    size_t end = data.find_last_not_of(" \t\r\n");
    if (start == std::string::npos || end == std::string::npos)
        return false;
    data = data.substr(start, end - start + 1);


    if (data.length() != 10 || data[4] != '-' || data[7] != '-')
        return false;

    std::string yearStr = data.substr(0, 4);
    std::string monthStr = data.substr(5, 2);
    std::string dayStr = data.substr(8, 2);


    int year = 0, month = 0, day = 0;
    std::stringstream ys(yearStr), ms(monthStr), ds(dayStr);

    if (!(ys >> year) || year < 0)
        return false;
    if (!(ms >> month) || month < 1 || month > 12)
        return false;
    if (!(ds >> day) || day < 1)
        return false;

    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31 };

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}











// bool BitcoinExchange::parse_date(std::string data)
// {
// 	size_t start = data.find_first_not_of(" \t\r\n");
//     size_t end = data.find_last_not_of(" \t\r\n");
// 	data = data.substr(start, end - start + 1);
//     if (data.length() != 10 || data[4] != '-' || data[7] != '-')
//         return false;

//     std::string year = data.substr(0, 4);
//     std::stringstream yr(year);
//     std::string month = data.substr(5,2);
// 	std::string dayStr = data.substr(8, 2);
// 	// std::cout << month << std::endl;
//     std::stringstream dy(dayStr);
//     std::stringstream mn(month);
// 	int months = 0;
// 	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     int y = 0;
// 	int day = 0;
//     if (year.size() != 4 || !(yr >> y) || y < 0)
//         return false;
// 	if (!(mn >> months) ||(day > daysInMonth[months-1]) || day < 0)
// 		return false;
// 	if (condition)
// 	{
// 		/* code */
// 	}
	
//     return true;
// }
// 0123-56-78
// std::string BitcoinExchange::trim(const std::string& str) 
// {
//     size_t start = str.find_first_not_of(" \t\r\n");
//     size_t end = str.find_last_not_of(" \t\r\n");

//     if (start == std::string::npos)
//         return "";

    
// }


BitcoinExchange::~BitcoinExchange(){}