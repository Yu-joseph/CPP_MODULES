#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cerr << "error args" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange bitcoin;
		bitcoin.check_file();
		bitcoin.input_file(std::string(av[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}