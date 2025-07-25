#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe nb;
	if(ac == 1)
	{
		std::cerr << "There should be at least one argument" << std::endl;
		return 1;
	}
	try
	{
		nb.checkNb(av);
		nb.sort_fn_vec();
		nb.sort_fn_deq();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}