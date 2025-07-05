#include "ScalarConverter.hpp"
#include <iostream>
int main( int ac, char **av)
{
	if ( ac == 2)
	{
		std::string str = av[1]; 
		ScalarConverter::convert(str);
	}
	else{
		std::cout << "'Invalid input'" << std::endl;
		return 1;
	}
	return 0;
}