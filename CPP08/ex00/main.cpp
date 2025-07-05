#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> ls;	
	ls.push_back(12);
	ls.push_back(-11);
	ls.push_back(88);
	ls.push_back(7);
	try
	{
		std::vector<int>::iterator it = easyfind(ls, 88);
		std::cout << *it << std::endl;
		it++;
		std::cout << *it << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}