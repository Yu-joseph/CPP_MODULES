#include "RPN.hpp"

int main(int ac, char **av)
{
	RPN a;
	if (ac != 2)
	{
		std::cerr << "Should be two args" << std::endl;
		return 1;
	}
	try
	{
		a.parse_arg(std::string(av[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	return 0;
}